#include "Valid.h"
map<int, int> calender = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
vector<string> valid_city{
"Cairo","Alexanria","Giza   ","Sohag","Hurgada","Dahb   ","Aswan","Luxor",
	"Edfu   ","Port_Said","Ismailia","Mansoura","Tanta","Sharm_El_Sheikh"
	,"Damiiette","Marsa_matruh","Suez","Minya"
};

void Valid::confirm_validation(string& c)
{
	if (c == "y" || c == "Y" || c == "n" || c == "N")
		return;
	else
		do {
			cout << "Invalid confirmation!! Enter y for Yes or n for No\n";
			cout << "your confirmation y/n:";
			cin >> c;

		} while (c != "N" && c != "n" && c != "y" && c != "Y");
}

void Valid::type_validation(string &c)
{
	if (c == "H" || c == "h" || c == "t" || c == "T")
		return;
	else
		do {
			cout << "Invalid type!! Enter h for Host or t for traveller\n";
			cout << "your type h/t:";
			cin >> c;

		} while (c != "H" && c != "h" && c != "t" && c != "T");
}

void Valid::gender_validation(string &c)
{
	if (c == "m" || c == "M" || c == "f" || c == "F")
		return;
	else
		do {
			cout << "Invalid gender !! Enter m for Male or f for Female\n";
			cout << "your gender m/f:";
			cin >> c;

		} while (c != "m" && c != "M" && c != "F" && c != "f");


}

bool Valid::v_f(string& str)
{
	for (int i = 0; i < str.length(); i++)

		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')

			return  false;
	return true;
}

bool Valid::v_i(string& str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

void Valid::valid_number(string& f, char a)
{
	if (a == 'i')
	{
		while (!v_i(f))
		{
			cout << "invaild enter \nenter integer number:";
			cin >> f;
		}
	}
	else if (a == 'f')
	{
		while (!v_f(f))
		{
			cout << "invaild enter \n enter float or integer number   ";
			cin >> f;

		}
	}
}

bool Valid::contains_char(string& str)
{
	bool test = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 2 || i == 5)
			continue;
		else
		{
			test = isdigit(str[i]);
			if (!test)
				break;

		}
	}
	return !test;//return true if date contains any char -- return false if date contains only numberes 01-12-2022 
}

bool Valid::is_suitable_date(string& str)
{
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);
	int curyear = 1900 + local_time->tm_year;
	int curmonth = 1 + local_time->tm_mon;
	int curday = local_time->tm_mday;
	long long really_days = calc_days(curday, curmonth, curyear);
	string date;
	vector <int> v;
	int x;
	istringstream stream(str);
	while (getline(stream, date, '-'))
	{
		x = stoi(date);
		v.push_back(x);
	}
	long long input_days = calc_days(v[0], v[1], v[2]);

	return (input_days >= really_days);//test if input date is current or not
}

bool Valid::is_date(string& str)//flow functiom which confirm date
{
	bool tmp = 0;
	if (str.size() == 10 && str[2] == '-' && str[5] == '-' && !contains_char(str) && is_suitable_date(str))
		tmp = 1;
	return tmp;
}

void Valid::date_validation(string& str)//force user to enter my prefered date -->  *--*
{
	if (!is_date(str))
	{
		do
		{
			cout << "invalid date form!!\nHint: 01-09-2022\n";
			cout << "Enter valid date:";
			cin >> str;
		} while (!is_date(str));
	}
}

void Valid::add_validation(string& c)
{
	if (c == "A" || c == "a" || c == "r" || c == "R" && c.size() == 1)
		return;
	else
		do {
			cout << "Invalid input!! Enter A for add or R for remove\n";
			cout << "your answer a/r:";
			cin >> c;

		} while (c != "R" && c != "r" && c != "A" && c != "a");
}

void Valid::email_valid(string& email)
{
	// Regular expression definition
	regex pattern(
		"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w){3})+");
	// Match the string pattern
	// with regular expression
	if (!regex_match(email, pattern))
	{
		do
		{
			cout << "Enter valid email like abdo@gmail.com\n";
			cin >> email;

		} while (!regex_match(email, pattern));
	}
}

void Valid::compare_date(string& date1, string& date2)
{
	while (true)
	{
		string y = date1 + "-" + date2;//(*--*) + (-) + (*--*) = (*--*-*--*)
		vector <long long> v;
		int x;
		istringstream stream(y);
		while (getline(stream, y, '-'))
		{
			x = stoi(y);
			v.push_back(x);

		}
		long long d1_days = calc_days(v[0], v[1], v[2]);
		long long d2_days = calc_days(v[3], v[4], v[5]);
		if (d2_days > d1_days)
			break;
		else
		{
			cout << "invalid end date!!\n";
			cout << "Enter end date:";
			cin >> date2;

		}
	}
}

bool Valid::in_date_range(string& start, string& end, string& date1, string& date2)//check if valid date is in range between 2 valid dates
{
	string line = start + "-" + end + "-" + date1 + "-" + date2;
	//(*--*) + (-) + (*--*)+ (-) + (*--*) = (*--*-*--*-*--*)
	vector <long long> v;
	int x;
	string word;
	istringstream stream(line);
	while (getline(stream, word, '-'))
	{
		x = stoi(word);
		v.push_back(x);

	}
	long long d1_days = calc_days(v[0], v[1], v[2]);//place start
	long long d2_days = calc_days(v[3], v[4], v[5]);//place end
	long long d3_days = calc_days(v[6], v[7], v[8]);//filter start
	long long d4_days = calc_days(v[9], v[10], v[11]);//filter end


	return(d3_days >= d1_days && d4_days <= d2_days);//return true if the date is in range




}

long long Valid::calc_days(int d, int m, int y)
{
	long long total = (y - 1) * 365;
	for (int i = 1; i < m; i++)
	{
		total += calender[i];
	}
	total += d;
	return total;
}
void Valid::valid_range(int& num, int start, int end)
{
	if (num < start || num > end)
	{
		do
		{
			cout << "invalid input\nplease Enter valid number:";
			cin >> num;

		} while (num<start || num > end);
	}

}
const string Valid::select_city()
{
	string ch;
	cout << "\t\t\t-------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < valid_city.size()/2; i++)
		cout << "\t\t\t\t\t" << i + 1 << "- " << valid_city[i] <<"\t\t" << i + 10 << "- " << valid_city[i+9] << "\n";
	cout << "\t\t\t-------------------------------------------------------------------------------------------\n";
	cout << "Enter number of city:";
	cin >> ch;
	valid_number(ch, 'i');
	int y = stoi(ch);
	valid_range(y, 1, valid_city.size());
	return valid_city[y - 1];
}
void Valid::header_decortion(string str, int co)
{
	set_color(co);
	cout << "\t\t\t\t\t+-------------------------------------------------------------+\n";
	cout << "\t\t\t\t\t+\t    ***    " << str << "    ***            +\n";
	cout << "\t\t\t\t\t+-------------------------------------------------------------+\n\n\n";
}

void Valid::set_color(int color)
{
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hconsole, color);
}
void Valid::table_decoration(string str)
{
	cout << "\t\t\t-----------------------------------------------------\n";
	for (int i = 0; i < valid_city.size(); i++)
		cout << "\t\t\t\t\t" << str << "\n";
	cout << "\t\t\t-----------------------------------------------------\n";
}


