#include"doctor.h"
#include <cctype>
#include"patient.h"
#include "person.h"
using namespace std;
#include <iostream>
#include <vector>
#include<fstream>
#include <sstream>
#include "appointment.h"



int main()
{
	int choice = 0;
	string patientName1, doctorName ,p_name, gender, patient_phone, address, illness,
		doc_name, doc_gender, doc_phone, specialty, available_days, working_hours, date, time;
	int id_doctor, id_patient, price, p_age, doc_age, patient_id, doc_id;
	vector<doctor>doctors;
	ifstream docFile("doctors.txt");
	if (docFile.is_open()) {
		string line;
		while (getline(docFile, line)) {
			stringstream ss(line);
			string doc_name, gender, doc_phone, specialty, available_days, working_hours;
			int doc_age, doc_id, price;

			getline(ss, doc_name, ',');
			ss >> doc_age; ss.ignore();
			getline(ss, gender, ',');
			getline(ss, doc_phone, ',');
			getline(ss, specialty, ',');
			ss >> doc_id; ss.ignore();
			ss >> price; ss.ignore();
			getline(ss, available_days, ',');
			getline(ss, working_hours, '\n');

			doctor d(doc_name, doc_age, gender, doc_phone, specialty, doc_id, price, available_days, working_hours);
			doctors.push_back(d);
		}
		docFile.close();
	}
	vector<patient>patients;
	ifstream patFile("patients.txt");
	if (patFile.is_open()) {
		string line;
		while (getline(patFile, line)) {
			stringstream ss(line);
			string p_name, gender, phone, address, illness;
			string temp;
			int p_age, patient_id;

			getline(ss, p_name, ',');

			getline(ss, temp, ',');
			p_age = stoi(temp);

			getline(ss, gender, ',');
			getline(ss, phone, ',');

			getline(ss, temp, ',');
			patient_id = stoi(temp);

			getline(ss, address, ',');
			getline(ss, illness, ',');

			getline(ss, temp);

			patient p(p_name ,p_age, gender, phone, patient_id, address, illness);
			patients.push_back(p);
		}
		patFile.close();
	}
	vector< appointment> appointments;
	ifstream appFile("appointments.txt");
	if (appFile.is_open()) {
		string line;
		while (getline(appFile, line)) {
			stringstream ss(line);
			string patientName1, doctorName, date, time;
			int id_doctor, id_patient;

			getline(ss, patientName1, ',');
			getline(ss, doctorName, ',');
			ss >> id_doctor; ss.ignore();
			ss >> id_patient; ss.ignore();
			getline(ss, date, ',');
			getline(ss, time, '\n');

			appointment ap(patientName1, doctorName, id_doctor, id_patient, date, time);
			appointments.push_back(ap);
		}
		appFile.close();
	}

	cout << "========================================\n";
	cout << "   Welcome to the Smart Clinic System   \n";
	cout << "  Your health is our top priority!      \n";
	cout << "========================================\n\n";
	for (int i = 1; i <= 100; i++)
	{
		cout << "1. Register a new Doctor\n";
		cout << "2. Register a new Patient\n";
		cout << "3. Register a new appointment \n";
		cout << "4. View Doctor List\n";
		cout << "5. View Patient List\n";
		cout << "6. View appointment List\n";
		cout << "7. search about appointment \n";
		cout << "8. search about doctor \n";
		cout << "9. search about patient \n";
		cout << "10. Exit\n";
		cout << "Please choose an option to get started:\n";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			cout << "Enter doctor's name: ";
			getline(cin >> ws, doc_name);
		
			while (true) {
				try {
					string temp_age;
					cout << "Enter doctor's age: ";
					cin >> temp_age;

					for (char c : temp_age) {
						if (!isdigit(c)) {
							throw "invalid input";
						}
					}

					doc_age = stoi(temp_age);
					break;
				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "please enter  doctor age correctly\n";
				}
			}



			cout << "Enter doctor's gender: ";
			getline(cin >> ws, gender);

			while (true) {
				try {
					cout << "Enter doctor's phone number: ";
					cin >> doc_phone;

					if (doc_phone.length() != 11) {
						throw "invalid input";
					}
					for (char c : doc_phone)
					{
						if (!isdigit(c))
						{
							throw "invalid input";
						}
					}

					break;
				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "please enter phone number correctly\n";
				}
			}



			while (true) {
				try {
					string temp_id;
					cout << "Enter doctor_id: ";
					cin >> temp_id;

					for (char i : temp_id)
					{
						if (!isdigit(i))
						{
							throw string("invalid input: ID must be digits only");
						}
					}

					int new_id = stoi(temp_id); 

					for (doctor id : doctors)
					{
						if (new_id == id.get_doctor_id())
						{
							throw string("invalid input: this ID is already registered");
						}
					}

					doc_id = new_id;
					break;
				}
				catch (string mistake)
				{
					cout << mistake << "\n";
					cout << "please enter a different ID.\n";
				}
			}


			cout << "Enter doctor's specialization: ";
			getline(cin >> ws, specialty);

			while (true)
			{
				try
				{
					string g;
					cout << "Enter doctor's visit price: ";
					cin >> g;

					for (char s : g)
					{
						if (!isdigit(s))
						{
							throw "invalid input";
						}
					}

					price = stoi(g);
					break;
				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "price should contain only digits\n";
				}
			}


			cout << "Enter available days: ";
			getline(cin >> ws, available_days);

			cout << "Enter working hours: ";
			getline(cin >> ws, working_hours);

			doctor d1(doc_name, doc_age, gender, doc_phone, specialty, doc_id, price, available_days, working_hours);
			doctors.push_back(d1);
			cout << "Doctor registered successfully!\n\n\n";

			ofstream docFile("doctors.txt", ios::app);
			if (docFile.is_open()) {
				docFile << doc_name << "," << doc_age << "," << gender << "," << doc_phone << ","
					<< specialty << "," << doc_id << "," << price << "," << available_days << "," << working_hours << "\n";
				docFile.close();
				cout << "Doctor saved to file successfully!\n";
			}
			else {
				cout << "Error: Couldn't open doctors.txt\n";
			}


			break;
		}
		case 2:
		{
			cout << "Enter patient's name: ";
			getline(cin >> ws, p_name);


			while (true) {
				try {
					string temp_age;
					cout << "Enter doctor's patient age: ";
					cin >> temp_age;

					for (char c : temp_age) {
						if (!isdigit(c)) {
							throw "invalid input";
						}
					}

					p_age = stoi(temp_age);
					break;
				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "please enter patient age correctly\n";
				}
			}

			cout << "Enter patient's gender: ";
			getline(cin >> ws, gender);
			while (true) {
				try {
					cout << "Enter patient's phone number: ";
					cin >> patient_phone;

					if (patient_phone.length() != 11) {
						throw "invalid input";
					}
					for (char c : patient_phone)
					{
						if (!isdigit(c))
						{
							throw "invalid input";
						}
					}

					break;
				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "please enter phone number correctly\n";
				}
			}


			while (true) {
				try {
					string temp_id;
					cout << "Enter patient_id: ";
					cin >> temp_id;

					for (char i : temp_id)
					{
						if (!isdigit(i))
						{
							throw string("invalid input: ID must be digits only");
						}
					}

					int new_id = stoi(temp_id);

					for (patient id : patients)
					{
						if (new_id == id.get_patient_id())
						{
							throw string("invalid input: this ID is already registered");
						}
					}

					patient_id = new_id;
					break;
				}
				catch (string mistake)
				{
					cout << mistake << "\n";
					cout << "please enter a different ID.\n";
				}
			}

			cout << "Enter address: ";
			getline(cin >> ws, address);

			cout << "Enter illness description: ";
			getline(cin >> ws, illness);



			patient p1(p_name, p_age, gender, patient_phone, patient_id, address, illness);
			patients.push_back(p1);
			cout << "Patient registered successfully!\n";
			ofstream patFile("patients.txt", ios::app);
			if (patFile.is_open()) {
				patFile << p_name << "," << p_age << "," << gender << "," << patient_phone << ","
					<< patient_id << "," << address << "," << illness << "\n";
				patFile.close();
				cout << "Patient saved to file successfully!\n";
			}
			else {
				cout << "Error: Couldn't open patients.txt\n";
			}

			break;
		}
		case 3:
		{
			cout << "enter your name please\n";
			getline(cin >> ws, p_name);
			cout << "enter doctor name please\n";
			getline(cin >> ws, doc_name);
			while (true)
			{
				try {
					string id;
					cout << "Enter patient ID: ";
					cin >> id;
						for (char i : id)
						{
							if (!isdigit(i))
							{
								throw "invalid input";
							}

						}
						id_patient = stoi(id);
						break;

				}
				catch (const char* mistake)
				{
					cout << mistake << "\n";
					cout << "id should have only digits\n";
				}
			}
			
			int k = 0;
			for (int i = 0; i < patients.size(); i++)
			{
				if (id_patient == patients[i].get_patient_id())
				{
					k += 1;
					break;
				}

			}
			if (k == 1)
			{
				int c = 0;
				while (c==0)
				{
					try {
						
						while (true)
						{
							try {
								string id;
								cout << "Enter doctor ID: ";
								cin >> id;
								for (char i : id)
								{
									if (!isdigit(i))
									{
										throw "invalid input";
									}
								}
								id_doctor = stoi(id);
								break;
							}
							catch (const char* mistake)
							{
								cout << mistake << "\n";
								cout << "id doctor should contain only digits\n";
							}
						
						}
						
						for (int i = 0; i < doctors.size(); i++)
						{
							if (id_doctor == doctors[i].get_doctor_id())
							{
								cout << "enter data visit\n";
								getline(cin >> ws, date);
								cout << "enter time visit\n";
								getline(cin >> ws, time);
								appointment ap1(p_name, doc_name, id_doctor, id_patient, date, time);
								appointments.push_back(ap1);
								cout << "appointment registered successfully!\n\n\n";
								ofstream docFile("appointments.txt", ios::app);
								if (docFile.is_open())
								{
									docFile << p_name << "," << doc_name << "," << id_doctor << "," << id_patient << ","
										<< date << "," << time << "\n";
									docFile.close();
									cout << "appointment saved to file successfully!\n";

								}

								else 
								{
									cout << "Error: Couldn't open appointment.txt\n";
								}
								c += 1;
								break;
							}
				
						}

						if (c == 0)
						{
							throw "inavlid input";

						}


					}
					catch (const char* mistake)
					{
						cout << mistake << "\n";
						cout << "doctor id not found please enter another id\n";
					}
				}
		
				
			}

			else
			{
				cout << "patient_id not found\n";
				cout << "please regester patient data\n";
				break;
			}
			break;
		}
		case 4: {
			if (doctors.empty())
			{
				cout << "No doctors registered yet.\n";
				break;
			}
			else
			{
				cout << "Available Doctors:\n\n";
				for (int i = 0; i < doctors.size(); i++)
				{
					doctors[i].show_info();
					cout << "\n\n";
				}
			}
			break;
		}
		case 5:
		{
			if (patients.empty())
			{
				cout << "No patients registered yet.\n";
				break;
			}
			else
			{
				cout << "Available patients:\n";
				for (int i = 0; i < patients.size(); i++)
				{
					patients[i].show_info();
				}
			}
			break;
		}
		case 6: {
			if (appointments.empty())
			{
				cout << "No appointments registered yet.\n";
				break;

			}
			{
				for (int i = 0; i < appointments.size(); i++)
				{
					appointments[i].show_appoint();
				}
			}
			break;

		}
		case 7: {
			int choice2;
			cout << "enter your choice\n";
			cout << "1.search as a doctor\n";
			cout << "2.search as a patient\n";
			cin >> choice2;
			switch (choice2)
			{
			case 1: {
				int key;
				cout << "Enter your ID:\n";
				cin >> key;
				int c = 0;

				for (int i = 0; i < appointments.size(); i++) {
					if (key == appointments[i].get_id_doctor()) {
						appointments[i].show_appoint();

						for (int k = 0; k < patients.size(); k++) {
							if (appointments[i].get_id_patient() == patients[k].get_patient_id()) {
								cout << "Patient Data:\n";
								patients[k].show_info();
								c++;
								break;
							}
						}
					}
				}

				if (c == 0) {
					cout << "No appointments found.\n";
				}
				break;
			}

			case 2:
			{
				int key;
				cout << "enter your id\n";
				cin >> key;
				int p = 0;
				for (int i = 0; i < appointments.size(); i++)
				{
					if (key == appointments[i].get_id_patient())
					{
						appointments[i].show_appoint();
						p += 1;
					}
					
				}
				if (p == 0)
				{
					cout << "no appointments for this patient\n";
				}
				break;

			}
			}
			break;

		}
		case 8:
		{
			int key;
			cout << "doctor,enter your id please \n";
			cin >> key;
			int n = 0;
			for (int i = 0; i < doctors.size(); i++)
			{
				if (key == doctors[i].get_doctor_id())
				{
					doctors[i].show_info();
					n += 1;
					break;

				}
			
			}
			if (n == 0)
			{
				cout << "not found\n";
			}
			break;

		}
		case 9: {
			int key;
			cout << "enter your id\n";
			cin >> key;
			int d = 0;
			for (int i = 0; i < patients.size(); i++)
			{
				if (key == patients[i].get_patient_id())
				{
					patients[i].show_info();
					d += 1;
					break;
				}

			}
			if (d == 0)
			{
				cout << "not found\n";
			}
			break;

		}
		case 10:
			break;
		default:
			cout << "Invalid option. Please choose a number between 1 and 8.\n";
			break;

		}
		}

	}
	

