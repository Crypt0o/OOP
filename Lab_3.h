#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 3
	@author: Ciubuc Mihai-Marian
*/


/*
	Să se realizeze un program ce foloseşte o clasă film cu următorii membrii: nume, actor principal, actor secundar, o metodă pentru iniţializare a datelor, o metodă care prezintă numele filmului şi actorii principali şi secundari. Programul va crea trei obiecte aparţinãnd clasei film, le va iniţializa şi va afişa titlurile filmelor şi numele actorilor. 
*/

class l3_e2 {
public:

	class film {
		string nume, actor_princ, actor_sec;

	public:
		film() {
			nume = actor_princ = actor_sec = "";
			init();
	
		}

		film(string NumeFilm, string ActorPrincipal, string ActorSecundar) {
			nume = NumeFilm, actor_princ = ActorPrincipal, actor_sec = ActorSecundar;
		}

		void init() {
			cout << "\nCare este numele filmului? ";
			cin >> nume;

			cout << "Actorul principal: ";
			cin >> actor_princ;

			cout << "Actor secundar: ";
			cin >> actor_sec;
		}

		void printValue() {
			cout <<endl<<endl<< nume;
			cout << endl << actor_princ;
			cout << endl << actor_sec << endl;
		}

	};

	l3_e2() {
		main();
	}

	void main() {
		film a("Colonelul Ion", "Jeff Cioc", "Klo"), b("Filmul - Continuarea", "Ionica Georgica", "Loko Cioco"), c("Filmul - Prequel", "Ionica Georgica", "Loko Cioco");

		a.printValue();
		b.printValue();
		c.printValue();
	}
	
};

/*
	Să se realizeze un program pentru calculul valorii unui polinom într - un punct.Pentru aceasta se va utiliza o clasă în care coeficienţii polinomului sunt de tip privat, o funcţie pentru iniţalizarea valorilor coeficienţilor şi o funcţie pentru calculul valorii polinomului într - un punct dat
*/

class l3_e3 {
public:
	class polinom {
		vector<int> *coef;
		int n;

	public:
		polinom() {
			main();
		}
		
		void main() {
			cout << "Introduceti ordinul polimomului ";
			cin >> n;

			coef = new vector<int>[n + 1];
			initCoef(n);

			printCoef();
			int x;
			cout << "\n\nx: "; cin >> x;

			f(x);
		}

		void initCoef(int n) {
			cout << endl;
			for (int i = 0; i <= n; i++) {
				cout << "Coeficientul lui x^" << i  << " : ";
				int x; cin >> x;
				coef->push_back(x);
			}
		}

		void printCoef() {
			cout << endl;
			for (int i = coef->size()-1; i >= 0; i--)
				cout << coef->at(i) << ' ';
		} 

		void f(int x) {
			int s = 0;
			for (unsigned i = 0; i < coef->size(); i++)
				s += (int)(coef->at(i) * pow(x, i));

			cout << "\nf(" << x << ") este " << s<<endl;
		}

	};

};

/*
	Să se realizeze un program care calculează data zilei de mäine cunoscänd data zilei de astăzi folosind pentru aceasta o structură de tipul clasă.  
*/

class l3_e4 {
public:

	class calendar {
		struct data{
			int zi, luna, an;
		} d1, d2;

	public:
		calendar() {
			do {
				cout << "Introduceti o luna: "; cin >> d1.luna;
			} while (d1.luna < 1 || d1.luna > 12);

			cout << "Introduceti un an: "; cin >> d1.an;
			verifyDate(d1);

			nextDate(d1);
			
			//system("cls");		
		}

