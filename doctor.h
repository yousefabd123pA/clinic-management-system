using namespace std;
#include <string>
#include <iostream>
#include "person.h"
#pragma once


class doctor :
    public person
{

private:
    string specialization;
    int doctor_id;
    int price_of_examination;
    string available_days;
    string working_hours;
public:
    doctor(string na, int ag, string ge, string ph, string spe, int _id, int pr, string day, string work_h);
    void set_specialization(string sp);
    void set_doctor_id(int id);
    void set_price_of_examination(int price);
    void set_available_days(string days);
    void set_working_hours(string whour);
    string get_specialization();
    int get_doctor_id();
    int get_price_of_examination();
    string get_available_days();
    string get_working_hours();
    void show_info();

};

