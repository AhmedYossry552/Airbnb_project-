#pragma once
#include "Place_Manager.h"
class Controller
{
public:
	User_Manager umgr;
	Place_Manager* pmgr;
	void host_function();
	void traveller_function();
	void admin_function();
	Valid va;
};

