#include "sea_additional.h"
#include "fish_additional.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool fish::is_valid_name_fish(const std::string& name)
{
    for (int i = 0; i < name.size(); i++)
    {
        if (!(isalpha(name[i])))
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}

 vector<fish> fish::read_fish(istream& ist)
{
    fish object1;
    string buf;
    int i = 1;
    string nameofffish;
    getline(ist, buf);
    if (buf.empty()) {
        return {};
    }
    try
    {
        if (!fish::is_valid_name_fish(buf))
        {
            throw runtime_error("Некорректные данные!");
        }
    }
    catch (const exception& ex)
    {
        cout << ex.what() << endl;
    }
    vector<fish> vect1;
    vector<fish> vect;
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
            if (fish::is_valid_name_fish(nameofffish))
            {
                object1.nameoffish = nameofffish;
                vect1.push_back(object1);
            }
            else
            {
                cout << "Неккоректные данные! Проверьте вводимые поля рыб!";
                return vect;
            }
        }
        else
        {
            continue;
        }
    }
    vector<fish> result;
    for (size_t i = 0; i < vect1.size(); ++i) {
        if (!vect1[i].nameoffish.empty()) {
            result.push_back(vect1[i]);
        }
    }
    return result;
}
