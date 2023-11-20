#include "Place_Manager.h"
#include <sstream>
#include<fstream>
stack <pair<float, float>> price_stack;
stack <pair<string, string>> date_stack;
stack <int> duration_stack;
vector <Place*> valid_places;

Place_Manager::Place_Manager()
{

}

void Place_Manager::add_place()
{
	Place* ptr = new Place;
	ptr->read();
	Place_Manager::place_list_[ptr->get_city()].push_back(ptr);
	cout << "added successfully!!\n";
}

void Place_Manager::edit_place(string& og) {
	vector<int> index;
	string city = v.select_city();
	while(place_list_[city].empty())
	{
		cout << "City has no places\n";
		city = v.select_city();
	}
	for (int i = 0; i < Place_Manager::place_list_.find(city)->second.size(); i++) {
		if (Place_Manager::place_list_.find(city)->second[i]->get_owner_gmail() == og)
		{
			index.push_back(i);
		}
	}
	string ch;
	for (int x = 0; x < index.size(); x++)
	{
		cout << x + 1 << ":";
		Place_Manager::place_list_.find(city)->second[index[x]]->display();
	}
	cout << "select place number";
	cin >> ch;
	v.valid_number(ch, 'i');
	int y = stoi(ch);
	v.valid_range(y, 1, index.size());
	Place_Manager::place_list_.find(city)->second[index[y - 1]]->fill_place_data();
}

void Place_Manager::search_price()
{
	float s, e;
	cout << "Enter filter price start range:";
	cin >> s;
	cout << "Enter filter price end range:";
	cin >> e;
	price_stack.push(make_pair(s, e));
}

void Place_Manager::search_date()
{
	string st, en;
	cout << "Enter filter start date:";
	cin >> st;
	cout << "Enter filter end date:";
	cin >> en;
	date_stack.push(make_pair(st, en));
}

void Place_Manager::search_duration()
{
	int dur;
	cout << "Enter filter duration:";
	cin >> dur;
	duration_stack.push(dur);
}

int Place_Manager::filter_number()
{
	int op = 0;
	if (!price_stack.empty())
		op++;
	if (!date_stack.empty())
		op++;
	if (!duration_stack.empty())
		op++;
	if (!op)
		return -1;
	return op;
}

void Place_Manager::display_filter()
{
	if (valid_places.empty())
		cout << "No places found!!\n";
	else
	{
		for (auto& v : valid_places)
		{
			v->display();
			cout << "----------------------------\n";
		}
	}
}

void Place_Manager::add_filter(vector <Place*>& v)
{
	int ch = 0;

	do
	{
		cout << "1--> Filter with price range";
		cout << "\n2--> Filter with date range";
		cout << "\n3--> Filter with duration";
		cout << "\n4--> Display filter places";
		cout << "\n5--> Back\nyour choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			search_price();

			break;
		case 2:
			search_date();
			break;
		case 3:
			search_duration();
			break;
		case 4:
			display_filter();
			break;
		case 5:
			break;
		default:
			cout << "Invalid choice!!\n";
		}
		func(v);
	} while (ch != 5);
}

vector<pair<int, char>> Place_Manager::display_selected_filter()
{
	vector<pair<int, char>> f = {};
	int ctr = 1;
	if (filter_number() == -1)
		cout << "No selected filter (Please add filter first)\n";
	else
	{
		if (!price_stack.empty())
		{
			cout << ctr << "-->  remove selected filter to price:";
			cout << price_stack.top().first << "--> " << price_stack.top().second << "\n";
			f.push_back(make_pair(ctr, 'p'));
			ctr++;
		}
		if (!date_stack.empty())
		{
			cout << ctr << "--> remove selected filter to date:";
			cout << date_stack.top().first << "--> " << date_stack.top().second << "\n";
			f.push_back(make_pair(ctr, 'd'));
			ctr++;
		}
		if (!duration_stack.empty())
		{

			cout << ctr << "--> remove selected filter to duration:";
			cout << duration_stack.top() << "\n";
			f.push_back(make_pair(ctr, 'r'));
		}
	}
	return f;
}

