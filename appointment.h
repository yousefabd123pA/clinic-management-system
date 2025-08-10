#pragma once
#include<string>
using namespace std;
class appointment
{
private:

	int id_doctor;
	int id_patient;
	string patientName;
	string doctorName;
	string date;
	string time;
public:
	appointment( string pname,string dname,int id_d, int id_p, string date2, string time2);
	void set_id_doctor(int id);
	void set_id_patient(int id);
	void set_date(string date1);
	void set_time(string time1);
	string get_date();
	string get_time();
	int get_id_doctor();
	int get_id_patient();
	void show_appoint();


};

