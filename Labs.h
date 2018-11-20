#pragma once

#include "Lab_1.h"
#include "Lab_2.h"
#include "Lab_3.h"
#include "Lab_4.h"
#include "Lab_5.h"
#include "Lab_6.h"
#include "Lab_7.h"
#include "Lab_8.h"
#include "Lab_9.h"

void chooseExercise() {
	string choice;

	cout << "Please enter the desired exercise lX_eY\tX = laboratory nummber, Y exercise number \n\n";

	cin >> choice;
	system("cls");

	// Switch is not compatible with strings.. Ugh >-<

	if (choice == "l1_e2")			l1_e2 x;
	else if (choice == "l1_e3")		l1_e3 x;
	else if (choice == "l1_e4")		l1_e4 x;
	else if (choice == "l1_e5")		l1_e5 x;

	else if (choice == "l2_e2")		l2_e2 x;
	else if (choice == "l2_e4")		l2_e4 x;

	else if (choice == "l3_e2")		l3_e2 x;
	else if (choice == "l3_e3")		l3_e3::polinom x;
	else if (choice == "l3_e4")		l3_e4::calendar x;
	else if (choice == "l3_e5")		l3_e5::ecuatii x;

	else if (choice == "l4_e2")		l4_e2 x;
	else if (choice == "l4_e3")		l4_e3 x;
	else if (choice == "l4_e4")		l4_e4 x;
	else if (choice == "l4_e5")		l4_e5 x;
	else if (choice == "l4_e6")		l4_e6 x;
	else if (choice == "l4_e7")		l4_e7 x;

	else if (choice == "l5_e2")		l5_e2 x;
	else if (choice == "l5_e3")		l5_e3 x;
	else if (choice == "l5_e4")		l5_e4 x;

	else if (choice == "l6_e1")		l6_e1 x;
	else if (choice == "l6_e2")		l6_e2 x;

	else if (choice == "l7_e1")		l7_e1 x;
	else if (choice == "l7_e2")		l7_e2 x;

	else if (choice == "l8_e1")		l8_e1 x;
	else if (choice == "l8_e2")		l8_e2 x;

	else if (choice == "l9_e1")		l9_e1 x;
	else if (choice == "l9_e2")		l9_e2 x;

	else if (choice == "l3_carte") {
		l3::Carte x("Print si Cersetor", "Mark Twain", "Teora", 150);
		l3::Carte y("Pisica salbatica", "Test", "Idk man", 25);
	}

	else if (choice == "l2_e3" || choice == "l2_e5" || choice == "l2_e6") 
			cout << "\nExercise is working, but only the template has been defined. Open Lab_2.h to see the code\n";

	else	cout << "\nInvalid input. Rerun the program\n";
}