void Place_Manager::view_places()
{
	string ch ;
	do
	{
		string city = v.select_city();
		if (place_list_[city].empty())
			cout << "City have no places\nplease view in another city\n";
		else
		{
			vector <Place*> ptr_to_avaliable_places = place_list_.find(city)->second;
			cout << "1-->View places by Price\n";
			cout << "2-->View places by Duration\n";
			cout << "3-->View places by Start Date\n";
			cout << "4-->View places by End Date\n";
			cout << "5-- > Back\nYour choice : ";
			cin >> ch;
			v.valid_number(ch, 'i');
			switch (stoi(ch))
			{
			case 1:
				view_price(ptr_to_avaliable_places);
				break;
			case 2:
				view_duration(ptr_to_avaliable_places);
				break;
			case 3:
				view_start_date(ptr_to_avaliable_places);
				break;
			case 4:
				view_end_date(ptr_to_avaliable_places);
				break;
			case 5:
				break;
			default:
				cout << "invalid";
			}
		}
	} while (stoi(ch) != 5);
}

void Place_Manager::access() {
	int t = 1;
	map<string, int> temp;
	vector<Place*>vi;
	for (auto it : place_list_)
	{
		for (int i = 0; i < it.second.size(); i++) {
			cout << t << "-";
			vi.push_back(it.second[i]);
			it.second[i]->display();
			t++;
		}
		temp[it.first] = t - 1;
	}
	string x;
	int y = 0;
	while (true) {
		cout << "Do you want do delete any place?\n Enter 1) to Delete\n 2) to back";
		cin >> x;
		v.valid_number(x, 'i');
		if (stoi(x) == 1) {
			string cho;
			cout << "Enter index of place that you want delete it:";
			cin >> cho;
			v.valid_number(cho, 'i');
			y = stoi(cho);
			v.valid_range(y, 1, vi.size());
			int ind = (y - 1) % temp[vi[y - 1]->get_city()];
			place_list_[vi[y - 1]->get_city()].erase(place_list_[vi[y - 1]->get_city()].begin() + (ind- 1));
			display_places();
		}
		else
			break;
	}
}

void Place_Manager::display_places()
{
	if (place_list_.empty())
	{
		v.set_color(4); cout << "No places yet\n";
		v.set_color(7);
	}
	else
	{
		v.set_color(9);
		for (auto& it : place_list_)
		{
			for (int i = 0; i < it.second.size(); i++)
			{
				cout << "\t\t\t";
				it.second[i]->display();
				cout << "\t\t\t";
				cout << "--------------------------------------------------------------------------------------\n";
			}
		}
	}

}
void Place_Manager::remove_filter(vector <Place*> c)
{
	int ch = 0, b = 0;
	do
	{
		vector<pair<int, char>> x = display_selected_filter();
		b = x.size() + 1;
		cout << b << "-Back\nyour choice:";
		cin >> ch;
		v.valid_range(ch, 1, b);
		if (x.size() > 0 && ch != b)
		{
			if (x[ch - 1].second == 'p')
				price_stack.pop();
			else if (x[ch - 1].second == 'd')
				date_stack.pop();
			else if (x[ch - 1].second == 'r')
				duration_stack.pop();
		}
	} while (ch != b);
	func(c);
}

void Place_Manager::display(vector <Place*>& inside)
{
	if (valid_places.empty())
		No_filter_display(inside);
	else
		display_filter();
}

void Place_Manager::No_filter_display(vector <Place*>& city_places)
{
	for (auto& it : city_places)
	{
		it->display();
	}
}

void Place_Manager::select_search()
{
	cout << "Where are you going?!\n";
	string city = v.select_city();//view city list and get input from user

	int ch = 0;
	do
	{
		if (place_list_[city].empty())
		{
			cout << "City has no places\nplease search in another city\n";
			city = v.select_city();
		}
		else
		{
			vector <Place*> ptr_to_avaliable_places = place_list_.find(city)->second;
			cout << "1-->Add filter\n";
			cout << "2-->remove selected filter\n";
			cout << "3-->display all places in "<< city<<"\n";
			cout << "4-->back\n your choice:";
			cin >> ch;

			switch (ch)
			{
			case 1:
				add_filter(ptr_to_avaliable_places);
				break;
			case 2:
				remove_filter(ptr_to_avaliable_places);
				break;
			case 3:
				display(ptr_to_avaliable_places);
			case 4:
				break;

			default:
				cout << "invalid selection!!\n";
			}
		}

	} while (ch != 4);

}

