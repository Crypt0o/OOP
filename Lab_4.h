#pragma once
#include "pch.h"

/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 4
	@author: Ciubuc Mihai-Marian
*/

/*
	Să se realizeze un program ce ordonează crescător elementele unui vector de numere reale şi apoi se afişează elementele şi adresele la care acestea se află în memorie. 
*/

class l4_e2 {
		
	vector<float> v {-5.2f, -89.2f, 62.1f, 49.521f, 15.82f, 1.25f, -25.28f};
	
public:
	l4_e2() {
		main();
	}

	void main() {
		for (unsigned i = 0; i < v.size(); i++)
			cout << v.at(i) << '\t';

		cout << "\n\n";

		sort(v.begin(), v.end());

		for (unsigned i = 0; i< v.size(); i++)
			cout << v.at(i) << '\t'<<&v.at(i)<<endl;
			
		cout << endl;
	}
};

/*
	Să se realizeze un program care foloseşte o funcţie ce primeşte ca argumente un pointer la un vector de numere reale şi un pointer la o funcţie şi returnează cel mai mic, respectiv cel mai mare element al vectorului prin apelarea unei funcţii de calcul a minimului respectiv a maximului. 
*/


float l4_e3_min(vector<float> v) {
	cout << "Cel mai mic element din vector este: ";
	float min = v[0];
	for (auto i : v)
		if (i < min) min = i;

	return min;
}

float l4_e3_max(vector<float> v) {
	cout << "Cel mai mare element din vector este: ";
	float max = v[0];
	for (auto i : v)
		if (i > max) max = i;

	return max;
}


class l4_e3 {
	vector<float> v{ -5.2f, -89.2f, 62.1f, 49.521f, 15.82f, 1.25f, -25.28f };

public:
	l4_e3() {
		main();
	}

	void f(float (*function)(vector<float>), vector<float> v) {
		cout << function(v) << endl;
	}

	void main() {

		for (unsigned i = 0; i < v.size(); i++)
			cout << v.at(i) << '\t';

		cout << "\n\n";

		f(::l4_e3_max, v);
	}

};

/*
	Să se scrie un program care citeşte o dată sub forma zz ll aaaa (de ex. 20 11 2001) şi o afişează sub forma yy luna aaaa (20 noiembrie 2001) folosind o funcţie ce returnează un pointer spre denumirea lunii calendaristice respective 
*/

class l4_e4 {
	int z, l, a;
	const char* luna[13] = {
		"", 
		"Ianuarie", 
		"Februarie", 
		"Martie", 
		"Aprilie", 
		"Mai", 
		"Iunie", 
		"Iulie", 
		"August", 
		"Septembrie", 
		"Octombrie", 
		"Noiembrie", 
		"Decembrie" 
	};

public:
	l4_e4() {
		main();
	}

	void main() {
		cout << "Introduceti ziua: "; cin >> z;
		do { cout << "Introduceti luna: "; cin >> l; } while (l < 1 || l > 12);
		cout << "Introduceti anul: "; cin >> a;

		cout <<endl<< z << '\t' << f(l) << '\t' << a << endl;

	}

	const char* f(int n) {
		return  luna[n];
	}
	
};

/*
		Să se scrie un program care determină rădăcina ecuaţiei f(x)=0 din intervalul [a,b] cu
	o eroare mai mică decât EPS=1e-8, ştiind că ecuaţia are o singură rădăcină în
	intervalul respectiv şi f(x) este o funcţie continuă pe acest interval. Se va utiliza o
	funcţie ce apelează ca parametru funcţia f căreia i se calculează rădăcina.

	Una din cele mai simple metode de calcul este metoda înjumătăţirii al cărei algoritm
	este următorul:

	1) c=(a+b)/2
	2) Dacă f(c)=0, atunci c este soluţia căutată şi se întrerupe procesul de calcul.
	3) Dacă f(a)*f(c)<0, atunci se pune b=c, altfel a=c
	4) Dacă b-a<EPS, atunci procesul de calcul se întrerupe şi rădăcina se ia media
	dintre a şi b.
		Altfel algoritmul se reia de la pasul 1).

	Se va aplica programul de mai sus la calculul rădăcinii ecuaţiei:
				x-sin(x+1)=0
	în intervalul [0.5 , 1], cu o eroare mai mică de 1e-8. 
*/

class l4_e5 {
	const double eps = 1e-8;
	double a, b;

public:

	l4_e5() {
		main();
	}

	void main() {
	
		cout << "a: "; cin >> a;
		cout << "b: "; cin >> b;

	beginning:
		double c = (a + b) / 2;

		if (!f(c)) {
			cout << "\nSolutia este: " << c << endl;
			return;
		}

		
		f(a)*f(c) < 0 ? b = c : a = c;
		//cout << a << '\t' << b << endl;

		if (b - a < eps) {
			cout << "\nSolutia este: " << (a + b) / 2<<endl;
			return;
		}
		else goto beginning;
		

	}

