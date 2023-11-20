#include "Airbnb.h"
#include<sstream>
#include<fstream>
Airbnb::Airbnb()
{
	load_place_data();
	load_user_data();
}

void Airbnb::load_user_data() {
	fstream file;
	file.open("userData.txt", ios::in);
	string str;
	while (getline(file, str))
	{
		vector<string>userData;
		User* u = new User;
		istringstream ss(str);
		string word;
		while (getline(ss, word, '|'))
			userData.push_back(word);
		u->set_full_name(userData[0]);
		u->set_email(userData[1]);
		u->set_age(stoi(userData[2]));
		u->set_gender(userData[3]);
		u->set_nationality(userData[4]);
		u->set_password(userData[5]);
		u->set_type(userData[6]);
		User_Manager::users_list[make_pair(u->get_full_name(), u->get_email())] = u;
	}
	file.close();
}

void Airbnb::load_place_data() {
	fstream f;
	f.open("places.txt", ios::in);
	string str;
	while (getline(f, str))
	{
		vector<string>aa;
		Place* p = new Place;
		istringstream ss(str);
		string word;
		while (getline(ss, word, '|'))
			aa.push_back(word);
		p->set_city(aa[0]);
		p->set_duration(stoi(aa[1]));
		p->set_start_date(aa[2]);
		p->set_end_date(aa[3]);
		p->set_owner_gmail(aa[4]);
		p->set_price(stof(aa[5]));
		Place_Manager::place_list_[p->get_city()].push_back(p);
	}
	f.close();
}

void Airbnb::flow()
{
	if (ugr.get_current_user()->get_type() == "Host")
		AS.host_function();
	else if (ugr.get_current_user()->get_type() == "Traveller")
		AS.traveller_function();
	else if (ugr.get_current_user()->get_type() == "Admin")
		AS.admin_function();
}

void Airbnb::access_system(int c)
{
	switch (c)
	{
	case 1:
		ugr.sign_up();
		break;
	case 2:
	{
	  if (ugr.login())
		flow();
	 break;
	}
	case 3:
		break;
	default:
		cout << "invalid selection!\n";
	}
}

void Airbnb::run()
{
	v.header_decortion("Welcome TO Airbnb System", 6);//header with yellow color
	string ch;
	do
	{
		cout << "1-->Sign up\n2-->Login\n3-->Log out\nYour choice: ";
		cin >> ch;
		v.valid_number(ch, 'i');
		access_system(stoi(ch));
	} while (stoi(ch) != 3);
	cout << "\n\n\t\t\t\t\tThank you for using our app\n";
}
void Airbnb::store_place_data() {
	ofstream f;
	f.open("places.txt", ios::out | ofstream::trunc);
	for (auto place : Place_Manager::place_list_)
	{
		for (int i = 0; i < place.second.size(); i++)
		{
			f << place.second[i]->get_city() << "|" << place.second[i]->get_duration() << "|" << place.second[i]->get_start_date() << "|" << place.second[i]->get_end_date() << "|" << place.second[i]->get_owner_gmail() << "|" << place.second[i]->get_price() << endl;
		}
	}
	f.close();
}
void Airbnb::store_user_data() {
	ofstream file;
	file.open("userData.txt", ios::out | ofstream::trunc);
	for (auto u : User_Manager::users_list)
	{
		file << u.first.first << "|" << u.first.second << "|" << u.second->get_age() << "|" << u.second->get_gender() << "|" << u.second->get_nationality() << "|" << u.second->get_password() << "|" << u.second->get_type() << endl;
	}
	file.close();
}
Airbnb::~Airbnb() {
	store_place_data();
	store_user_data();
}