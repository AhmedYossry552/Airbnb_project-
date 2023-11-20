#pragma warning(disable : 4996)
#include <iostream>
#include<sstream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <ctime>
#include<regex>
#include <Windows.h>
#include <stdio.h>
using namespace std;

class Valid
{
public:
	long long calc_days(int, int, int);
	void add_validation(string&);
	void email_valid(string&);
	void confirm_validation(string&);
	void type_validation(string&);
	void gender_validation(string&);
	bool v_f(string&);
	bool v_i(string&);
	void valid_number(string&, char);
	bool in_date_range(string&, string&, string&, string&);
	void date_validation(string&);
	bool is_date(string&);
	bool is_suitable_date(string&);
	void compare_date(string&, string&);
	bool contains_char(string&);
	void valid_range(int&, int, int);
	const string select_city();
	void header_decortion(string, int);
	void set_color(int);
	void table_decoration(string);
};

