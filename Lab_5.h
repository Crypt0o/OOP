#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 5
	@author: Ciubuc Mihai-Marian
*/


/*
	Să se realizeze un program ce foloseşte o clasă Film cu următorii membrii: nume, actor principal, actor secundar. Se cere afişarea membrilor. Se vor utiliza funcţii constructor şi destructor.  
*/

class l5_e2 {
public:
	class Film {
		string nume, ap, as;

	public:
		Film(string a, string b, string c) {
			nume = a, ap = b, as = c;
		}

		~Film(void) {
			cout << "\n\nS-a apelat destructorul pentru filmul " << nume << endl;
		}

		void afiseazaMembrii(void) {
			cout << "Nume film: " << nume;
			cout << "\nActor principal: " << ap;
			cout << "\nActor secundar: " << as;
		}
	};

	l5_e2() {
		main();
	}

	void main(void) {
		Film x("Pisica salbatica", "Kitty Kat", "Winnie the Doggo");
		x.afiseazaMembrii();
	}
};

/*
	Să se realizeze un program care utilizează o clasă Grupa ce conţine ca date numele, prenumele, vârsta, notele la 5 examene şi media acestora pentru 10 studenţi. Clasa va avea o funcţie constructor pentru iniţializarea numelui şi prenumelui iar notele se vor citi de la tastatură. Media notelor va fi de tip privat. 
*/

class l5_e3 {
public:
	class Grupa {
		float media;

	public:
		string nume, prenume;
		unsigned varsta;
		vector<int> note[5];

		Grupa(string a, string b) {
			nume = a, prenume = b;
			read();
		}

		void read(void) {
			cout << "Introduceti cele 5 note pentru elevul "<< nume << ' ' << prenume<<endl;
			int x;
			for (int i = 0; i < 5; i++)
				cin >> x, note->push_back(x);

			cout << endl;
			//print();
			calculateMean();
		}

		void print(void) {
			cout << endl;
			for (int i = 0; i < 5; i++)
				cout << note->at(i) << ' ';
			cout << endl;
		}

		void calculateMean(void) {
			int s = 0;
			for (int i = 0; i < 5; i++)
				s += note->at(i);

			media = (float) s / 5;
		}

		~Grupa() {
			cout << "Elevul " << nume << ' ' << prenume << " are media " << media << endl;
		}
	};

	l5_e3() {
		main();
	}

	void main(void) {
		Grupa a0("Miai", "Marean"), a1("Costin", "Marean"), a2("Marius", "George");

		cout << endl;
	}


};


/*
	Să se realizeze un program care conţine două clase: o clasă ce va conţine un tip de maşină, culoarea acesteia şi preţul şi o clasă care conţine numele, prenumele şi vârsta unui şofer. Obiectele celei de-a doua clase vor apela obiectele primei clase pentru a specifica maşina fiecărui şofer.  Se vor utiliza funcţii constructor şi destructor 
*/

class l5_e4 {

public:

	class masina {
		string tip, culoare;
		unsigned pret;

	public:
		masina(string a, string b, unsigned c) {
			tip = a, culoare = b, pret = c;
		}

		~masina() {
			getType();
			getColor();
			getPrice();
			cout << endl;
		}

		void setCar(string Tip, string Culoare, unsigned Pret) {
			tip = Tip, culoare = Culoare, pret = Pret;
		}

		void getColor() {
			cout << endl << culoare;
		}

		void getType() {
			cout << endl << tip;
		}

		void getPrice() {
			cout << endl << pret;
		}
	};

	class sofer {
		string nume, prenume;
		unsigned varsta;

	public:

		sofer(string Nume, string Prenume, unsigned Varsta) {
			nume = Nume, prenume = Prenume, varsta = Varsta;
		}

		void apelA() {
			string Tip, Culoare; 
			unsigned Pret;

			cout << "\nIntroduceti culoarea masinii: ";
			cin >> Culoare;

			cout << "Introduceti tipul: ";
			cin >> Tip;

			cout << "Introduceti pretul: ";
			cin >> Pret;

			masina A(Tip, Culoare, Pret);
		}
	};

	l5_e4() {
		main();
	}

	void main() {
		sofer a("Cornel", "Daniel", 25);
		a.apelA();
	}

};