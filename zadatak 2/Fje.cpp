#include <iostream>
#include <time.h>
#include "Fje.h"

using namespace std;

void Unos(char Matrica[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> Matrica[i][j];

		}
	}
}

void Ispis(char Matrica[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << Matrica[i][j] << ' ';
			if (j == 4) cout << endl;
		}
	}
	cout << endl;
}

char PrviIgra() {
	int boja;
	srand(time(NULL));
	boja = rand() % 2;
	if (boja == 0) return 'c';
	else return 'p';
}

int OcenaStanja(char mat[5][5], int i, int j) {
	if (i > 1) {
		if ((mat[i][j] == mat[i - 1][j]) && (mat[i][j] == mat[i - 2][j])) return 1;
	}
	if (i < 3) {
		if ((mat[i][j] == mat[i + 1][j]) && (mat[i][j] == mat[i + 2][j])) return 1;
	}
	if ((i < 4) && (i > 0)) {
		if ((mat[i][j] == mat[i + 1][j]) && (mat[i][j] == mat[i - 1][j])) return 1;
	}
	if (j > 1) {
		if ((mat[i][j] == mat[i][j - 1]) && (mat[i][j] == mat[i][j - 2])) return 1;
	}
	if (j < 3) {
		if ((mat[i][j] == mat[i][j + 1]) && (mat[i][j] == mat[i][j + 2])) return 1;
	}
	if ((j < 4) && (j > 0)) {
		if ((mat[i][j] == mat[i][j + 1]) && (mat[i][j] == mat[i][j - 1])) return 1;
	}
	if ((i < 3) && (j < 3)) {
		if ((mat[i][j] == mat[i + 1][j + 1]) && (mat[i][j] == mat[i + 2][j + 2])) return 1;
	}
	if ((i > 1) && (j > 1)) {
		if ((mat[i][j] == mat[i - 1][j - 1]) && (mat[i][j] == mat[i - 2][j - 2])) return 1;
	}
	if ((i < 3) && (j > 1)) {
		if ((mat[i][j] == mat[i + 1][j - 1]) && (mat[i][j] == mat[i + 2][j - 2])) return 1;
	}
	if ((i > 1) && (j < 3)) {
		if ((mat[i][j] == mat[i - 1][j + 1]) && (mat[i][j] == mat[i - 2][j + 2])) return 1;
	}
	if ((i > 0) && (j > 0)) {
		if ((mat[i][j] == mat[i - 1][j - 1]) && (mat[i][j] == mat[i + 1][j + 1])) return 1;
		if ((mat[i][j] == mat[i - 1][j + 1]) && (mat[i][j] == mat[i + 1][j - 1])) return 1;
	}
	return 0;


}





Elem DodajKuglicu(int j, char mat[5][5], char boja) {


	for (int i = 0; i < 5; i++) {
		Elem B;
		if (i == 0 && mat[i][j] != 'x') {
			B.Ocena = -2;
			return B;
		}
		if (mat[i + 1][j] != 'x') {

			for (int i = 0; i < 5; i++) {
				for (int k = 0; k < 5; k++) B.Matrica[i][k] = mat[i][k];
			}
			B.Matrica[i][j] = boja;
			B.Ocena = OcenaStanja(B.Matrica, i, j);
			B.crtaj = boja;
			return B;
		}
	}
}



char PromeniBoju(char boja) {
	if (boja == 'c') boja = 'p';
	else boja = 'c';
	return boja;
}