#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 1
	@author: Ciubuc Mihai-Marian
*/

/*
	Să se realizeze un program pentru calculul produsului scalar a a doi vectori de numere íntregi
iar rezultatul se va afişa pe o singură linie cu o distanţă de cinci caractere între elementele
vectorului, aliniate la dreapta, în baza 8 şi baza 16 iar spaţiile libere vor fi completate cu
caracterul ‘.’ 

*/
class l1_e2 {

	 struct vectoras{
		int x, y, z;
	} v1, v2;

public:
	l1_e2() {
		main();
	}

	int produsScalar(vectoras v1, vectoras v2) {

			return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}

	void main() {

		cout << "\nIntroduceti valorile primului vector (x, y, z )\n";
		cin >> v1.x>> v1.y >> v1.z;

		cout.fill('.');
		//cout <<v1.x << setw(5) << v1.y << setw(5) << v1.z << endl<<right;
	
		cout << "\nIntroduceti valorile celui de-al doilea vector (x, y, z)\n";
		cin >> v2.x >> v2.y >> v2.z;
		//cout <<v2.x << setw(5) << v2.y << setw(5) << v2.z << endl<<right;

		int r = produsScalar(v1, v2);
		cout << right << endl<<r << "....." << oct << r << "....." << hex << r << endl;
	}
};

/*
	Să se realizeze un program ce calculează norma unui vector şi afişează rezultatul ín format
ştiinţific (exponenţial). 

*/


class l1_e3 {

	struct vectoras {
		float x, y, z;
	} v;

public:
	l1_e3() {
		main();
	}

	l1_e3(float x, float y, float z) {
		v.x = x, v.y = y, v.z = z;
	}

	void norma() {
		cout << "Norma vectorului este " << scientific << sqrt(v.x*v.x + v.y*v.y + v.z*v.z) << endl;
	}

	// Only use it if you don't use the overloaded constructor
	void main() {
		cout<<"Introduceti vectorul\n";
		cin>>v.x>>v.y>>v.z;

		norma();

	}
};


/*
	Să se realizeze un program pentru calculul mediei aritmetice, geometrice şi armonice a 5
numere reale citite de la tastatură şi afişează rezultatele în format fix cu precizie de 3 zecimale. 
*/

class l1_e4 {
	vector <float> v[5];

public:
	float arithmeticMean(int n) {
		float s = 0;
		for (auto i = 0; i< n; i++)
			s += v->at(i);

		return (float)s / n;
	}

	float geometricMean(int n) { 
		float product = 1;
		for (int i = 0; i < n; i++)
			product = product * v->at(i);


		float gm = pow(product, (float) 1 / n);

		return gm;
	}

	float harmonicMean(int n) {
		float sum = 0;
		for (int i = 0; i < n; i++)
			sum = sum + (float)1 / v->at(i);

		return (float) n / sum;
	}

	void main() {
		cout << "Introduceti cele 5 numere reale\n";
		
		for (auto i = 0; i < 5; i++) {
			float x;
			cin >> x;
			v->push_back(x);
		}


		cout << setprecision(3) << setiosflags(ios::fixed);

		cout << "\nMedia aritmetica este\t" << arithmeticMean(v->size());
		cout << "\nMedia geometrica este\t" << geometricMean(v->size());
		cout << "\nMedia armonica este\t" << harmonicMean(v->size()) << endl;
	}

	l1_e4() {
		main();
	}

};


/*
	Să se scrie un program care citeşte de la tastatură numele a 5 studenţi şi afişează iniţialele lor. 
*/
class l1_e5 {

	struct elev {
		string nume, prenume;
	} elevul[5];

public:
	l1_e5() { 
		for (int i = 0; i < 5; i++) 
			elevul[i].nume = elevul[i].prenume = ""; 

		main();
	}

	void main() {
		cout << "Introduceti numele celor cinci studenti\n";

		for (int i = 0; i < 5; i++)
			cin >> elevul[i].nume >> elevul[i].prenume;
		

		cout << endl;
		for (int i = 0; i < 5; i++)
			cout << elevul[i].nume[0] << ' ' << elevul[i].prenume[0] << endl;
	}

};