#include <iostream>
#include <string>
#include <time.h>
#include "Tree.h"
#include "Fje.h"

using namespace std;


int main() {


	char boja = PrviIgra();
	char pboja = PromeniBoju(boja);
	
	cout << "Prvi potez igra: ";
	cout << boja << endl;
	
	char  Matrica[5][5];

	cout << "Unesite pocetno stanje:" << endl;
	Unos(Matrica);

	Tree T(Matrica,0,pboja);

	int izbor;

	while (true) {
		cout << "Izaberite opciju:" << endl;
		cout << "1. Formiranje stabla igre" << endl;
		cout << "2. Ispis stabla igre" << endl;
		cout << "3. Brisanje stabla" << endl;
		cout << "4. KRAJ" << endl;

		cin >> izbor;

		int ubaci = 1;
		int cnt = 0;
		int brojac = 0;
		Elem E;

		if (izbor == 1) {

			for (int k = 0; k < brojac * 5 + 1; k++) {

				if (T.Niz[cnt].Ocena == 0) {

					for (int j = 0; j < 5; j++) {

						E = DodajKuglicu(j, T.Niz[cnt].Matrica, PromeniBoju(T.Niz[cnt].crtaj));
						if (E.Ocena == 1 && pboja == boja) T.Niz[cnt].Ocena = 1;
						else if (E.Ocena == 1 && pboja != boja) T.Niz[cnt].Ocena = (-1);
						T.Dodaj(E);
						brojac++;
					}


				}

				cnt++;
			}
		}


		if (izbor == 2) {
			int m = 0;

			for (int i = 0; i < T.Duzina(); i++) {
				for (int k = 0; k < 5; k++) {
					for (int j = 0; j < 5; j++) {
						if (T.Niz[i].Ocena != -2) {
							cout << T.Niz[i].Matrica[k][j] << ' ';
							if (j == 4) cout << endl;
						}
					}
				}

				if (T.Niz[i].Ocena != -2) {
					m++;
					cout << T.Niz[i].Ocena << endl;;
				}
			}

			cout << "Ukupno covorva: ";
			cout << m << endl;

		}

		if (izbor == 3) delete[] T.Niz;
		if (izbor == 4) exit(1);

	}

	system("pause");
	return 0;

}