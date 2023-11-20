#include "Place.h";
User_Manager* umgr;
Place::Place()
{
	start_date = "";
	end_date = "";
	duration = 0;
	price = 0.0;
	city = "";
	owner_gmail = "";
}
void Place::set_start_date(string start_date)
{
	this->start_date = start_date;
}
void Place::set_end_date(string end_date)
{
	this->end_date = end_date;
}
void Place::set_duration(int duration)
{
	this->duration = duration;
}
void Place::set_price(float price)
{
	this->price = price;
}
void Place::set_city(string city)
{
	this->city = city;
}
void Place::set_owner_gmail(string owner_gmail)
{
	this->owner_gmail = owner_gmail;
}


string Place::get_start_date()
{
	return start_date;
}
string Place::get_end_date()
{
	return end_date;
}
int Place::get_duration()
{
	return duration;
}
float Place::get_price()
{
	return price;
}
string Place::get_city()
{
	return city;
}
string Place::get_owner_gmail()
{
	return owner_gmail;
}
void Place::read()
{
	string str, start, end;
	cout << "Enter strat date:";
	cin >> start;
	v.date_validation(start);
	set_start_date(start);
	cout << "Enter end date:";
	cin >> end;
	v.date_validation(end);
	v.compare_date(start, end);
	set_end_date(end);
	cout << "Enter duration:";
	cin >> str;
	v.valid_number(str, 'i');
	set_duration(stoi(str));
	str = v.select_city();
	set_city(str);
	cout << "Enter price:";
	cin >> str;
	v.valid_number(str, 'f');
	set_price(stof(str));
	set_owner_gmail(umgr->get_current_user()->get_email());
}
void Place::fill_place_data()
{
	string str,start,end = "";
	string ch;
	cout << "Edit place data..\n";
	do
	{
		cout << "1-->Edit Date\n";
		cout << "2-->Edit Duraion\n";
		cout << "3-->Edit price\n";
		cout << "4-->Back\n";
		cin >> ch;
		v.valid_number(ch, 'i');
		switch (stoi(ch))
		{
		case 1:
			cout << "Enter start date:";
			cin >> start;
			v.date_validation(start);
			this->set_start_date(start);
			cout << "Enter End date:";
			cin >> end;
			v.date_validation(end);
			v.compare_date(start, end);
			this->set_end_date(end);
			break;
		case 2:
			cout << "Enter duration:";
			cin >> str;
			v.valid_number(str, 'i');
			this->set_duration(stoi(str));
			break;
		case 3:
			cout << "Enter price:";
			cin >> str;
			v.valid_number(str, 'f');
			this->set_price(stof(str));
			break;
		case 4:
			break;
		default:
			cout << "Invalid choice!!\n enter number from 1 to 5";
		}
	} while (stoi(ch) != 4);
}
void Place::display()
{
	cout << "City: " << this->get_city();
	cout << "||Price: " << this->get_price();
	cout << "||Start date : " << this->get_start_date();
	cout << "||End date : " << this->get_end_date();
	cout << "||Duration : " << this->get_duration()<<endl;
	cout << "Gmail of owner if you want to contact with: " << this->get_owner_gmail() << "\n\n";
}
Place::~Place(void) {

}