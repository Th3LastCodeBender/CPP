#include "eader.h"

/**
 * @brief Esegue l'ordinamento Ford-Johnson (merge-insertion) su un deque.
 *
 * @param deq Deque da ordinare in ordine crescente.
 */
void dequeAlgorithm(std::deque<int> &deq)
{
    if (deq.size() <= 1)
		return;

	CoupVec	pairs;
	bool	has_straggler = (deq.size() % 2 != 0);
	int		straggler = 0;

	check_for_struggler(has_straggler, straggler, deq);
	create_pairs(pairs, deq);
	if (pairs.empty())
	{
		handle_straggler(has_straggler, straggler, deq);
		return ;
	}
	std::deque<int> max_chain = deque_create_max_chain(pairs);
	dequeAlgorithm(max_chain);
	pairs = reorder_pairs_by_max(max_chain, pairs);
	deq = max_chain;
	std::vector<size_t> max_positions(pairs.size());
	for (size_t i = 0; i < pairs.size(); ++i)
		max_positions[i] = i;
	binary_insert_before_bound(deq, pairs[0].first, max_positions[0], max_positions);
	std::vector<size_t> order = jacob_insertion_order(pairs.size());
	for (size_t k = 0; k < order.size(); ++k)
		binary_insert_before_bound(deq, pairs[order[k]].first, max_positions[order[k]], max_positions);
	handle_straggler(has_straggler, straggler, deq);
}

/**
 * @brief Riordina le coppie per allinearle all'ordine dei loro massimi ordinati.
 *
 * @param sorted_max Lista ordinata dei massimi.
 * @param pairs Coppie originali (min, max).
 * @return CoupVec Coppie allineate all'ordine di sorted_max.
 */
CoupVec	reorder_pairs_by_max(const std::deque<int> &sorted_max, const CoupVec &pairs)
{
	CoupVec				ordered;
	std::vector<char>	used(pairs.size(), false);

	ordered.reserve(pairs.size());
	for (size_t m = 0; m < sorted_max.size(); ++m)
	{
		int	target = sorted_max[m];
		for (size_t i = 0; i < pairs.size(); ++i)
		{
			if (used[i] == false && pairs[i].second == target)
			{
				ordered.push_back(pairs[i]);
				used[i] = true;
				break;
			}
		}
	}
	return (ordered);
}

/**
 * @brief Inserisce value in deq con ricerca binaria nell'intervallo [0, bound).
 *
 * Aggiorna anche max_positions dopo l'inserimento per mantenere coerenti i bound.
 *
 * @param deq Deque ordinato dei massimi e dei minimi gia' inseriti.
 * @param value Valore minimo da inserire.
 * @param bound Limite superiore esclusivo dell'intervallo di inserimento.
 * @param max_positions Posizioni correnti dei massimi in vec.
 */
void	binary_insert_before_bound(std::deque<int> &deq, int value, size_t bound, std::vector<size_t> &max_positions)
{
	std::deque<int>::iterator it = std::lower_bound(deq.begin(),
			deq.begin() + bound, value);
	size_t	insert_pos = static_cast<size_t>(it - deq.begin());

	deq.insert(it, value);
	for (size_t i = 0; i < max_positions.size(); ++i)
	{
		if (max_positions[i] >= insert_pos)
			max_positions[i]++;
	}
}

/**
 * @brief Crea le coppie (min, max) dal deque in input.
 *
 * Assume che vec abbia dimensione pari (straggler gia' rimosso).
 *
 * @param pairs Vector di output delle coppie.
 * @param deq Deque di input.
 */
void	create_pairs(CoupVec &pairs, const std::deque<int> &deq)
{
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int a = deq[i];
		int b = deq[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
}

/**
 * @brief Rimuove l'ultimo elemento quando la dimensione e' dispari e lo restituisce come straggler.
 *
 * @param has_straggler True se la dimensione in input era dispari.
 * @param straggler Valore di output per l'elemento rimosso.
 * @param deq Deque di input (l'ultimo elemento puo' essere rimosso).
 */
void	check_for_struggler(bool has_straggler, int &straggler, std::deque<int> &deq)
{
	if (has_straggler)
	{
		straggler = deq.back();
		deq.pop_back();
	}
}

/**
 * @brief Estrae la catena dei massimi dalle coppie.
 *
 * @param pairs Coppie in input (min, max).
 * @return std::deque<int> Deque contenente solo i massimi.
 */
std::deque<int>	deque_create_max_chain(const CoupVec pairs)
{
	std::deque<int> max_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		max_chain.push_back(pairs[i].second);
	return (max_chain);
}

/**
 * @brief Inserisce lo straggler nel deque ordinato.
 *
 * Usa la ricerca binaria su tutto il deque.
 *
 * @param has_straggler True se esiste uno straggler.
 * @param straggler Valore da inserire.
 * @param deq Deque ordinato in cui inserire il valore.
 */
void	handle_straggler(bool has_straggler, int straggler, std::deque<int> &deq)
{
	if (has_straggler)
	{
		std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), straggler);
		deq.insert(it, straggler);
	}
}
