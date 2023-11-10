#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct fish
{
    string nameoffish;
};

struct sea
{
    string name;

    double depth;

    double salinity;

    vector<fish> name_of_fish;
    
    vector<sea> vect;

    static vector<sea> read_sea(istream& ist);
    
    static vector<fish> read_fish(istream& ist);
    
    static string read_name_of_sea(istream& ist);
    
    void write(vector<sea> vect,ostream& out, int k);
    
    void output(vector<sea> vect,ostream& out);  
    
    vector<sea> initialization(istream& ist, sea object);
};



