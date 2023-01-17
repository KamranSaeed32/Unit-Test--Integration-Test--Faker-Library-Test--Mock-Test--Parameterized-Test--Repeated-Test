#include "List.h"
#include <iostream>
using namespace std;
bool List::PrintL(List list) {

	cout << "\n*Printing List*\n";
	for (int i = 0; i < list.size; i++) {
		if (list.dataArray[i].name == "\0") {
			continue;
		}
		cout << "Item Name : " << list.dataArray[i].name << endl;
		cout << "Item Category : " << list.dataArray[i].category << endl;
		cout << "Item Quantity : " << list.dataArray[i].quantity << endl;
		cout << "Item Brand : " << list.dataArray[i].brand << endl;
		cout << endl;
	}
	return true;
}

void List::INSERT(item x, int location, List list) {

	if (list.nextArray[location] == -2) {
		list.dataArray[location] = x;
	}
	else if (location < 0 || location >= list.size) {
		cout << "Index out of array bounds\n";
	}
	else
		cout << "\nAn item already exists at index " << location << "\n";

	list.nextArray[location] = location;
}

List List::concantinate_list(List L1, List L2) {
	int newsize = L1.size + L2.size;
	List L3(newsize);

	for (int i = 0; i < L1.size; i++) {
		L3.dataArray[i] = L1.dataArray[i];
		L3.nextArray[i] = L1.nextArray[i];
	}
	for (int i = L1.size; i < newsize; i++) {
		L3.dataArray[i] = L2.dataArray[i- L1.size];
		L3.nextArray[i] = L2.nextArray[i- L1.size];
	}
	return L3;
}

bool List::deleteElement(int location, List list) {

	if (location < 0 || location >= list.size) {
		cout << "\nLocation out of bounds of array\n";
	}
	else {
		list.dataArray[location].name = "\0";
		list.dataArray[location].category = "\0";
		list.dataArray[location].quantity = -1;
		list.dataArray[location].brand = "\0";

		list.nextArray[location] = -2;
		cout << "\nitem at index " << location << " deleted\n";
	}
	return true;
}

void List::MakeNull(List list) {

	for (int i = 0; i < list.size; i++) {

		list.dataArray[i].name = "\0";
		list.dataArray[i].category = "\0";
		list.dataArray[i].quantity = -1;
		list.dataArray[i].brand = "\0";

		list.nextArray[i] = -2;
	}
	cout << "\nList is now empty\n";
}

bool List::Locate(string name, List list) {

	bool found = false;
	for (int i = 0; i < list.size; i++) {

		if (name == list.dataArray[i].name) {
			cout << "\nItem located! at index " << i << endl;
			cout << "Item details are:\n";
			cout << "Item Name : " << list.dataArray[i].name << endl;
			cout << "Item Category : " << list.dataArray[i].category << endl;
			cout << "Item Quantity : " << list.dataArray[i].quantity << endl;
			cout << "Item Brand : " << list.dataArray[i].brand << endl;
			found = true;
			return true;
		}
	}
	if (found == false) {
		cout << "\nItem not found\n";
		return false;
	}
}

bool List::Retrieve(int index, List list) {

	if (index < 0 || index >= list.size) {
		cout << "\nLocation out of bounds of array\n";
		return false;
	}

	if (list.nextArray[index] == -2) {
		cout << "\nNo item at index " << index << endl;
		return false;
	}
	else {
		cout << "Retrieving item at index " << index << endl;
		cout << "Item details are:\n";
		cout << "Item Name : " << list.dataArray[index].name << endl;
		cout << "Item Category : " << list.dataArray[index].category << endl;
		cout << "Item Quantity : " << list.dataArray[index].quantity << endl;
		cout << "Item Brand : " << list.dataArray[index].brand << endl;
		return true;
	}
}

bool List::Next(int index, List list) {

	int newindex = index + 1;
	bool found = false;

	while (newindex < list.size) {
		if (list.nextArray[newindex] != -2) {
			cout << "The next item is at index " << newindex << endl;
			cout << "Item details are:\n";
			cout << "Item Name : " << list.dataArray[newindex].name << endl;
			cout << "Item Category : " << list.dataArray[newindex].category << endl;
			cout << "Item Quantity : " << list.dataArray[newindex].quantity << endl;
			cout << "Item Brand : " << list.dataArray[newindex].brand << endl;
			found = true;
			return true;
		}
		newindex++;
		if (found == true) {
			break;
		}
	}
	if (found == false) {
		cout << "\nNo item after index " << index << endl;
		return false;
	}
}

bool List::Previous(int index, List list) {

	int newindex = index - 1;
	bool found = false;
	while (newindex >= 0) {
		if (list.nextArray[newindex] != -2) {
			cout << "The previous item is at index " << newindex << endl;
			cout << "Item details are:\n";
			cout << "Item Name : " << list.dataArray[newindex].name << endl;
			cout << "Item Category : " << list.dataArray[newindex].category << endl;
			cout << "Item Quantity : " << list.dataArray[newindex].quantity << endl;
			cout << "Item Brand : " << list.dataArray[newindex].brand << endl;
			found = true;
			return true;
		}
		if (found == true) {
			break;
		}
		newindex--;
	}
	if (found == false) {
		cout << "\nNo item before index " << index << endl;
		return false;
	}
}

bool List::First(List list) {

	bool found = false;

	for (int i = 0; i < list.size; i++) {

		if (list.nextArray[i] != -2) {
			cout << "The first item is at index " << i << endl;
			cout << "Item details are:\n";
			cout << "Item Name : " << list.dataArray[i].name << endl;
			cout << "Item Category : " << list.dataArray[i].category << endl;
			cout << "Item Quantity : " << list.dataArray[i].quantity << endl;
			cout << "Item Brand : " << list.dataArray[i].brand << endl;
			found = true;
			return true;
		}
		if (found == true) {
			break;
		}
	}
	if (found == false) {
		cout << "List is empty\n";
		return false;
	}
}
