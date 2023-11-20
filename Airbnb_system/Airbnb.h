#pragma once
#include "Controller.h"
class Airbnb
{
	Controller AS;
	User_Manager ugr;
	Place_Manager pgr;
public:
	Valid v;
	Airbnb();
	void run();
	void flow();
	void store_place_data();
	void store_user_data();
	void load_user_data();
	void load_place_data();
	void access_system(int);
	~Airbnb();
};

