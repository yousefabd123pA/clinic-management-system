#include "doctor.h"
#include "patient.h"
#include "person.h"
#include <iomanip>
#include "appointment.h"



person::person() :name("unknown"), age(0), gender("unknown"), phone_num("unknown")
{
}

person::person(string n, int a, string g, string ph) :name(n), age(a), gender(g), phone_num(ph)
{
}



void person::show_info()
{
  
    cout << left << setw(20) << "Name:" << name << "\n";
    cout << left << setw(20) << "Age:" << age << "\n";
    cout << left << setw(20) << "Gender:" << gender << "\n";
    cout << left << setw(20) << "Phone:" << phone_num << "\n";
}

doctor::doctor(string na, int ag, string ge, string ph, string spe, int _id, int pr, string day, string work_h) :person(na, ag, ge, ph)
{
    specialization = spe;
    doctor_id = _id;
    price_of_examination = pr;
    available_days = day;
    working_hours = work_h;

}

void doctor::set_specialization(string sp)
{
    specialization = sp;
}

void doctor::set_doctor_id(int id)
{
    doctor_id = id;
}

void doctor::set_price_of_examination(int price)
{
    price_of_examination = price;
}

void doctor::set_available_days(string days)
{
    available_days = days;
}

void doctor::set_working_hours(string whour)
{
    working_hours = whour;
}

string doctor::get_specialization()
{
    return specialization;
}

int doctor::get_doctor_id()
{
    return doctor_id;
}

int doctor::get_price_of_examination()
{
    return price_of_examination;
}

string doctor::get_available_days()
{
    return available_days;
}

string doctor::get_working_hours()
{
    return working_hours;
}
void doctor::show_info()
{
    cout << "\n============================================\n";
    cout << "        \x1B[32m\u2714 Doctor Information \x1B[0m\n";
    cout << "============================================\n";
    person::show_info();
    cout << left << setw(20) << "\U0001FA7A Specialty:" << specialization << "\n";
    cout << left << setw(20) << "\U0001F194 ID:" << doctor_id << "\n";
    cout << left << setw(20) << "\U0001F4B0 Price:" << price_of_examination << " EGP\n";
    cout << left << setw(20) << "\U0001F4C5 Days:" << available_days << "\n";
    cout << left << setw(20) << "\u23F0 Hours:" << working_hours << "\n";
    cout << "============================================\n\n";
}

patient::patient(string n, int a, string g, string ph, int p_id, string ad, string ill) :person(n, a, g, ph)
{
    patient_id = p_id;
    address = ad;
    illness = ill;
}



void patient::set_patient_id(int pa_id)
{
    patient_id = pa_id;

}

void patient::set_address(string add)
{
    address = add;
}

void patient::set_illness(string ill)
{
    illness = ill;
}



int patient::get_patient_id()
{
    return patient_id;
}

string patient::get_address()
{
    return address;
}

string patient::get_illness()
{
    return illness;
}


void patient::show_info()
{

    cout << "\n--------------------------------------------\n";
    cout << "\U0001F491 Patient Information\n";
    cout << "--------------------------------------------\n";
    person::show_info();
    cout << left << setw(20) << "Patient ID:" << patient_id << "\n";
    cout << left << setw(20) << "Address:" << address << "\n";
    cout << left << setw(20) << "Illness:" << illness << "\n";
    cout << "--------------------------------------------\n\n";
}

appointment::appointment(string pname, string dname, int id_d, int id_p, string date2, string time2) :patientName (pname), doctorName(dname)
, id_doctor(id_d), id_patient(id_p), date(date2), time(time2)
{
}

void appointment::set_id_doctor(int id)
{
    id = id_doctor;
}

void appointment::set_id_patient(int id)
{
    id = id_patient;
}

void appointment::set_date(string date1)
{
    date = date1;
}

void appointment::set_time(string time1)
{
    time1 = time;
}

string appointment::get_date()
{
    return date;
}

string appointment::get_time()
{
    return time;
}

int appointment::get_id_doctor()
{
    return id_doctor;
}

int appointment::get_id_patient()
{
    return id_patient;
}



void appointment::show_appoint() {
    cout << "\n=====================================\n";
    cout << "       \x1B[36m📅 Appointment Details \x1B[0m\n";
    cout << "=====================================\n";
    cout << left << setw(20) << "👤 Patient:" << patientName << " (ID: " << id_patient << ")\n";
    cout << left << setw(20) << "🧑‍⚕️ Doctor:" << doctorName << " (ID: " << id_doctor << ")\n";
    cout << left << setw(20) << "📆 Date:" << date << "\n";
    cout << left << setw(20) << "⏰ Time:" << time << "\n";
    cout << "=====================================\n\n";
}


