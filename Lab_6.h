#pragma once
#include "pch.h"


/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 6
	@author: Ciubuc Mihai-Marian
*/

/*
	 Să se implementeze o clasa Data_de_Nastere care sa aibă ca membrii datele de tip întreg an, luna, zi şi o metodă arata_data care sa afiseze aceasta data, o clasa Student care sa aiba ca membrii nume, prenume si varsta , o clasă Note care să aibă ca membru un vector de cinci elemente de tip real ce cuprinde cinci note ale studentului şi o clasă Grupa derivată din cele trei clase anterioare care sa aiba ca membru propriu o variabilă întreagă nr_grupa. 
		
	Să se creeze 5 obiecte de tip Grupa şi să se afişeze informaţiile despre fiecare obiect sub forma: nr_grupa, nume, prenume, varsta, data nasterii si media notelor. Să se afişeze un mesaj la apelul funcţiilor constructor şi destructor pentru fiecare obiect. 
 */

class l6_e1 {
public:

	class Data_de_Nastere {
		int an, luna, zi;
	public:
		void arata_data() {
			printf("Data de nastere: %d %d %d\n", zi, luna, an);
		}

		Data_de_Nastere() {
			cout << "\nA fost apelat constructorul clasei Data_de_Nastere\n";

			cout << "\nIntroduceti ziua: "; cin >> zi;
			cout << "Introduceti luna: "; cin >> luna;
			cout << "Introduceti anul: "; cin >> an;
		}

		Data_de_Nastere(int Zi, int Luna, int An) {
			zi = Zi, luna = Luna, an = An;
		}

		~Data_de_Nastere() {
			cout << "A fost apelat destructorul clasei Data_de_Nastere\n";
		}

		void setData(int Zi, int Luna, int An) {
			zi = Zi, luna = Luna, an = An;
		}

	};

	class Student {
		string nume, prenume;
		unsigned varsta;

	public:
		Student() {
			cout << "\nStudent nou\n";

			cout << "\nIntroduceti numele studentului: ";		cin >> nume;
			cout << "Introduceti prenumele studentului: ";	cin >> prenume;
			cout << "Introduceti varsta studentului: ";		cin >> varsta;
		}

		Student(string Nume, string Prenume, unsigned Varsta) {
			Student::nume = Nume, Student::prenume = Prenume, Student::varsta = Varsta;
		}

		~Student() {
			cout << "A fost apelat destructorul clasei Student\n";
		}

		void setStudent(string Nume, string Prenume, unsigned Varsta) {
			Student::nume = Nume, Student::prenume = Prenume, Student::varsta = Varsta;
		}
		
		void printStudent() {
			cout << "\nNume: " << nume;
			cout << "\nPrenume: " << prenume;
			cout << "\nVarsta: " << varsta<<endl;
		}

	};

	class Note {
		vector <float> v[5];

	public:
		Note() {
			cout << "\nA fost apelat constructorul clasei Note\n";

			cout << "Introduceti cele 5 note\n";
			float x;
			for (int i = 0; i < 5; i++)
				cin >> x, v->push_back(x);
		}

		Note(float a, float b, float c, float d, float e) {	
			v->push_back(a), v->push_back(b), v->push_back(c), v->push_back(d), v->push_back(e);
			cout << "\nA fost apelat constructorul clasei Note\n";
		}

		~Note() {
			cout << "A fost apelat destructorul clasei Note\n";
		}

		void printMean() {
			float s = 0;

			for (int i = 0; i < (int) v->size(); ++i)
				s += v->at(i);
			
			cout << "Media: " << (float)s / v->size() << "\n\n";
		}

		void setNote(float a, float b, float c, float d, float e) {
			v->push_back(a), v->push_back(b), v->push_back(c), v->push_back(d), v->push_back(e);
		}

	};

	class Grupa : public Student, public Data_de_Nastere, public Note {
		int nr_grupa;
	public:

		Grupa(int nrGrupa) {
			nr_grupa = nrGrupa;
		}

		Grupa(int nrGrupa, string Nume, string Prenume, unsigned Varsta, int ZiNastere, int LunaNastere, int AnNastere, float n1, float n2, float n3, float n4, float n5) :Student(Nume, Prenume, Varsta), Note(n1, n2, n3, n4, n5), Data_de_Nastere(ZiNastere, LunaNastere, AnNastere)  {
			nr_grupa = nrGrupa;
		}

		~Grupa() {
			cout << "\nA fost apelat destructorul clasei Grupa\n";
		}

		void printInfo() {
			cout << "\nNumar grupa: " << nr_grupa;
			printStudent();
			arata_data();
			printMean();
		}
	};



	l6_e1() {
		main();
	}

