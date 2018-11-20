#pragma once
#include "pch.h"
#include "dateMember.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 8
	@author: Ciubuc Mihai-Marian
*/

/*
	Să se realizeze un program ce implementează o clasă Patrulater care conţine patru date de tip Punct (clasa Punct defi  neşte şi afişează coordonatele unui punct din plan şi este definită în interiorul clasei patrulater). 
	
	Să se realizeze o funcţie care determină natura patrulaterului pe care îl formează cele 4 puncte (paralelogram, romb, dreptunghi, pătrat sau patrulater oarecare) şi o funcţie care calculează aria acestuia (cu excepţia cazului în care patrulaterul este oarecare). 
 */


class l8_e1 {
public:
	class Patrulater {
		class Punct {
			float x, y;

		public:

			friend class Patrulater;
			
			void printCoord() {
				cout << endl << x << '\t' << y << endl;
			}

			Punct() { x = y = 0; }
			Punct(float X, float Y) { x = X, y = Y; }
		};

		Punct A, B, C, D;

	public:

		friend class l8_e1;

		float getLength(Punct a, Punct b) {
			return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
		}

		/*	
			Given quadrilater ABCD

			Edges :			l[0] = AB, l[1] = BC, l[2] = CD, l[3] = DA
			Diagonals :		l[4] = AC, l[5] = BD
		*/

		float l[6];
		void setTheLengths() {

			l[0] = getLength(A, B);
			l[1] = getLength(B, C);
			l[2] = getLength(C, D);
			l[3] = getLength(D, A);
			l[4] = getLength(A, C);
			l[5] = getLength(B, D);

		}

		/*
			@function	getType
			@returns:	0 - error, 1 - patrat, 2 - romb, 3 - paralelogram, 4 - dreptunghi, 5 - oarecare
		*/

		int getType()
		{
			// Verify if the given figure is quadrilater

			if (	((A.x == B.x) && (B.x == C.x) && (A.x = C.x))  ||
					((A.x == B.x) && (A.x == D.x) && (B.x == D.x)) || 
					((A.x == C.x) && (C.x == D.x) && (A.x == D.x)) || 
					((B.x == C.x) && (C.x == D.x) && (B.x == D.x))
				)	return 0;


			if (	((A.y == B.y) && (B.y == C.y) && (A.y = C.y))	|| 
					((A.y == B.y) && (A.y == D.y) && (B.y == D.y))	|| 
					((A.y == C.y) && (C.y == D.y) && (A.y == D.y))  || 
					((B.y == C.y) && (C.y == D.y) && (B.y == D.y))
				)	return 0;

			// Figure types
			if ((l[0] == l[1]) && (l[1] == l[2]) && (l[4] == l[5]))
				return 1; 
			else {
				if ((l[0] == l[1]) && (l[1] == l[2]) && (l[4] != l[5]))
					return 2; 
				
				else {
					if ((l[0] == l[2]) && (l[1] == l[3]) && (l[4] != l[5]))
						return 3; 

					if ((l[0] == l[2]) && (l[0] != l[1]) && (l[4] == l[5]))
						return 4;
					else
						return 5;
				}
			}
		}

		void verifyType();


		// Class constructors 
		// Patrulater(void);
		Patrulater(Punct, Punct, Punct, Punct);
		Patrulater(Punct*, Punct*, Punct*, Punct*);
		
	};


	l8_e1() {
		main();
	}

	void main() {

		typedef Patrulater::Punct Point;
		Patrulater p(Point(-4, 0), Point(0, -2),Point(4, 0), Point(0, 3));
		p.verifyType();
		
	}
};

 
 /* 
	Să se creeze o clasă Client, pentru gestionarea conturilor unei bănci, care să conţină următoarele date: numele, prenumele, numărul de telefon şi vârsta clientului, şi o dată de tip Cont_Bancar (clasa Cont_Bancar definită în interiorul clasei Client) care conţine următoarele date: numărul contului, suma depusă în lei, echivalentul sumei în euro, dobânda aferentă contului, suma la data actuală şi data deschiderii contului.

 Clasa Cont_Bancar are următoarele funcţii: o funcţie ce converteşte suma din lei în euro, o funcţie ce calculează suma totală (suma depusă + dobânda) în funcţie de data curentă şi de data depunerii sumei şi o funcţie de afişare a numărului contului şi a sumei aflate în cont în lei şi valută. Să se creeze trei obiecte de tip Client şi să se afişeze toate informaţiile referitoare la cei trei clienţi.  
*/

