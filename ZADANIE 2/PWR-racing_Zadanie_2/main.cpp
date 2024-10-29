#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Point {		//stworzenie struktury punktu o współrzędnych x, y
	float x, y;
};

// Funkcja zwracająca orientację trójkąta (p, q, r)
// 0 -> punkty są współliniowe
// 1 -> zgodnie z ruchem wskazówek zegara
// 2 -> przeciwnie do ruchu wskazówek zegara
int orientation(Point p, Point q, Point r) {
	float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0;       // współliniowe
	if (val > 0) return 1;		  // zgodnie z ruchem wskazówek zegara
	if (val < 0) return 2;	      // przeciwnie z ruchem wskazówek zegara
}

// Funkcja znajdująca otoczkę wypukłą dla zbioru punktów
void convexHull(const vector<Point>& points) {
	int n = points.size();
	if (n < 3) {	// Nie można utworzyć wielokątu bez conajmnniej 3 punktów

		cout << "Potrzeba przynajmniej 3 punktow" << endl;
		return;
	}

	vector<Point> hull;       // Wektor do przechowywania otoczki wypukłej

	// Znajdź punkt najbardziej na lewo
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	int p = l, q;
	do {
		hull.push_back(points[p]); // Dodaj obecny punkt do otoczki

		// Znajdź najbardziej przeciwny do ruchu wskazówek zegara punkt q względem p
		q = (p + 1) % n;
		for (int i = 0; i < n; i++) {
			if (orientation(points[p], points[i], points[q]) == 2)
				q = i;
		}

		p = q; // Ustaw p na q, aby kontynuować dodawanie do otoczki

	} while (p != l); // Powtórz aż wrócisz do początku

	// Wyświetl wynik
	for (const auto& pt : hull)
		cout << "(" << pt.x << ", " << pt.y << ")\n";
}

int main() {
	ifstream file("dane.txt"); //importowanie pliku
	if (!file) {
		cerr << "Nie mozna otworzyc pliku!" << endl; //brak pliku w wyznaczonej scieżce
		return 1;
	}

	int n;
	file >> n; // Wczytaj liczbę punktów

	vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		file >> points[i].x >> points[i].y; // Wczytaj współrzędne punktu
	}
	file.close();

	convexHull(points);
	return 0;
}
