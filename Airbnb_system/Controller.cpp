#include "Controller.h"
void Controller::host_function()
{
	string choice;
	do
	{
		cout << "1-->Add_place\n2-->Edit place data\n3-->Back\nYour choice:";
		cin >> choice;
		va.valid_number(choice, 'i');
		switch (stoi(choice))
		{
		case 1:
		{
			pmgr->add_place();
			break;
		}
		case 2:
		{
			User* u = umgr.get_current_user();
			string x = u->get_email();
			pmgr->edit_place(x);
			break;
		}
		case 3:
			break;
		default:
			cout << "Invaild choice";
		}
	} while (stoi(choice) != 3);
}

void Controller::traveller_function()
{
	pmgr->select_search();
}
void Controller::admin_function()
{
	string cho = "";
	string choice;
	do
	{
		cout << "1-->Access\n2-->back\nyour choice:";
		cin >> choice;
		va.valid_number(choice, 'i');
		switch (stoi(choice))
		{
		case 1:
		{
			cout << "1)Access users data\n2)Access places data\nyour choise:";
			cin >> cho;
			va.valid_number(cho, 'i');
			if (stoi(cho) == 1)
			{
				umgr.access_users();
			}
			else if (stoi(cho) == 2) {
				string in;
				cout << "1)access places in system\n2)view places\nyour choise:";
				cin >> in;
				va.valid_number(in,'i');
				if(stoi(in)==1)
				  pmgr->access();
				else if(stoi(in) == 2) 
				  pmgr->view_places();
				else {
					cout << "Invaled enter\n!!";
					break;
				}
			}
			else
			{
				cout << "Invaled enter!!\n";
				break;
			}
			break;
		}
		case 2:
			break;
		default:
			cout << "Invaild choice\n";
		}
	} while (stoi(choice) != 2);
}