class l8_e2 {
public:
	class Client {
		string name, surname, phoneNumber;
		unsigned age;

	public:
		Client() {
			cout << "\nNume: "; cin >> name;
			cout << "Prenume: "; cin >> surname;
			cout << "Numar telefon: "; cin >> phoneNumber;
			cout << "Varsta : "; cin >> age;		
		}


		Client(string Name, string Surname, string PhoneNumber, unsigned Age) {
			name = Name, surname = Surname, phoneNumber = PhoneNumber, age = Age;
		}

		class Cont_Bancar {
			int id;
			float balanceRO, balanceEU, interest, currentBalance;
			Date dataDeschidere;
			Date dataCurenta = { 20, 10, 2018 };

		public:

			float returnBalanceEU(float balance) {
				 return balance / 4.67588556f;
			}

			void setDate() {	//TODO: do while conditions

				cout << "\nZi deschidere cont: ";	cin >> dataDeschidere.d;
				cout << "Luna: ";					cin>> dataDeschidere.m;
				cout << "An: ";						cin >> dataDeschidere.y;
			}

			Cont_Bancar() {
				cout << "\nNumar cont: ";		cin >> id;
				cout << "Suma depusa in lei: "; cin >> balanceRO;
				setDate();
				sumaTotala();
			}

			void setInterest() {			// According to BT

				if (balanceRO >= 1000 && balanceRO <= 9999)			interest = 0.011f;
				else if (balanceRO > 9999 && balanceRO <= 99999)	interest = 0.0115f;
				else if (balanceRO > 99999 && balanceRO <= 499999)	interest = 0.012f;
				else if (balanceRO > 499999)						interest = 0.0125f;
				else												interest = 0.f;
			}

			void sumaTotala() {
				setInterest();
				currentBalance = balanceRO + balanceRO * interest*getDifference(dataDeschidere, dataCurenta);
			}

			void printInfo() {


				cout << "\nNumar cont: " << id;
				cout << "\nSuma depusa initial: " << balanceRO;
				cout << "\nSuma curenta in lei: " << currentBalance;
				cout << "\nSuma curenta in valuta: " << returnBalanceEU(currentBalance) << endl;
			}

		} contBancar;
	};

	l8_e2() {
		main();
	}

	void main() {
		Client A("Cornel", "Gigel", " ", 35), B("Genevo", "Costin", " ", 20), C("Mik", "Ionel", " ", 40);

		system("cls");
		A.contBancar.printInfo();
		B.contBancar.printInfo();
		C.contBancar.printInfo();
	}
};


l8_e1::Patrulater::Patrulater(Punct a, Punct b, Punct c, Punct d) {
	A = *new Punct(a.x, a.y);
	B = *new Punct(b.x, b.y);
	C = *new Punct(c.x, c.y);
	D = *new Punct(d.x, d.y);
	setTheLengths();
}

l8_e1::Patrulater::Patrulater(Punct *a, Punct *b, Punct *c, Punct *d) {
	A = *new Punct(a->x, a->y);
	B = *new Punct(b->x, b->y);
	C = *new Punct(c->x, c->y);
	D = *new Punct(d->x, d->y);
	setTheLengths();
}

/*
		@function	getType
		@returns:	0 - error, 1 - patrat, 2 - romb, 3 - paralelogram, 4 - dreptunghi, 5 - oarecare
*/

void l8_e1::Patrulater::verifyType() {
	switch (getType()) {
		case 0: 
			cout << "\nThe given figure is not a quadrilater\n";
			break;

		case 1:
			cout << "\nThe given figure is a square and it's surface is " << pow(l[0], 2) << endl;
			break;

		case 2:
			cout << "\nThe given figure is a rhombus and it's surface is " << .5f * l[4] * l[5] << endl;
			break;

		case 3:
			cout << "\nThe given figure is a parallelogram and it's area is {base} * {height}" << endl;
			break;

		case 4:
			cout << "\nThe given figure is a rectangle and it's area is " << l[0] * l[1]<<endl;
			break;

		case 5:
			cout << "\n The given figure is a random quadrilater\n";
			break;
	}
}