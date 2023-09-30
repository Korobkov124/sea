#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void sea::read(ifstream& ist, vector <sea> vect, sea object)
{
	while (!ist.eof())
	{
		ist >> object.name >> object.depth >> object.salinity;
		vect.push_back(object);
	}
	output(vect, cout);
}

void sea::write(vector<sea> vect, std::ostream& out, int k)
{
	sea object1 = vect[k];
	out << object1.name << " " << object1.depth << " " << object1.salinity << endl;;
}
void sea::output(vector<sea> vect, ostream& out)
{
	size_t size = vect.size();
	for (int k = 0; k < size; k++)
	{
		write(vect, out, k);
	}
}
void sea::initialization(ifstream& ist, sea object, vector<sea>vect)
{
	object.read(ist, vect, object);
}

