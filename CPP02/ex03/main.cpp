/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:25:38 by lparolis          #+#    #+#             */
/*   Updated: 2025/10/30 16:45:04 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void test(const Point& a, const Point& b, const Point& c, const Point& p, std::string label)
 {
    std::cout << label << " → " 
              << (Point::bsp(a, b, c, p) ? "✅ Dentro\n" : "❌ Fuori\n");
}

int main() {
    std::cout << std::boolalpha;

    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    std::cout << "=== TRIANGOLO BASE ===\n";
    test(a, b, c, Point(3.0f, 3.0f), "1. Punto chiaramente dentro");
    test(a, b, c, Point(5.0f, 0.0f), "2. Punto sul bordo (AB)");
    test(a, b, c, Point(0.0f, 5.0f), "3. Punto sul bordo (AC)");
    test(a, b, c, Point(10.0f, 10.0f), "4. Punto fuori in diagonale");
    test(a, b, c, Point(0.1f, 0.1f), "5. Punto quasi sull’angolo (precisione)");
    test(a, b, c, Point(4.9999f, 0.0001f), "6. Punto infinitesimale sopra AB");

    std::cout << "\n=== TRIANGOLO INCLINATO ===\n";
    Point d(-5.0f, -2.0f);
    Point e(2.0f, 4.0f);
    Point f(6.0f, -3.0f);

    test(d, e, f, Point(1.0f, 0.0f), "7. Dentro triangolo inclinato");
    test(d, e, f, Point(2.0f, 4.0f), "8. Esattamente su un vertice");
    test(d, e, f, Point(5.0f, -2.0f), "9. Sul bordo inferiore");
    test(d, e, f, Point(10.0f, 10.0f), "10. Lontanissimo fuori");

    std::cout << "\n=== TRIANGOLO CON COORDINATE NEGATIVE ===\n";
    Point g(-10.0f, -10.0f);
    Point h(-5.0f, -2.0f);
    Point i(-2.0f, -8.0f);

    test(g, h, i, Point(-6.0f, -6.0f), "11. Dentro");
    test(g, h, i, Point(-9.9f, -9.9f), "12. Quasi sull’angolo");
    test(g, h, i, Point(-4.0f, -8.0f), "13. Vicino al bordo");
    test(g, h, i, Point(0.0f, 0.0f), "14. Lontano fuori");

    std::cout << "\n=== TRIANGOLO MINUSCOLO (PRECISIONE FIXED) ===\n";
    Point j(0.0f, 0.0f);
    Point k(0.01f, 0.0f);
    Point l(0.0f, 0.01f);

    test(j, k, l, Point(0.005f, 0.002f), "15. Dentro un triangolo microscopico");
    test(j, k, l, Point(0.02f, 0.02f), "16. Fuori microscopico");
    test(j, k, l, Point(0.005f, 0.005f), "17. Quasi sulla diagonale");

    std::cout << "\n=== TRIANGOLO DEGENERATO (PUNTI ALLINEATI) ===\n";
    Point m(0.0f, 0.0f);
    Point n(5.0f, 5.0f);
    Point o(10.0f, 10.0f);

    test(m, n, o, Point(3.0f, 3.0f), "18. Punti collineari");
    test(m, n, o, Point(6.0f, 7.0f), "19. Fuori ma vicino alla linea");

    std::cout << "\n=== TRIANGOLO ROVESCIATO ===\n";
    Point p1(0.0f, 0.0f);
    Point p2(10.0f, 0.0f);
    Point p3(5.0f, -5.0f);

    test(p1, p2, p3, Point(5.0f, -2.0f), "20. Dentro triangolo rovesciato");
    test(p1, p2, p3, Point(5.0f, 0.0f), "21. Esattamente sul bordo superiore");
    test(p1, p2, p3, Point(5.0f, 2.0f), "22. Sopra il triangolo (fuori)");

    return 0;
}