#include<string>
#include<iostream>
using namespace std;
class item {
public:
	string name;
	string category;
	int quantity = -1;
	string brand;

public:
	item() {
	}
	item(string name, string category, int quantity, string brand) {
		this->name = name;
		this->category = category;
		this->quantity = quantity;
		this->brand = brand;
	}
};

class List {

public:
	item* dataArray;
	int* nextArray;
	int size;
	virtual bool PrintL(List);
	void INSERT(item, int, List);
	List concantinate_list(List L1, List L2);
	bool deleteElement(int location, List list);
	void MakeNull(List list);
	virtual bool Locate(string name, List list);
	virtual bool Retrieve(int index, List list);
	virtual bool Next(int index, List list);
	virtual bool Previous(int index, List list);
	bool First(List list);

	List(int size) {
		dataArray = new item[size];
		nextArray = new int[size];
		this->size = size;

		for (int i = 0; i < size; i++) {
			nextArray[i] = -2;
		}
	}
};
class warehouseinfo {

	List* lw;
	
public:
	warehouseinfo(List* list) : lw(list) {}

	void printwarehouseinfo() {
		lw->PrintL(*lw);
	}
	void locatewarehouseinfo() {
		lw->Locate("L&L" ,* lw);
	}
	void Reterivewarehouseinfo() {
		lw->Retrieve(0, *lw);
	}
	void Nextwarehouseinfo() {
		lw->Next(0, *lw);
	}
	void Previouswarehouseinfo() {
		lw->Previous(0, *lw);
	}

};
