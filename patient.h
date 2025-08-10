#pragma once
using namespace std;
#include <string>
#include "person.h"
class patient :
    public person
{
private:
    int patient_id;
    string address;
    string illness;
public:
    patient(string n, int a, string g, string ph, int p_id, string ad, string ill);
    void set_patient_id(int pa_id);
    void set_address(string add);
    void set_illness(string ill);
    int get_patient_id();
    string get_address();
    string get_illness();

    void show_info();



}; 