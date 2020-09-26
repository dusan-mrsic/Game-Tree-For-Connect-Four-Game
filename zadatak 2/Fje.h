#ifndef _FUNKCIJE_H_
#define _FUNKCIJE_H_

struct Elem {
	char Matrica[5][5];
	int Ocena;
	char crtaj;
};

void Unos(char Matrica[5][5]);

void Ispis(char Matrica[5][5]);

char PrviIgra();

int OcenaStanja(char mat[5][5], int i, int j);

Elem DodajKuglicu(int j, char mat[5][5], char boja);

char PromeniBoju(char boja);


#endif