	void main(void) {
		Grupa A(1, "Marean", "Dan", 20, 1, 1, 1990, 10, 7, 5, 7, 6); A.printInfo();
		Grupa B(2, "Genoviu", "Laur", 25, 15, 12, 1985, 5, 5,4,3,2); B.printInfo();
		Grupa C(1, "Carnat", "Vasile", 18, 15, 4, 1992, 10, 10, 10, 10, 10); C.printInfo();
		Grupa D(3, "Stanciu", "Vladimir", 25, 16, 11, 1985, 8, 8, 8, 8,8 ); D.printInfo();
		Grupa E(4, "Ecaterina", "Andreea", 20, 2, 4, 1990, 10, 8, 9, 10, 7); E.printInfo();
	}
};


/*
	Să se implementeze o clasa Jucători care să aibă ca membrii următoarele tablouri: nume, prenume şi varsta şi o clasă Echipa, derivată din clasa Jucători care să aibă ca membrii datele nume_echipă, puncte, golaveraj şi o metodă arata_date care să afişeze datele despre această echipă şi jucătorii ei. 
	
	Să se creeze 5 obiecte de tip Echipa şi să se afişeze clasamentul acestor 5 echipe. 
*/


class l6_e2 {
public:

	class Jucatori {
		string nume, prenume;
		unsigned varsta;

	public:
		Jucatori() {
			cout << "\nIntroduceti numele jucatorului: ";		cin >> nume;
			cout << "Introduceti prenumele jucatorului: ";	cin >> prenume;

			cout << "Introduceti varsta jucatorului: ";		cin >> varsta; 
			
		}

		Jucatori(string nume, string prenume, unsigned varsta) {
			Jucatori::nume = nume;
			Jucatori::prenume = prenume;
			Jucatori::varsta = varsta;
		}

		void printPlayer() {
			cout << "\nNume jucator: " << nume;
			cout << "\nPrenume jucator: " << prenume;
			cout << "\nVarsta jucator: " << varsta << endl;
		}
	};

	class Echipa : public Jucatori {
	public:
		string nume_echipa;
		int puncte, golaveraj;

		Echipa() {
			cout << "\nIntroduceti numele echipei: ";		cin >> nume_echipa;
			cout << "Introduceti punctele echipei: ";	cin >> puncte;
			cout << "Introduceti golaverajul echipei: ";		cin >> golaveraj;
		}

		Echipa(string Nume, int Puncte, int Golaveraj) {
			nume_echipa = Nume, puncte = Puncte, golaveraj = Golaveraj;
		}

		Echipa(string Nume, int Puncte, int Golaveraj, string numeJucator, string prenume, unsigned varsta) : Jucatori(numeJucator, prenume, varsta) {
			nume_echipa = Nume, puncte = Puncte, golaveraj = Golaveraj;
		}

		void arata_date() {
			cout << "\nNume: " << nume_echipa;
			cout << "\nPuncte: " << puncte;
			cout << "\nGolaveraj: " << golaveraj;

			printPlayer();
		}

		bool compare(const  Echipa & other) {
			if (puncte < other.puncte) return 1;
			else if (puncte == other.puncte)
				return golaveraj > other.golaveraj;
			else return 0;
		}

	};


	l6_e2() {
		main();
	}

	void main(void) {
		Echipa a("Gaz Metan Medias", 14, -1, "Stigmo", "Cealaul", 24); a.arata_date();
		Echipa f("Gaz Metan Medias", 14, -1, "Andrei", "Costin", 24); f.arata_date();

		Echipa b("CFR Cluj", 23, 6, "Gennifer", "Kloko", 20); b.arata_date();
		Echipa g("CFR Cluj", 23, 6, "Mateas", "Emil", 21); g.arata_date();

		Echipa c("Universitatea Craiova", 23, 9, "Ounounou", "Boli", 18); c.arata_date();
		Echipa d("FCSB", 15, 5, "Boloko", "Mirel", 23); d.arata_date();
		Echipa e("Sepsi", 15, 6, "Dan", "Sebastian", 21); e.arata_date();

		

		vector <Echipa> ligaI = { a, b,c, d, e};

		
	
		system("pause");
		system("cls");
		cout << endl;
		for (auto &i : ligaI)
			cout << i.nume_echipa <<right<< "\t\t"<< i.puncte<< '\t' << i.golaveraj<<endl;

		cout << endl;
		sort(ligaI.begin(), ligaI.end(), [](const Echipa& l, const Echipa& r) {
			if (l.puncte > r.puncte)
				return 1;
			else if (l.puncte == r.puncte)
				return l.golaveraj > r.golaveraj ? 1 : 0;
			else return 0;
		}
		
		);
			
		cout << "\nClasament\n\n";
		for (auto &i : ligaI)
			cout << i.nume_echipa <<right<< "\t\t" << i.puncte << '\t' << i.golaveraj << endl;

	}

};