	double f(double x) {
		return x - sin(x + 1);
	}


};

/*
	Să se realizeze un program ce creează o listă simplă înlănţuită ale cărei noduri sunt structuri ce au următoarele câmpuri:
				cheie, nume, prenume, vârstă, salariu.

	Se va ordona lista crescător după nume şi după vârstă. 
*/

class l4_e6 {

	struct Node{
		int cheie;
		string nume, prenume;
		unsigned varsta, salariu;
		Node *next;
	};


public:
	l4_e6() {
		main();
	}

	void main() {
		Node* lista = NULL;
		int n;

		cout << "Dimensiune lista: "; cin >> n;

		for (int i = 0; i < n; i++) {
			string nu, pre;
			unsigned varsta, salariu;
			
			cout << "\nNume: "; cin >> nu;
			
			cout << "Prenume: ";  cin >> pre;
			cout << "Varsta: "; cin >> varsta;
			cout << "Salariu: "; cin >> salariu;

			push(&lista, i, nu, pre, varsta, salariu);
		}
		system("cls");
		cout << "Lista este\n";
		print(lista);

		cout << "\nSortarea dupa varsta este \n";
		ageSort(lista);
		print(lista);

		cout << "\nSortarea dupa nume este \n";
		nameSort(lista);
		print(lista);
	}

	void push(Node** head_ref, int cheie, string Nume, string Prenume, unsigned varsta, unsigned salariu)
	{
	
		Node* new_node = new Node;
		Node *last = *head_ref;

		new_node->cheie = cheie;
		new_node->nume = Nume;
		new_node->prenume = Prenume;
		new_node->varsta = varsta;
		new_node->salariu = salariu;

		new_node->next = NULL;

		if (*head_ref == NULL)
		{
			*head_ref = new_node;
			return;
		}

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		return;
	}

	void print( Node *node)
	{
		cout << endl;
		while (node != NULL)
		{
			cout << node->nume << '\t' << node->prenume<<'\t';
			printf("%u\t%u\n", node->varsta, node->salariu);
			node = node->next;
		}
	}

	void ageSort(Node *head) {
		Node *i, *j;

		for (i = head; i->next != NULL; i = i->next)
			for (j = i->next; j != NULL; j = j->next)
				if (i->varsta > j->varsta)
					swap(i, j);
	}

	void nameSort(Node *head) {
		Node *i, *j;

		for (i = head; i->next != NULL; i = i->next)
			for (j = i->next; j != NULL; j = j->next)
				if (i->nume.compare(j->nume) == 1)
					swap(i, j);
				else if (i->nume.compare(j->nume) == 0)
						if (i->prenume.compare(j->prenume) == 1)
						swap(i, j);
	}

	void swap(Node *i, Node *j) {
		string nu = i->nume, pre = i->prenume;
		int cheie = i->cheie;
		unsigned varsta = i->varsta, salariu = i->salariu;

		i->nume = j->nume, i->prenume = j->prenume, i->cheie = j->cheie;
		i->varsta = j->varsta, i->salariu = j->salariu;

		j->nume = nu, j->prenume = pre, j->cheie = cheie;
		j->varsta = varsta, j->salariu = salariu;
	}

};

/*
	Să se realizeze un program pentru calculul rădăcinilor ecuaţiei de gradul II folosind o
funcţie ai carei parametrii (coeficienţii ecuaţiei) vor fi apelaţi prin pointer şi prin referinţă. 
*/

class l4_e7 {
	int a, b, c;
public:
	l4_e7() {
		main();
	}

	void main() {
		a = 1, 2, 3;

		f(a, b, c);
		f(&a, &b, &c);

	}

	void f(int &a, int &b, int &c) {
		int delta = b * b - 4 * a*c;

		cout << endl;
		if (delta > 0) cout << (float)((-b - sqrt(delta)) / (2 * a)) << '\t' << (float)((-b + sqrt(delta)) / (2 * a));
		else if (!delta) cout << (float)(-b / (2 * a));
		else cout << "Delta negativ. Rezultatul va fi un numar complex\n";
	}

	void f(int *a, int *b, int *c) {
		int delta = *b * (*b) - 4 * (*a)*(*c);

		cout << endl;
		if (delta > 0) cout << (float)((-(*b) - sqrt(delta)) / (2 * *a)) << '\t' << (float)((-*b + sqrt(delta)) / (2 * *a));
		else if (!delta) cout << (float)(-*b / (2 * *a));
		else cout << "Delta negativ. Rezultatul va fi un numar complex\n";
	}


};
