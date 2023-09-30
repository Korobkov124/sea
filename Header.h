#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct sea
{
    string name;

    double depth;

    double salinity;
    
    vector<sea> vect;

    void read(ifstream& ist, vector<sea>, sea object);
    
    void write(vector<sea> vect, ostream& out, int k);
    
    void output(vector<sea> vect, ostream& out);  
    
    void initialization(ifstream& ist, sea object, vector<sea>vect);
};



