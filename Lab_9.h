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
		cout << "Care este caracterul pe care doriti sa il eliminati? "; cin >> ch;

		Sir titlu(s); 
		titlu = titlu - ch;

		cout << "\nSirul dupa eliminare este: "; titlu.arata_sir();  cout << endl;
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
			numarator = a;
			numitor = b;
		}

		void printValues() {
			cout << numarator << '/' << numitor << endl;
		}

		fr operator + (fr);
		fr operator - (fr);
		fr operator * (fr);
		fr operator / (fr);

		int multiple(int, int);
	};

	l9_e2() {
		main();
	}

	void main() {
		fr a(1, 4), b(5, 6);
		cout << "Fractiile sunt\n";
		a.printValues();
		b.printValues();

		cout << "\nRezultatele operatiilor sunt\n\n";
		(a + b).printValues();
		(a - b).printValues();
		(a * b).printValues();
		(a / b).printValues();
	}
};


l9_e2::fr l9_e2::fr::operator+ (fr b) {

	return *new fr( numarator * multiple(numitor, b.numitor) /numitor + b.numarator * multiple(numitor, b.numitor) /b.numitor, multiple(numitor, b.numitor));
}

l9_e2::fr l9_e2::fr::operator- (fr b) {
	return *new fr(numarator * multiple(numitor, b.numitor) / numitor - b.numarator * multiple(numitor, b.numitor) / b.numitor, multiple(numitor, b.numitor));
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