#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include "Fje.h"
using namespace std;




class Tree {

	struct node {
		char Matrica[5][5];
		int Ocena;
		char crtaj;
	};

	
	int duz=0;
	int m = 5;

	

public:

	node *Niz;

	Tree(char Mat[5][5], int Ocena_, char crtaj_) {
		Niz = new node[40000000];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) Niz[0].Matrica[i][j] = Mat[i][j];
		}
		Niz[0].Ocena = Ocena_;
		Niz[0].crtaj = crtaj_;
		duz = 1;
	}

	~Tree() { delete Niz; }

	int Duzina() const { return duz; }

	Tree& Dodaj(Elem G) {
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < 5; k++) Niz[duz].Matrica[i][k] = G.Matrica[i][k];
		}
		Niz[duz].Ocena = G.Ocena;
		Niz[duz].crtaj = G.crtaj;
		duz++;
		return *this;
	}
	


};

#endif