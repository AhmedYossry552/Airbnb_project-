#include "Place.h"
class Place_Manager
{
public:
	Valid v;
	static std::map< string, vector <Place*> > place_list_;
public:
	Place_Manager();
	void display_filter();
	void add_filter(vector <Place*>&);
	int filter_number();
	void select_search();
	void edit_place(string&);
	void add_place();//only implemented in cpp to show how class works
	void func(vector<Place*>&);
	void search_duration();
	void search_price();
	void search_date();
	void access();
	void remove_filter(vector <Place*>);
	void display_places();//display All system places
	void No_filter_display(vector <Place*>& city_places);//display city places
	vector<pair<int, char>> display_selected_filter();//display filter vector
	void display(vector <Place*>&);//select which display in code
	void view_places();
	void view_price(vector<Place*>&);
	void view_start_date(vector<Place*>&);
	void view_end_date(vector<Place*>&);
	void view_duration(vector<Place*>&);
	~Place_Manager();
};

