#include "pch.h"
#include "warehousetest.h"
#include "../Project5/List.h"
#include "gtest/gtest.h"
using namespace fakeit;
TEST_F(warehousetest, Previous_Item_Mock_Test)
{
	Mock<List> mock;
	List l2 = List(1);

	When(Method(mock, Previous)).Return(false);

	List& i = mock.get();

	warehouseinfo whi = warehouseinfo(&i);
	// Production code
	whi.Previouswarehouseinfo();
	// Verify method mock.locate was invoked.
	Verify(Method(mock, Previous));
}
TEST_F(warehousetest, Locate_item_Integration_Test) {
		List list1(5);
		item itm = item("Bisconi", "Snack", 2, "B&B");
		list1.INSERT(itm, 0, list1);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		list1.INSERT(itm1, 1, list1);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		list1.INSERT(itm2, 2, list1);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		list1.INSERT(itm3, 3, list1);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		list1.INSERT(itm4, 4, list1);
		bool a = list1.Locate("Whole-grain or multigrain cereals", list1);
		EXPECT_TRUE(a);
	}
TEST_F(warehousetest, Locate_Mock_Test)
{
	Mock<List> mock;
	List l2 = List(1);

	When(Method(mock, Locate)).Return(false);

	List& i = mock.get();

	warehouseinfo whi = warehouseinfo(&i);
	// Production code
	whi.locatewarehouseinfo();

	// Verify method mock.locate was invoked.
	Verify(Method(mock, Locate));
}
TEST_F(warehousetest, locate_Unit_test_True) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Locate("Bisconi", list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Locate_Repeated_Test) {
	List list1(5);
	item itm = item("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(itm, 0, list1);
	item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list1.INSERT(itm2, 2, list1);
	item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm4, 4, list1);

	auto name = std::vector<string>{ "Bisconi", "Tomato sauce", "Barbecue sauce", "Whole-grain or multigrain cereals","Frozen shrimp" };
	for (auto name : name) {
		ASSERT_TRUE(list1.Locate(name, list1));
	}
}
TEST_F(warehousetest, locate_Unit_Test_False) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Locate("D&D", list1);
	EXPECT_FALSE(a);
}
TEST_F(warehousetest, Random_Locate_Unit_Test_False)
{
	string Name[4] = { "Bisconi","Tomato sauce","Barbecue sauce","Oil" };
	string Category[4] = { "snaks","Ketchup","milk","oil" };
	string Brand[4] = { "B&B","kutuny","sama","Pakistan" };
	int Quantity[4] = { 1,2,3,4 };
	List list1(9);
	for (int y = 0; y < 3; y++)
	{
		int i = (rand() % 10) / 3;
		item insertItem(Name[i], Category[i], Quantity[i], Brand[i]);
		list1.INSERT(insertItem, i, list1);
	}
	bool a = list1.Locate("Henry", list1);
	EXPECT_FALSE(a);
}
TEST_F(warehousetest, Random_Locate_Unit_Test_True)
{
	string Name[4] = { "Bisconi","Tomato sauce","Barbecue sauce","Oil" };
	string Category[4] = { "snaks","Ketchup","milk","oil" };
	string Brand[4] = { "B&B","kutuny","sama","Pakistan" };
	int Quantity[4] = { 1,2,3,4 };
	bool a;
	List list1(9);
	for (int y = 0; y < 3; y++)
	{
		int i = (rand() % 10) / 3;
		item insertItem(Name[i], Category[i], Quantity[i], Brand[i]);
		list1.INSERT(insertItem, i, list1);
	}
	for (int r = 0; r < 3; r++)
	{
		bool a = list1.Locate("B&B", list1);
	}
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Display_Mock_test)
{
	Mock<List> mock;
	List l2 = List(1);

	When(Method(mock, PrintL)).Return(false);

	List& i = mock.get();

	warehouseinfo whi = warehouseinfo(&i);
	// Production code
	whi.printwarehouseinfo();

	// Verify method mock.PrintL was invoked.
	Verify(Method(mock, PrintL));
}
TEST_F(warehousetest, Display_unit_test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.PrintL(list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Reterieve_Mock_Test)
{
	Mock<List> mock;
	List l2 = List(1);

	When(Method(mock, Retrieve)).Return(false);

	List& i = mock.get();


	warehouseinfo whi = warehouseinfo(&i);

	// Production code
	whi.Reterivewarehouseinfo();

	// Verify method mock.foo was invoked.
	Verify(Method(mock, Retrieve));
}
TEST_F(warehousetest, Reterive_Integration_Test) {
	List list1(5);
	item itm = item("bisconi", "chocolate", 1, "new brand");
	list1.INSERT(itm, 0, list1);

	item itm1 = item("bisconi1", "chocolate1", 1, "new brand1");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("bisconi2", "chocolate2", 1, "new brand2");
	list1.INSERT(itm2, 2, list1);

	item itm3 = item("bisconi3", "chocolate3", 1, "new brand3");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("bisconi4", "chocolate4", 1, "new brand4");
	list1.INSERT(itm4, 4, list1);
	bool a = list1.Retrieve(3, list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Reterieve_Unit_test_True) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Retrieve(-2, list1);
	EXPECT_FALSE(a);
}

TEST_F(warehousetest, Next_Item_Mock_Test)
{
	Mock<List> mock;
	List l2 = List(1);

	When(Method(mock, Next)).Return(false);

	List& i = mock.get();


	warehouseinfo whi = warehouseinfo(&i);

	// Production code
	whi.Nextwarehouseinfo();

	// Verify method mock.foo was invoked.
	Verify(Method(mock, Next));
}
TEST_F(warehousetest, Next_Item_unit_test_True) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Next(-1, list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Next_Item_unit_test_False) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Next(4, list1);
	EXPECT_FALSE(a);
}
TEST_F(warehousetest, Next_Item_Integration_Test) {
	List list1(5);
	item itm = item("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(itm, 0, list1);
	item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list1.INSERT(itm2, 2, list1);
	item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm4, 4, list1);
	bool a = list1.Next(3, list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Next_Item_Repeated_test) {
	List list1(6);
	item itm = item("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(itm, 0, list1);
	item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list1.INSERT(itm2, 2, list1);
	item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm4, 4, list1);
	item itm5 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm5, 5, list1);

	auto name = std::vector<int>{ 0,1,2,3,4 };
	for (auto name : name) {
		ASSERT_TRUE(list1.Next(name, list1));
	}
}
TEST_F(warehousetest, Previous_Item_Repeated_test) {
	List list1(6);
	item itm = item("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(itm, 0, list1);
	item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list1.INSERT(itm2, 2, list1);
	item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm4, 4, list1);
	item itm5 = item("Frozen shrimp", "Sea Food", 25, "F&F");
	list1.INSERT(itm5, 5, list1);

	auto name = std::vector<int>{ 1,2,3,4 };
	for (auto name : name) {
		ASSERT_TRUE(list1.Previous(name, list1));
	}
}
TEST_F(warehousetest, Previous_item_Unit_Test_False) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Previous(-2, list1);
	EXPECT_FALSE(a);
}
TEST_F(warehousetest, Previous_item_test_Unit_Test_True) {
	List list1(4);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Previous(4, list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Previous_Item_Integration_Test) {
	List list1(5);
	item itm = item("bisconi", "chocolate", 1, "new brand");
	list1.INSERT(itm, 0, list1);

	item itm1 = item("bisconi1", "chocolate1", 1, "new brand1");
	list1.INSERT(itm1, 1, list1);
	item itm2 = item("bisconi2", "chocolate2", 1, "new brand2");
	list1.INSERT(itm2, 2, list1);

	item itm3 = item("bisconi3", "chocolate3", 1, "new brand3");
	list1.INSERT(itm3, 3, list1);
	item itm4 = item("bisconi4", "chocolate4", 1, "new brand4");
	list1.INSERT(itm4, 4, list1);
	bool a = list1.Previous(3, list1);
	EXPECT_TRUE(a);
}
TEST_F(warehousetest, Reterieve_Unit_test_False) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.Retrieve(-4, list1);
	EXPECT_FALSE(a);
}
TEST_F(warehousetest, Reterieve_Unit_test) {
	List list1(2);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 1, list1);
	item insetItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insetItem, 0, list1);
	bool a = list1.Retrieve(0, list1);
	EXPECT_TRUE(a);
}