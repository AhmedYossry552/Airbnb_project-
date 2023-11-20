#include"User.h"
class User_Manager
{
public:
	static std::map < pair<string, string>, User* > users_list;
	Valid v;
public:
	User* current_user = nullptr;
	User_Manager();
	void sign_up();
	bool login();
	void display_users();
	void invaled_user();
	void view_users();
	void view_type();
	void view_gender();
	void view_nationalty();
	void access_users();
	void main_view();
	void remove_after_display();
	~User_Manager();
	User* get_current_user();
};

