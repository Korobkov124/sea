#include "sea_additional.h"
#include "fish_additional.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<sea> sea::read_sea(istream& ist)
{
    sea object;
    vector <sea> vect; vector <fish> vect1;
    while (!ist.eof())
    {
        object.name = object.read_name_of_sea(ist);
        ist >> object.depth >> object.salinity;
        object.name_of_fish = fish::read_fish(ist);
        vect.push_back(object);
    }
    return vect;
}

string sea::read_name_of_sea(istream& ist)
{
    string pod;
    int chet = 0;
    ist >> pod;
    auto len = pod.length();
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

void sea::write(vector<sea> vect, std::ostream& out)
{
    sea object1;
    for (int k = 0; k < vect.size(); k++)
    {
        object1 = vect[k];
        out << object1.name << " " << object1.depth << " " << object1.salinity << " ";
        for (int i = 0; i < object1.name_of_fish.size(); i++)
        {
            out << object1.name_of_fish[i].nameoffish << " ";
        }
        out << endl;
    }
    
}

vector<sea> sea::initialization(istream& ist)
{
    vector<sea> vect1;
    vect1 = sea::read_sea(ist);
    return vect1;
}
