#include <iostream>
#include "Tree.h"
#include <string>
using namespace std;

int main() {

	int m, broj;
	cout << "Unesite red stabla (m): " << endl;
	cin >> m;
	Tree T(m);
	string str;

	while (true) {

		int izbor; 

		cout << "Izaberite opciju:" << endl;
		cout << "1. Dodavanje elemnta u stablo" << endl;
		cout << "2. Dohvatanje roditelja datog cvora" << endl;
		cout << "3. Odredjivanje sirine stabla" << endl;
		cout << "4. Ispis po 'level order' algoritmu" << endl;
		cout << "5. Ispis stabla" << endl;
		cout << "6. KRAJ" << endl;

		cin >> izbor;

		switch (izbor) {

		case 1: cout << "Unesite celi broj koji zelite da dodate u stablo, za prekid unesite 'end':" << endl;
			
			while (str != "end") {
				cin >> str;
				if (str != "end")
				{
					broj = stoi(str);
					T += broj;
				}
			}
				break;
		case 2: cout << "Unesite cvor za koji se trazi roditelj" << endl;
			int br;
			cin >> br;
			cout << "Roditelj je:" << T.Roditelj(br) << endl; break;
		case 3: cout << "Sirina stabla je: " << T.Sirina() << endl; break;
		case 4: cout << "Level order: ";
			T.LevelOrder(); break;
		case 5: T.pisi(); break;
		case 6: exit(1);


		}



	}
	system("pause");
	return 0;
}