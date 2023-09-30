#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include "Header.h"


using namespace std;

int main()
{
	sea test;
	vector<sea> vect;
	setlocale(LC_ALL, "ru");
	ifstream txt("txt.txt");
	if (txt.is_open()) {cout << "Файл открыт!\n";}
	else {cout << "WARNING! Файл не открылся!!!\n";}
	test.initialization(txt, test, vect);
	return 0;
}