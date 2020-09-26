#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include<cmath>

using namespace std;

class Tree {

	int info;
	int m;
	int duz;


	int* Niz;

	void kopiraj(Tree& T) {
		
		Niz = new int[duz = T.duzina()];
		for (int i = 0; i < T.duzina(); i++) {
			Niz[i]= T.Niz[i];
		}
	}

	void premesti(Tree& T) {
		
		Niz = new int[T.duzina()];
		Niz = T.Niz;
		T.Niz = nullptr;
		duz = T.duzina();
	}

	void brisi() {
		Niz = nullptr;
	}

public:

	Tree(int m_) : Niz(nullptr), duz(0), m(m_) {} // stvaranje praznog stabla

	Tree(Tree& T) { kopiraj(T); } //konstruktor kopije

	Tree& operator=(Tree& T){	//kopirajuci operator dodele
		brisi();
		kopiraj(T);
	}

	Tree(Tree&& T) { premesti(T); } // premestajuci konstruktor

	Tree& operator=(Tree&& T) {		//premestajuci operator dodele
		brisi();
		premesti(T);
	}

	int duzina() const { return duz; } // BROJ CVOROVA U STABLU

	Tree &operator +=(int broj) {      //dodavanje novog cvora

		if (Niz == nullptr) {
			Niz = new int[1];
			Niz[duz] = broj;
			duz++;
		}
		else {
			int *temp;
			temp = new int[duz + 1];
			for (int i = 0; i < duz; i++) {
				temp[i] = Niz[i];
			}
			Niz = temp;
			Niz[duz] = broj;
			duz++;
		}

		return *this;

	}

	int Roditelj(int broj) {      // Pokazivac na roditelja
		for (int i = 0; i < duz; i++) {
			if (Niz[i] == broj) return Niz[(i-1)/m];
		}
	}

	void pisi() {
		int cnt = 0;
		for (int i = 0; i < duz/m; i++) {
			cout << Niz[i] << " ( ";
			for (int j = 0; j < m; j++) {
				if (cnt == duz - 1) {
					cout << ")" << endl;
					break;
				}
				if (cnt < duz) {
					cout << Niz[m*(i)+1 + j];
					cnt++;
				}
				if (j < m - 1) cout << ", ";
				else cout << " )" << endl;
			}
		}
	}

	void LevelOrder() {
		for (int i = 0; i < duz; i++) {
			cout << Niz[i];
			if (i < duz - 1) cout << ",";
		}
		cout << endl;
	}

	int Sirina() {
		int suma = 0;
		int i = 0;
		int broj=0;
		while (true) {
			broj = pow(m, i);
			if (suma+broj >= duz) break;
			suma = suma + broj;
			i++;
		}
		int zadnji = duz - suma;
		if (zadnji >= pow(m, i - 1)) return zadnji;
		else return pow(m, i - 1);


	}

};



#endif