#pragma once
#include "pch.h"


/*
	AIA 2 - Programarea Orientata pe obiecte: Laboratorul 9
	@author: Ciubuc Mihai-Marian
*/


/*
	 Să se realizeze un program de supraîncărcare a operatorului "–" astfel încât acesta să elimine un anumit caracter dintr-un şir dat (de exemplu instrucţiunea  sir=sir1-ch să aibă ca rezultat eliminarea caracterului ch din sirul sir1). 
*/

class l9_e1 {

public:

	class Sir {
		char string[256];  
		int lung;

	public:

		Sir(const char *in_sir) {
			strcpy(string, in_sir);
			lung = strlen(string);
		}  

		Sir(char *in_sir) {
			strcpy(string, in_sir);
			lung = strlen(string);
		}
		
		Sir(void) { 
			lung = 0; 
		};  
		
		void arata_sir() { 
			cout << string;
		}

		Sir operator - (char ch) {
			char temp[256];

			strcpy(temp, string);

			for (int i = 0; i < lung; i++) 
				if (temp[i] == ch) {
					int j = i;
					for (; j < lung - 1; j++)
						temp[j] = temp[j + 1];
					temp[j] = '\0';
					lung--;
					i--;
				}

			return temp;
		}	
	};


	l9_e1() {
		main();
	}

	void main() {
		char s[50], ch;
		cout << "Care este sirul? "; cin >> s;

		cout << "Sirul este " << s << endl;
		cout << "\nCare este caracterul pe care doriti sa il eliminati? "; cin >> ch;

		Sir titlu(s); 
		titlu = titlu - ch;

		cout << "Sirul dupa eliminare este: "; titlu.arata_sir();  cout << endl;
	}

};


/*
	 Să se creeze o clasă FRACŢIE care să aibă două date de tip întreg: - numărător (care reprezintă numărătorul fracţiei) ; - numitor (care reprezintă numitorul fracţiei). 
	 
	 Să se supraîncarce operatorii " + ", " - ", " * ", " / " astfel încât să realizeze cele patru operaţii aritmetice cu fracţii. (Rezultatele se vor afişa sub forma a/b unde a este numărătorul, iar b este numitorul rezultatului). 
 	
*/

class l9_e2 {
public:

	class fr {
		int numarator, numitor = 1;

	public:
		fr(int a, int b) {

			if (a < 0 && b < 0) {
				a = -a; 
				b = -b;
			}

			numarator = a;
			numitor = b;

			//simplify();
		}

		void printValues() {
			cout << numarator << '/' << numitor << endl;
		}

		fr operator + (fr);
		fr operator - (fr);
		fr operator * (fr);
		fr operator / (fr);

		int multiple(int, int);
		int divisor(int, int);
		void simplify();
	};

	l9_e2() {
		main();
	}

	void main() {
		int x, y;

		cout << "x: "; cin >> x;
		cout << "y: "; cin >> y;
		fr a(x, y);
		a.simplify();

		cout << "\nx: "; cin >> x;
		cout << "y: "; cin >> y;
		fr b(x, y);
		b.simplify();

		cout << "\nFractiile sunt\n";
		a.printValues();
		b.printValues();


		cout << "\nRezultatele operatiilor sunt\n\n";
		cout << "+: ";
		fr s = a + b;
		s.simplify();
		s.printValues();

		cout << "\n-: ";
		fr d = a - b;
		d.simplify();
		d.printValues();

		cout << "\n*: ";
		fr m = a * b;
		m.simplify();
		m.printValues();

		cout << "\n/: ";
		fr i = a / b;
		i.simplify();
		i.printValues();
	}
};


l9_e2::fr l9_e2::fr::operator+ (fr b) {

	int multiplu = multiple(numitor, b.numitor);


	return *new fr( numarator * (multiplu /numitor) + b.numarator * (multiplu /b.numitor), multiplu);
}

l9_e2::fr l9_e2::fr::operator- (fr b) {

	int multiplu = multiple(numitor, b.numitor);
	return *new fr(numarator * (multiplu / numitor) - b.numarator * (multiplu / b.numitor), multiplu);
}

l9_e2::fr l9_e2::fr::operator* (fr b) {
	return *new fr(numarator * b.numarator, numitor * b.numitor);
}

l9_e2::fr l9_e2::fr::operator/ (fr b) {
	return *new fr(numarator * b.numitor, numitor * b.numarator);
}

int l9_e2::fr::multiple(int a, int b) {

		int x = a, y = b;

		while (x != y) {
			if (x > y)
				x = x - y;
			else
				y = y - x;
		}

		return (a*b) / x;
}

// simplificare si semn

int l9_e2::fr::divisor(int a, int b) {

	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;
}

void l9_e2::fr::simplify() {
	int divizor = divisor(numitor, numarator);

	if (!(numitor % divizor) && !(numarator % divizor)) {
		numitor /= divizor;
		numarator /= divizor;
	}
}

//ostream & operator << (ostream& iesire, PL w) {
//	return iesire << w.x << endl;
//}