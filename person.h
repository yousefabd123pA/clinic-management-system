#include <string>
using namespace std;
#pragma once
class person
{
protected:
    string name;
    int age;
    string gender;
    string phone_num;
public:
    person();
    person(string n, int a, string g, string ph);
    void show_info();


};
