#pragma once
#include <iostream>
#include <vector>
#include "fish_additional.h"

using namespace std;

struct sea
{
    string name;

    double depth;

    double salinity;

    vector<sea> vect1;

    vector<fish> name_of_fish;

    static vector<sea> read_sea(istream& ist);

    static string read_name_of_sea(istream& ist);

    static void write(vector<sea> vect, ostream& out);

    static vector<sea> initialization(istream& ist);
};
