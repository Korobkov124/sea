#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


vector<sea> sea::read_sea(istream& ist)
{
	sea object;
	fish object1;
	vector <sea> vect; vector <fish> vect1;
	while (!ist.eof())
	{
		object.name = object.read_name_of_sea(ist);
		ist >> object.depth >> object.salinity;
		object.name_of_fish = read_fish(ist);
		vect.push_back(object);
	}
	return vect;
}


string sea::read_name_of_sea(istream& ist)
{
	string pod;
	int chet = 0;
	ist >> pod;
	int len = pod.length();
	string nos;
	int i = 0;
	while (chet != 2)
	{
		if (pod[i] == '\0')
		{
			nos += ' ';
			ist >> pod;
			chet = 1;
			i = 0;
		}
		if (pod[i] == '\"')
		{
			chet++;
			i++;
			continue;
		}
		if (chet == 1)
		{
			nos += pod[i];
			i++;
		}
	}
	chet = 0;
	return nos;
}

vector<fish> sea::read_fish(istream& ist)
{
	fish object1;
	string buf;	
	int i = 1;
	string nameofffish;
	getline(ist, buf);
	if (buf.empty())
		return {};
	vector<fish> vect1;
	while (buf[i])
	{
		if (buf[i] == ' ')
		{
			object1.nameoffish = nameofffish;
			vect1.push_back(object1);
			i++;
			nameofffish = "";
		}
		nameofffish += buf[i];
		i++;
		if (i + 1 == buf.length())
		{
			nameofffish += buf[i];
			object1.nameoffish = nameofffish;
			vect1.push_back(object1);
		}
	}
	std::vector<fish> result;
	for (size_t i = 0; i < vect1.size(); ++i) {
		if (!vect1[i].nameoffish.empty()) {
			result.push_back(vect1[i]);
		}
	}
	return result;
}

void sea::write(vector<sea> vect, std::ostream& out, int k)
{
	sea object1 = vect[k];
	out << object1.name << " " << object1.depth << " " << object1.salinity << " ";

	for (int i = 0; i < object1.name_of_fish.size(); i++)
	{
		out << object1.name_of_fish[i].nameoffish  << " ";
	}
	out << endl;
}
void sea::output(vector<sea> vect, ostream& out)
{
	size_t size = vect.size();
	for (int k = 0; k < size; k++)
	{
		vect[k].name_of_fish;
		write(vect, out, k);
	}
}
vector<sea> sea::initialization(istream& ist, sea object)
{
	vector<sea> vect1;
	vect1 = object.read_sea(ist);
	return vect1;
}
