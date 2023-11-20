#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include "Valid.h"
using namespace std;
class User
{
private:
	string full_name;
	string email;
	string password;
	string nationality;
	string gender;
	int  age;
	string type;
public:
	User();
	void set_full_name(string);
	void set_email(string);
	void set_password(string);
	void set_nationality(string);
	void set_gender(string);
	void set_age(int);
	void set_type(string);
	/*------------------------------*/
	string get_full_name();
	string get_email();
	string get_password();
	string get_nationality();
	string get_gender();
	int  get_age();
	string get_type();
	/*-------------------------------*/
	void Read(string&, string&);
	~User();
	/*-------------------------------*/
};

