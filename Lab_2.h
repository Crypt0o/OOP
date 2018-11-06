#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 2
	@author: Ciubuc Mihai-Marian
*/

/*
	Să se realizeze un program pentru calculul sumei a două matrici de tip întreg şi de tip real folosind supraîncărcarea funcţiilor. 
*/

class l2_e2 {

	int **mi1, **mi2;
	float **mf1, **mf2;

public:

	l2_e2(int n, int m) {
		mi1 = new int*[n]; mi2 = new int*[n];
		mf1 = new float*[n]; mf2 = new float*[n];

		for (int i = 0; i < n; i++) {
			mi1[i] = new int[m], mi2[i] = new int[m];
			mf1[i] = new float[m], mf2[i] = new float[m];
		}

		main();
	}

	int** addMatrix(int **a, int **b, int n, int m) {

		int **c; c = new int*[n];

		for (int i = 0; i < n; i++)
			c[i] = new int[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				c[i][j] = a[i][j] + b[i][j];

		return c;
	}
	

	float** addMatrix(float **a, float **b, int n, int m) {

		float **c; c = new float*[n];

		for (int i = 0; i < n; i++)
			c[i] = new float[m];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				c[i][j] = a[i][j] + b[i][j];

		return c;
	}


	void read_iMatrix(int n, int m) {
		cout << "Prima matrice intreaga\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "[" << i+1 << "][" << j+1 << "]: ";
				cin >> mi1[i][j];
			}

		cout << "\nA doua matrice intreaga\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "[" << i+1 << "][" << j+1 << "]: ";
				cin >> mi2[i][j];
			}
	}

	void read_fMatrix(int n, int m) {
		cout << "Prima matrice reala\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "[" << i + 1 << "][" << j + 1 << "]: ";
				cin >> mf1[i][j];
			}

		cout << "\nA doua matrice reala\n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cout << "[" << i + 1 << "][" << j + 1 << "]: ";
				cin >> mf2[i][j];
			}
	}

	void main() {

		int n, m;

		cout << "Introduceti n si m "; cin >> n >> m;
		

		mi1 = new int*[n]; mi2 = new int*[n];
		mf1 = new float*[n]; mf2 = new float*[n];

		for (int i = 0; i < n; i++) {
			mi1[i] = new int[m], mi2[i] = new int[m];
			mf1[i] = new float[m], mf2[i] = new float[m];
		}


		
		read_iMatrix(n, m);
		int **c = addMatrix(mi1, mi2, n, m);

		cout << "Matricea intreaga\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << c[i][j] << ' ';
			cout << endl;
		}
		cout << endl;

		read_fMatrix(n, m);
		float **d = addMatrix(mf1, mf2, n, m);

		cout << "Matricea reala" <<endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << d[i][j] << ' ';
			cout << endl;
		}
	}

	l2_e2() {
		main();
	}
};



/*
	Acelaşi program pentru calculul produsului a două matrici. 
*/


class l2_e3 {

public :
	template <typename T>
	T produsMatrice(T **a, T **b, int n, int m) {

		T **c;
		c = new T*[n];
		for (int i = 0; i < n; i++)
			c[i] = new T[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				c[i][j] = a[i][j] * b[i][j];

		return c;
	}

};


/*
	Să se realizeze un program ce foloseşte două structuri: una ce cuprinde cãmpurile nume, prenume, vãrstă, şi o funcţie ce afişează numele şi vãrsta iar cea de-a doua ce cuprinde cãmpurile nume, prenume, ocupatie, salariu şi o funcţie (cu acelaşi nume cu funcţia din prima structură) ce afişează prenumele , ocupaţia şi salariul.  
*/

class l2_e4 {

public:
	struct s1{
		string nume, prenume;
		unsigned int varsta;
		void f() {
			cout << endl << endl << nume << '\n' << prenume << '\n' << varsta << endl;
		}
	} v1;

	struct s2 {
		string nume, prenume, ocupatie;
		unsigned int salariu;

		void f() {
			cout << endl << endl << prenume << '\n' << ocupatie << "\n" << salariu << endl;
		}
	} v2;


	
	l2_e4() {
		main();
	}
	

	void main() {
		cout << "Nume: ";		cin >> v1.nume; v2.nume = v1.nume;
		cout << "Prenume: ";	cin >> v1.prenume; v2.prenume = v1.prenume;
		cout << "Varsta: ";		cin >> v1.varsta;
		cout << "Ocupatie: ";	cin >> v2.ocupatie;
		cout << "Salariu: ";	cin >> v2.salariu;

		v1.f();
		v2.f();

	}
};


/*
	Să se realizeze un program ce utilizează două funcţii cu acelaşi nume pentru calculul mediei geometrice şi armonice, prima pentru trei numere reale iar cea de-a doua pentru patru numere reale. 
*/

class l2_e5 {
public:

	float medie(float a, float b, float c) {	
		float p = a * b * c;
		return pow(p, (float)1 / 3);
	}

	float medie(float a, float b, float c, float d) {
		float sum = a + b + c + d;
		return (float) 4/ sum;
	}
};

/*
	Să se realizeze un program ce utilizează două funcţii cu acelaşi nume pentru a determina cel mai mare din trei şi respectiv patru elemente pe care funcţiile le primesc ca argumente. 
*/
class l2_e6 {

public:
	/*
			HOW TO USE:

			f <TYPE> (parameters) 
	*/

	template <typename T>
	T f(T a, T b, T c) {

		T max = INT32_MIN;

		if (a > max) max = a;
		if (b > max) max = b;
		if (c > max) max = c;

		return max;
	}

	template <typename T>
	T f(T a, T b, T c, T d) {

		T max = INT32_MIN;

		if (a > max) max = a;
		if (b > max) max = b;
		if (c > max) max = c;
		if (d > max) max = d;

		return max;
	}
};
