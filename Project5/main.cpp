#include "List.h"
#include <iostream>
using namespace std;
int innout();
int release_resources(List, List);
int option_disp();

int main()
{
	int size=0;
	
	size=innout();
	

	//creating a list
	List LIST1(size);

	char mainagain = 'y';
	while (mainagain == 'Y' || mainagain == 'y') {

		int userselect;
		option_disp();

		
		cin >> userselect;

		switch (userselect) {

		case 1:
		{
			char again = 'y';
			while (again == 'Y' || again == 'y') {

				int location;
				cout << "\nAt which location in the list do you want to insert an item? ";
				cin >> location;

				cout << "Please enter item and its details\n";
				item insertitem;
				cout << "\nEnter Name of item : ";
				cin.ignore();
				getline(cin, insertitem.name);

				cout << "\nEnter Category of item : ";
				//cin.ignore();
				getline(cin, insertitem.category);

				cout << "\nEnter Quantity of item : ";
				cin >> insertitem.quantity;

				cout << "\nEnter brand of item : ";
				cin.ignore();
				getline(cin, insertitem.brand);

				LIST1.INSERT(insertitem, location, LIST1);

				cout << "\nDo you want to insert another item?\n";
				cout << "Enter Y for YES, any other key for NO: ";
				cin >> again;
			}
		}
		break;

		case 2:
		{
			int size;
			cout << "\nPlease enter the max size of the list: ";
			cin >> size;
			List LIST2(size);
		}
		break;

		case 3:
		{
			cout << "Concantenate lists\n";
			List L1(size), L2(size);
			LIST1.concantinate_list(L1, L2);
		}
		break;

		case 4:
		{
			int delitem;
			cout << "Enter index at which item needs to be deleted: ";
			cin >> delitem;
			LIST1.deleteElement(delitem, LIST1);
		}
		break;

		case 5:
		{
			LIST1.PrintL(LIST1);
		}
		break;

		case 6:
		{   
			string locateitem;
			cout << "An item can be located in the list based on its name\n";
			cout << "Please enter name of item that you want to locate: ";
			cin.ignore();
			getline(cin, locateitem);
			LIST1.Locate(locateitem, LIST1);
		}
		break;

		case 7:
		{
			int retrieveitem;
			cout << "\nAn item can be retrieved from the list\n";
			cout << "Please enter location from which you want to retrieve item: ";
			cin >> retrieveitem;
			LIST1.Retrieve(retrieveitem, LIST1);
		}
		break;

		case 8:
		{
			int nextitem;
			cout << "\nEnter position of an item, and the next item will be displayed: ";
			cin >> nextitem;
			LIST1.Next(nextitem, LIST1);
		}
		break;

		case 9:
		{
			int previtem;
			cout << "\nEnter position of an item, and the previous item will be displayed: ";
			cin >> previtem;
			LIST1.Previous(previtem, LIST1);
		}
		break;

		case 10:
		{
			LIST1.First(LIST1);
		}
		break;

		case 11:
		{
			LIST1.MakeNull(LIST1);
		}
		default:
			cout << "\nInvalid Selection\n";
		}

		cout << "\nDo you want to run another task?\n";
		cout << "Enter Y for YES, any other key for NO: ";
		cin >> mainagain;
	}
	release_resources(LIST1,LIST1);
	return 0;
}
int innout()
{
	int var = 0;
	cout << "\nPlease enter the max size of the list: ";
	cin >> var;
	return var;
}
int release_resources(List d, List n)
{
	delete[] d.dataArray;
	delete[] n.nextArray;
	return 0;
}
int option_disp()
{

	cout << "\nMAIN MENU\n";
	cout << "Enter the corresponding number\n";
	cout << "1) INSERT(x,p,L)\n";
	cout << "2) CREATE_LIST(size)\n";
	cout << "3) CONCANTINATE(L1,L2)\n";
	cout << "4) DELETE(p,L)\n";
	cout << "5) PRINTLIST(L)\n";
	cout << "6) LOCATE(x,L)\n";
	cout << "7) RETRIEVE(p,L)\n";
	cout << "8) NEXT(p,L)\n";
	cout << "9) PREVIOUS(p,L)\n";
	cout << "10) FIRST(L)\n";
	cout << "11) MAKE_NULL(L)\n";
	cout << "Enter you selection: ";
	return 0;
}