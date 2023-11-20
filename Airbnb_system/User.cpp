#include "User.h"
User::User()
{
	age = 0;
	email = "";
	full_name = "";
	gender = "";
	nationality = "";
	password = "";
	type="";
}
void User::set_age(int age)
{
	this->age = age;
}
void User::set_email(string email)
{
	this->email = email;
}
void User::set_full_name(string full_name)
{
	this->full_name = full_name;
}
void User::set_gender(string gender)
{
	if (gender == "m" || gender == "M" || gender == "Male")
		this->gender = "Male";

	else
		this->gender = "Female";
}

void User::set_nationality(string nationality)
{
	this->nationality = nationality;
}
void User::set_password(string password)
{
	this->password = password;

}
void User::set_type(string type)
{
	{
		if (type == "h" || type == "H" || type == "Host")
			this->type = "Host";
		else if (type == "t" || type == "T" || type == "Traveller")
			this->type = "Traveller";
		else
			this->type = "Admin";
	}
}
int User::get_age()
{
	return age;
}
string User::get_full_name()
{
	return full_name;
}
string User::get_email()
{
	return email;
}
string User::get_gender()
{
	return gender;
}
string User::get_nationality()
{
	return nationality;
}
string User::get_password()
{
	return password;
}
string User::get_type()
{
	return type;
}


void User::Read(string& user_name, string& email) {
	set_full_name(user_name);
	Valid v;
	string str;
	char x = '0';
	set_email(email);
	cout << "Enter password: ";
	cin >> str;
	set_password(str);
	cout << "Enter your nationality: ";
	cin >> str;
	set_nationality(str);
	cout << "Enter your gender (m/f): ";
	cin >> str;
	v.gender_validation(str);
	set_gender(str);
	cout << "Enter your age: ";
	cin >> str;
	v.valid_number(str, 'i');
	set_age(stoi(str));
	cout << "Enter ur type (H/T):";
	cin >> str;
	v.type_validation(str);
	set_type(str);
}
User::~User() {
}