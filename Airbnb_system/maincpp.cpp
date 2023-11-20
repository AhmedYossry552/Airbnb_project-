#include "Airbnb.h"
std::map<std::string, std::vector<Place*> >Place_Manager::place_list_;
std::map <  pair<string, string>, User*>User_Manager::users_list;
int main()
{
	Airbnb app;
	app.run();
	return 0;
}


