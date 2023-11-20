#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct fish
{
    string nameoffish;

    static bool is_valid_name_fish(const string& name);

    static vector<fish> read_fish(istream& ist);

};