void Place_Manager::func(vector <Place*>& vec)
{
	int ctr;
	if (!valid_places.empty())
	{
		valid_places.clear();
	}
	for (auto it : vec)
	{
		ctr = 0;
		string x = it->get_start_date();
		string y = it->get_end_date();
		if (!price_stack.empty() && it->get_price() >= price_stack.top().first && it->get_price() <= price_stack.top().second)
			ctr++;
		if (!date_stack.empty() && v.in_date_range(x, y, date_stack.top().first, date_stack.top().second))
			ctr++;
		if (!duration_stack.empty() && it->get_duration() == duration_stack.top())
			ctr++;
		if (ctr == filter_number())
			valid_places.push_back(it);
	}
}
void Place_Manager::view_price(vector<Place*>& vec)
{
	string n;
	vector <Place*> suitable;
	float pr;
	do {
		cout << "Enter price:";
		cin >> pr;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i]->get_price() == pr)
			{
				suitable.push_back(vec[i]);
			}
		}if (suitable.size() == 0)
		{
			cout << "There are no places with this price\n";

		}
		else {
			for (int i = 0; i < suitable.size(); i++)
			{
				cout << i + 1 << " - ";
				suitable[i]->display();
			}
		}
		cout << "Do you want to serch with another price(y,n)?";
		cin >> n;
		v.confirm_validation(n);
	} while (n != "n");
}
void Place_Manager::view_start_date(vector<Place*>& vec)
{
	string n;
	vector <Place*> suit;
	string st;
	do {
	cout << "Enter regarded start date to view with:";
	cin >> st;
	v.date_validation(st);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->get_start_date() == st)

		{
			suit.push_back(vec[i]);
		}
	}
	if (suit.size() == 0)
	{
		cout << "There are no places with this date\n";
	}
	else {
		for (int i = 0; i < suit.size(); i++)
		{
			cout << i + 1 << " -";
			suit[i]->display();
		}
	}cout << "Do you want to serch with another start date(y,n)?";
	cin >> n;
	v.confirm_validation(n);
	} while (n != "n");
}

void Place_Manager::view_end_date(vector<Place*>& vec)
{
	string n;
	vector <Place*> suit;
	string en;
	do{
	cout << "Enter regarded End date to view with:";
	cin >> en;
	v.date_validation(en);
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->get_end_date() == en)
		{
			suit.push_back(vec[i]);
		}
	}if (suit.size() == 0)
	{
		cout << "There are no places with this end date\n";
	}
	else {
		for (int i = 0; i < suit.size(); i++)
		{
			cout << i + 1 << " -";
			suit[i]->display();
		}
	}cout << "Do you want to serch with another start date(y,n)?";
	cin >> n;
	v.confirm_validation(n);
	} while (n != "n");
}

void Place_Manager::view_duration(vector<Place*>& vec)
{
	string n;
	vector <Place*> suitable;
	int dur;
	do{
	cout << "Enter regarded duration to view with:";
	cin >> dur;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->get_duration() == dur)
		{
			suitable.push_back(vec[i]);
		}
	}if (suitable.size() == 0)
	{
		cout << "There are no places with this duration\n";
	}
	else {
		for (int i = 0; i < suitable.size(); i++)
		{
			cout << i + 1 << " -";
			suitable[i]->display();
		}
	}cout << "Do you want to serch with another start date(y,n)?";
	cin >> n;
	v.confirm_validation(n);
	} while (n != "n");
}

Place_Manager::~Place_Manager()
{
	for (auto it : Place_Manager::place_list_)
	{
		for (auto x : it.second)
			delete x;
	}
	Place_Manager::place_list_.clear();
}



