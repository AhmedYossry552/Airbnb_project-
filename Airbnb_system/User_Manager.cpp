#include "User_Manager.h"
User_Manager::User_Manager()
{

}
void User_Manager::sign_up()
{
	string user_name, email, ch = "y";
	while (ch == "Y" || ch == "y")
	{
		cout << "Enter user name: ";
		cin >> user_name;
		cout << "Enter your Email address : ";
		cin >> email;
		v.email_valid(email);
		if (users_list.count(make_pair(user_name, email)))
		{
			cout << "Already used. Try again\n";
			cout << "Do you want to Try again? (y/n):";
			cin >> ch;
			v.confirm_validation(ch);
		}
		else
			break;
	}
	current_user = new User();
	current_user->Read(user_name, email);
	users_list[make_pair(current_user->get_full_name(), current_user->get_email())] = current_user;
}
User* owner_user;
bool User_Manager::login()
{
	string op = "";
	bool check = false;
	do
	{
		string user_name, pass, email;
		cout << "Enter user name: ";
		cin >> user_name;
		cout << "Enter email address: ";
		cin >> email;
		cout << "Enter password: ";
		cin >> pass;
		if (!users_list.count(make_pair(user_name, email))) {
			cout << "\nIncorrect data\nDo you want to try again(y/n)?:";
			cin >> op;
			v.confirm_validation(op);
			continue;
		}
		User* user_exist = users_list.find(make_pair(user_name, email))->second;
		if (pass != user_exist->get_password()) {
			cout << "\nIncorrect data\nDo you want to try again(y/n)?:";
			cin >> op;
			v.confirm_validation(op);
			continue;
		}
		check = true;
		current_user = user_exist;
		owner_user = user_exist;
	} while ((op == "Y" || op == "y") && !check);
	return check;
}
void User_Manager::display_users() {
	int num = 1;
	for (auto u : users_list)
	{
		if (u.first.first == "admin") {
			continue;
		}
		else
		{
			cout << "user number: " << num << ") ";
			cout << "user name: " << u.first.first << "\n" << "user email: " << u.first.second << "\n" << "user age: " << u.second->get_age() << "\n" << "user gender: " << u.second->get_gender() << "\n" << "user nationality:" << u.second->get_nationality() << "\n" << "user tyep: " << u.second->get_type() <<"\n\n";
			num++;
		}
	}
}
void User_Manager::main_view()
{
	string c = "";
	do
	{
		cout << "1-->grouping useres view\n3-->Back\nyour choice:";
		cin >> c;
		v.valid_number(c, 'i');
		switch (stoi(c))
		{
		case 1:
			break;
		case 2:
			view_users();
			break;
		case 3:
			break;
		default:
			cout << "Invalid selection\n";

		}

	} while (stoi(c) != 3);
}
void User_Manager::access_users() {

	string c = "";
	do
	{

		cout << "1-->view all user in system\n";
		cout << "2-->view with spacific filter\n";//choose which view(1- display all then delete ,2-view) then delete   view all users then delete 
		// view for spacfic opetion 
		cout << "3-->Back\n";
		cin >> c;
		v.valid_number(c, 'i');
		switch (stoi(c))
		{
		case 1:
			display_users();
			break;
		case 2:
			view_users();
			break;
		case 3:
			break;
		default:
			cout << "invalid";
		}
	} while (stoi(c) != 3);
}

void User_Manager::view_users() {
	string ch;
	do
	{
		cout << "1-->View With Type\n";
		cout << "2-->View With Gender\n";
		cout << "3-->View With Nationalty\n";
		cout << "4-- > Back\nYour choice : ";
		cin >> ch;
		v.valid_number(ch, 'i');
		switch (stoi(ch))
		{
		case 1:
			view_type();
			break;
		case 2:
			view_gender();
			break;
		case 3:
			view_nationalty();
			break;
		case 4:
			break;
		default:
			cout << "Enter valid number!!\n";
		}
	} while (stoi(ch) != 4);
}
void User_Manager::view_type() {
	string c;
	cout << "Select your type h or t:";
	cin >> c;
	v.type_validation(c);
	if (c == "h" || c == "H")
		c = "Host";
	else
		c = "Traveller";
	int n = 1;
	for (auto u : users_list) {

		if (u.second->get_type() == c && u.first.first != "admin") {
			cout << n << ")" << "user name: " << u.first.first << "\n" << "user email: " << u.first.second << "\n" << "user age: " << u.second->get_age() << "\n" << "user gender: " << u.second->get_gender() << "\n" << "user nationality:" << u.second->get_nationality() << "\n" << "user tyep: " << u.second->get_type() <<"\n\n";
			n++;
		}
	}
}
void User_Manager::view_gender() {
	string c;
	cout << "Select your gender m or f:";
	cin >> c;
	v.gender_validation(c);
	if (c == "M" || c == "m")
		c = "Male";
	else
		c = "Female";
	int n = 1;
	for (auto u : users_list) {

		if (u.second->get_gender() == c && u.first.first != "admin") {
			cout << n << ")" << "user name: " << u.first.first << "\n" << "user email: " << u.first.second << "\n" << "user age: " << u.second->get_age() << "\n" << "user gender: " << u.second->get_gender() << "\n" << "user nationality:" << u.second->get_nationality() << "\n" << "user tyep: " << u.second->get_type() << endl;
			n++;
		}
	}
	if (n == 1) {
		cout << "no user match with your selection\n";
	}
}
void User_Manager::view_nationalty() {
	int n = 1;
	string c;
	cout << "enter the natonalty to view list:";
	cin >> c;
	for (auto u : users_list) {

		if (u.second->get_nationality() == c&&u.first.first!="admin") {
			cout << n << ")" << "user name: " << u.first.first << "\n" << "user email: " << u.first.second << "\n" << "user age: " << u.second->get_age() << "\n" << "user gender: " << u.second->get_gender() << "\n" << "user nationality:" << u.second->get_nationality() << "\n" << "user tyep: " << u.second->get_type() << endl;
			n++;
		}
	}
	if (n == 1) {
		cout << "No user match with this nationality\n";
	}
}
User* User_Manager::get_current_user()
{
	return owner_user;
}
User_Manager::~User_Manager() {
	for (auto u : users_list) {
		delete u.second;
	}
	users_list.clear();
}