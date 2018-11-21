#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 7
	@author: Ciubuc Mihai-Marian
*/

/*
	Să se implementeze o clasă Punct care conţine 6 date de tip privat: 3 reprezintă coordonatele polare ale punctului în spaţiu (unghiurile fi , theta şi distanţa ro), iar 3 sunt coordonatele carteziene ale punctului (x, y şi z). Constructorul clasei va iniţializa cele trei coordonate polare, iar clasa va avea o funcţie de calcul a coordonatelor carteziene ştiind că formulele de calcul sunt urm:

				x = rho * cos(theta) * cos(phi);
				y = rho * cos(theta) * sin(phi);
				z = rho * sin(theta);

	De asemenea, clasa va avea o funcţie de afişare a coordonatelor polare şi o funcţie de afişare a coordonatelor carteziene.
	
	Să se creeze o clasă Segment care să conţină două date de tip Punct şi o funcţie care să calculeze lungimea segmentului (egală cu distanţa dintre cele două puncte). 
	
	Să se creeze două segmente şi să se afişeze coordonatele polare şi  carteziene ale capetelor segmentelor precum şi lungimea segmentelor.
*/

class l7_e1 {
public:
	
	class Punct {
		float x, y, z, rho, theta, phi;

	public:
		Punct() {
			cout << "\nPunct nou\n";
			cout << "\nRho: ";		cin >> rho;
			cout << "Theta: ";	cin >> theta;
			cout << "Phi: ";		cin >> phi;

			calculateCartesianCoordinates();
		}

		Punct(float Rho, float Theta, float Phi) {
			rho = Rho, theta = Theta, phi = Phi;

			calculateCartesianCoordinates();
		}

		void calculateCartesianCoordinates() {
			x = rho * cos(theta) * cos(phi);
			y = rho * cos(theta) * sin(phi);
			z = rho * sin(theta);
		}

		void printCartesian() {
			cout << "\nx: " << x;
			cout << "\ny: " << y;
			cout << "\nz: " << z<<endl;
		}

		void printPolar() {
			cout << "\nRho: " << rho;
			cout << "\nTheta: " << theta;
			cout << "\nPhi: " << phi<<endl;
		}

		float returnCoordinate(string coordinate) {
			if (coordinate == "x" || coordinate == "X")
				return x;
			else if (coordinate == "y" || coordinate == "Y")
				return y;
			else if (coordinate == "z" || coordinate == "Z")
				return y;
			else if (coordinate == "rho" || coordinate == "Rho" || coordinate == "RHO")
				return rho;
			else if (coordinate == "phi" || coordinate == "Phi" || coordinate == "PHI")
				return phi;
			else if (coordinate == "theta" || coordinate == "Theta" || coordinate == "THETA")
				return theta;
			else return 0.0f;
		}
	};

	class Segment {
		Punct a, b;

	public:


		float getLength() {
			return sqrt(pow(a.returnCoordinate("x") - b.returnCoordinate("x"), 2) + pow(a.returnCoordinate("y") - b.returnCoordinate("y"), 2) + pow(a.returnCoordinate("z") - b.returnCoordinate("z"), 2));
		}

		void printPoints() {
			cout << "\nCoordonatele carteziene ale punctelor segmentului sunt\n";
			cout << endl << a.returnCoordinate("x") << '\t' << a.returnCoordinate("y") << '\t' << a.returnCoordinate("z") << endl;

			cout<< b.returnCoordinate("x") << '\t' << b.returnCoordinate("y")<< '\t' << b.returnCoordinate("z") << endl;

			cout << "\nCoordonatele polare ale punctelor segmentului sunt\n";
			cout << endl << a.returnCoordinate("rho") << '\t' << a.returnCoordinate("theta") << '\t' << a.returnCoordinate("phi") << endl;

			cout << b.returnCoordinate("rho") << '\t' << b.returnCoordinate("theta") << '\t' << b.returnCoordinate("phi") << endl;


			cout << "\nLungimea segmentului este: " << getLength() << endl << endl;
		}

	};


	l7_e1() {
		main();
	}

	void main() {
		Segment unu;
		unu.printPoints();

		system("pause");
		system("cls");

		Segment doi;
		doi.printPoints();
	}
};

/*
	 Să se implementeze o clasă Punct care să conţină două date de tip privat x şi y ce reprezintă coordonatele carteziene în plan ale unui punct, o funcţie constructor care iniţializează cele două coordonate şi o funcţie de afişare a coordonatelor. 
	 
	 Să se creeze o clasă Triunghi de tip friend cu clasa Punct, care să conţină trei elemente de tipul Punct ce reprezintă vârfurile unui triunghi. 
	 
	 Să se creeze o funcţie care să stabilească dacă triunghiul este echilateral, isoscel sau oarecare şi o funcţie care să calculeze perimetrul triunghiului. 
*/

class l7_e2 {
public:
	class Triunghi;

	class Punct {
		float x, y;

	public:
		Punct() {

			cout << "\nInitializare punct ";
			cout << "\nx: "; cin >> x;
			cout << "y: "; cin >> y;
		//	printCoord();
		}

		Punct(float X, float Y) {
			x = X, y = Y;
		}

		void printCoord() {
			printf("\n(%g %g)\n", x, y);
		}

		friend class Triunghi;
	};

	class Triunghi {
		Punct A, B, C;

	public:
		int tipTriunghi() {
			float x = getLength(B, C), y = getLength(A, C), z = getLength(A, B);
			cout << endl<< x << '\t' << y << '\t' << z << endl;

			if (!x || !y || !z) return 0; // Eroare
			
			if (x == y && y == z) return 1; // Echilateral
			else if ((x == y) || (x == z) || (y == z)) return 2; // Isoscel
			else return 3; // Oarecare
		}

		float getLength(Punct a, Punct b) {
			return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
		}

		float Perimetru() {
			return getLength(B, C) +  getLength(A, C) + getLength(A, B);
		}

		Triunghi() {
			switch (tipTriunghi()) {

			case 1:
				cout << "\nTriunghiul este echilateral\n";
				break;

			case 2:
				cout << "\nTriunghiul este isoscel\n";
				break;

			case 3:
				cout << "\nTriunghiul este oarecare\n";
				break;

			case 4:
				cout << "\nEroare\n";
				break;
			}

			cout << "\nPerimetrul triunghiului este " << Perimetru() << endl;
		}

	};

	l7_e2() {	
		main(); 
	}

	void main() {
		Triunghi d;
	}
};