		void verifyDate(data &d1) {

			switch (d1.luna) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					do {
						cout << "Introduceti o zi: "; cin >> d1.zi;
					} while (d1.zi < 1 || d1.zi > 31);

					break;

				case 2:
					if (d1.an % 4) {
						do {
							cout << "Introduceti o zi: "; cin >> d1.zi;
						} while (d1.zi < 1 || d1.zi > 28);
					}
					else {
						do {
							cout << "Introduceti o zi: "; cin >> d1.zi;
						} while (d1.zi < 1 || d1.zi > 29);
					}

					break;

				case 4: case 6: case 9: case 11:
					do {
						cout << "Introduceti o zi: "; cin >> d1.zi;
					} while (d1.zi < 1 || d1.zi > 30);

					break;

				default:
					cout << "\nError\n";
					break;
			}
		}

		void nextDate(data d) {
			data a {0,0,0 };

			if (d.luna == 12 && d.zi == 31) a.luna = a.zi = 1, a.an = d.an + 1;
			else

			switch (d.luna) {
				case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					if (d.zi == 31) 
							a.zi = 1, a.luna = d.luna + 1, a.an = d.an;
					else	a.an = d.an, a.zi = d.zi + 1, a.luna = d.luna;

					break;


				case 4: case 6: case 9: case 11:
					if (d.zi == 30)
						a.zi = 1, a.luna = d.luna + 1, a.an = d.an;
					else	a.an = d.an, a.zi = d.zi + 1, a.luna = d.luna;
					break;


				case 2:
					if ((d.an % 4 && d.zi == 28) || (d.an %4 == 0 && d.zi == 28))
							a.zi = 1, a.luna = d.luna + 1, a.an = d.an;
					else a.zi = d.zi + 1, a.luna = d.luna + 1, a.an = d.an;
	
				default: break;
			}

			cout << endl<<a.zi << '\t' << a.luna << '\t' << a.an << endl;
		}

	};
};

/*
	Utilizänd o clasă pentru gruparea datelor şi metodelor, să se realizeze un program pentru rezolvarea unei ecuaţii de gradul I şi un program pentru rezolvarea unei ecuaţii de gradul al II-lea. 
 
*/

class l3_e5 {
public:
	class ecuatii {
		int a, b, c;

	public:
		void i() {
			cout << "\na * x + b = 0\n";
			do { cout << "a: "; cin >> a; } while (!a);
			cout << "b: "; cin >> b;

			printf("x este %f\n", (float)-b / a);
		}

		void ii() {
			cout << "\na * x^2 + b * x + c = 0\n";
			do { cout << "a: "; cin >> a; } while (!a);
			cout << "b: "; cin >> b;
			cout << "c: "; cin >> c;

			int delta = b * b - 4 * a*c;

			cout << endl;
			if (delta > 0) cout << (float)((-b - sqrt(delta)) / 2 * a) << '\t' << (float)((-b + sqrt(delta)) / 2 * a) << endl;
			else if (!delta) cout << (float)(-b / 2 * a) << endl;
			else cout << "Delta negativ. Rezultatul va fi un numar complex\n";
		}

		void main() {
			int ord = 4;

			do {
				cout << "Introduceti ordinul ecuatiei: ";
				cin >> ord;
			} while (ord < 1 || ord > 2);


			// TODO: do while a == 0
			if (ord == 1) i();
			else ii();

		}
	};

};


class l3 {
public:
	class Carte {
		char editura[256];   
		void arata_editura(void) { 
			cout << editura << '\n';
		}

	public:   
		char titlu[256];   
		char autor[64];   
		float pret;   
	
		void arata_carte(void) { 
			cout << endl<<titlu << '\n'<<autor<<endl; 
			arata_editura();
		}
		float da_pret(void) { return(pret); }; 
	
		Carte(void) {
			cout << "\nTry using the other constructor (Titlu, Autor, Editura, Pret)\n";
		}

		Carte(const char* Titlu, const char *Autor, const char *Editura, float Pret) {
			strcpy(titlu, Titlu);
			strcpy(autor, Autor);
			strcpy(editura, Editura);
			pret = Pret;

			main();
		}

		void main(void) {
			arata_carte();
			cout << "Pretul cartii este: " << da_pret() << '\n';
		}

	};
};

