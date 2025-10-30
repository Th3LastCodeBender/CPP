#!/bin/bash
set -euo pipefail

ROOT="/home/lparolis/Desktop/gitspace/CommonCore/Milestone_04/CPP"

find "$ROOT" -type f \( -name '*.h' -o -name '*.hpp' \) | while IFS= read -r f; do
  if grep -q '^[[:space:]]*#ifndef' "$f"; then
    printf "skip: %s (already has guard)\n" "$f"
    continue
  fi

  base=$(basename "$f")
  name=$(echo "$base" | tr '[:lower:]' '[:upper:]' | sed 's/[^A-Z0-9]/_/g')
  guard="${name}_"

  # se il file inizia con un commento (header 42), inserisci il guard dopo la prima "*/"
  if head -n1 "$f" | grep -q '^\/\*'; then
    end_line=$(awk '/\*\// {print NR; exit}' "$f" || true)
    if [ -n "$end_line" ]; then
      tmp="$(mktemp)"
      head -n "$end_line" "$f" > "$tmp"
      printf "\n#ifndef %s\n#define %s\n\n" "$guard" "$guard" >> "$tmp"
      tail -n +"$((end_line + 1))" "$f" >> "$tmp"
      printf "\n#endif /* %s */\n" "$guard" >> "$tmp"
      mv "$tmp" "$f"
      printf "added guard to: %s -> %s (after header)\n" "$f" "$guard"
      continue
    fi
  fi

  # fallback: aggiungi il guard all'inizio del file
  tmp="$(mktemp)"
  printf "#ifndef %s\n#define %s\n\n" "$guard" "$guard" > "$tmp"
  cat "$f" >> "$tmp"
  printf "\n#endif /* %s */\n" "$guard" >> "$tmp"
  mv "$tmp" "$f"
  printf "added guard to: %s -> %s\n" "$f" "$guard"
done