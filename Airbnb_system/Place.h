//#include "User.h"
#include "User_Manager.h"
#include<stack>
class Place
{
private:
	string start_date;
	string end_date;
	int duration;
	float price;
	string city;
	string owner_gmail;

public:
	Place();
	Valid v;
	void set_start_date(string);
	void set_end_date(string);
	void set_duration(int);
	void set_price(float);
	void set_city(string);
	void set_owner_gmail(string);
	/*------------------------------*/
	string get_start_date();
	string get_end_date();
	int get_duration();
	float get_price();
	string get_city();
	string get_owner_gmail();
	/*-------------------------------*/
	void read();
	void fill_place_data();
	void display();
	/*-------------------------------*/
	~Place(void);

};


