#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include "Header.h"


using namespace std;

int main()
{
	sea test;
	string path = "txt.txt";
	setlocale(LC_ALL, "ru");
	ifstream txt;
	txt.exceptions(ifstream::badbit | ifstream::failbit);
	try
	{
		txt.open(path);
	}
	catch (const std::exception& ex)
	{
		cout << "Ошибка открытия файла!" << endl;
		cout << ex.what() << endl;
		return 0;
	}
	vector<sea> vect;
	vect = test.initialization(txt, test);
	test.output(vect, cout);
	return 0;
}
