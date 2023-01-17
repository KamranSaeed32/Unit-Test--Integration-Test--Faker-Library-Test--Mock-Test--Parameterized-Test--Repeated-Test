#include "pch.h"
//#include "../Project5/List.h"
#include "../Project5/Source.cpp"
//#include "../Project5/main.cpp"
#include "../fakelibrary/FakeLib.h"
#include "gtest/gtest.h"
using namespace fakeit;
//#include "gmock/gmock.h"
using namespace ::testing;
//using namespace std;

//**************UNIT TEST 1******************
TEST(Unittest1, Contcatination) {
	List list1(2);
	item insertItem("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(insertItem, 0, list1);
	item insertItemTwo("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(insertItemTwo, 1, list1);
	List list2(1);
	item insertItemThree("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list2.INSERT(insertItemThree, 0, list2);
	List newList = list1.concantinate_list(list1, list2);
	EXPECT_EQ(newList.size, 3);
	EXPECT_EQ(newList.dataArray[2].category, "Ketcup");
}
//**************Integration TEST 1******************

//**************Faker Library TEST 1******************
TEST(FakerLibraryTest1, Test1)
{
	string Name[4], Category[4], Brand[4], expectedbrand;
	int Quantity[4];
	List list1(5);
	for (int i = 0; i < 3; i++)
	{
		Name[i] = FakerNameGenerator();
		Category[i] = FakerCategoryGenerator();
		Quantity[i] = Fakerquantitygenerator();
		Brand[i] = FakerBrandGenerator();
		item insertItem(Name[i], Category[i], Quantity[i], Brand[i]);
		list1.INSERT(insertItem, i, list1);
		string expectedbrand = insertItem.brand;
	}

	EXPECT_EQ(list1.dataArray[3].brand, expectedbrand);
}

//**************MOCK TEST 1******************



//**************Parameterized TEST 1******************


//**************Repeated TEST 1******************

//**************Unit TEST 2******************
TEST(UnitTest2, Insertiontest1) {
	List list1(1);

	item insertItem("Bisconi", "Snack", 1, "Blue & Brand"
	);
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].name, "Bisconi");
}
//**************Integration TEST 2******************

//**************Faker Library TEST 2******************
TEST(FakerLibraryTest2, Test2)
{
	List list1(2);
	string Name = FakerNameGenerator();
	string Category = FakerCategoryGenerator();
	int Quantity = Fakerquantitygenerator();
	string Brand = FakerBrandGenerator();
	item insertItem(Name, Category, Quantity, Brand);
	list1.INSERT(insertItem, 0, list1);
	string expectedCategory = insertItem.category;
	EXPECT_EQ(list1.dataArray[0].category, expectedCategory);
}
//**************MOCK TEST 2******************

//**************Parameterized TEST 2******************

//**************Repeated TEST 2******************
TEST(Repeattest2, Repeattest2) {
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

	auto name = std::vector<int>{ 0,1,2,3,4 };
	for (auto name : name) {
		ASSERT_TRUE(list1.Retrieve(name, list1));
	}
}
//**************Unit TEST 3******************
TEST(Unittest3, deletetest1) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].brand, "");
}
//**************Integration TEST 3******************

//**************Faker Library TEST 3******************
TEST(FakerLibraryTest3, Test3)
{
	List list1(2);
	string Name = FakerNameGenerator();
	string Category = FakerCategoryGenerator();
	int Quantity = Fakerquantitygenerator();
	string Brand = FakerBrandGenerator();
	item insertItem(Name, Category, Quantity, Brand);
	list1.INSERT(insertItem, 0, list1);
	int expectedquantity = insertItem.quantity;
	EXPECT_EQ(list1.dataArray[0].quantity, expectedquantity);

}
//**************Mock TEST 3******************


//**************Parameterized TEST 3******************


//**************Repeated TEST 3******************


//**************Unit TEST 4******************

//**************Integration Test 4******************


//**************Faker Library Test 4******************
TEST(FakerLibraryTest4, Test4)
{
	List list1(2);
	string Name = FakerNameGenerator();
	string Category = FakerCategoryGenerator();
	int Quantity = Fakerquantitygenerator();
	string Brand = FakerBrandGenerator();
	item insertItem(Name, Category, Quantity, Brand);
	list1.INSERT(insertItem, 0, list1);
	string expectedbrand = insertItem.brand;
	EXPECT_EQ(list1.dataArray[0].brand, expectedbrand);
}
//**************MOCK Test 4******************

//**************Parameterized Test 4******************

//**************Repeated Test 4******************

//**************Unit Test 5******************
TEST(Unittest5, FindFirstitem) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.First(list1);
	EXPECT_TRUE(a);
}
//**************Integrartion Test 5******************
TEST(integrationtest5, firstintegrate) {
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
	bool a = list1.First(list1);
	EXPECT_TRUE(a);
}
//**************Faker Library Test 5******************
TEST(FakerLibraryTest5, Test5)
{
	List list1(2);
	string Name = FakerNameGenerator();
	string Category = FakerCategoryGenerator();
	int Quantity = Fakerquantitygenerator();
	string Brand = FakerBrandGenerator();
	item insertItem(Name, Category, Quantity, Brand);
	list1.INSERT(insertItem, 0, list1);
	string expectedName = insertItem.name;
	EXPECT_EQ(list1.dataArray[0].name, expectedName);

}
//**************MOCK Test 5******************

//**************Parameterized Test 5******************

//**************Repeated Test 5******************
TEST(Repeattest5, Repeattest5) {
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
		ASSERT_TRUE(list1.deleteElement(name, list1));
	}
}
//**************Unit Test 6******************
TEST(unittest6, InsertTest2) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].quantity, 2);
}
//**************UNIT TEST 7******************
TEST(unittest7, InsertTest3) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].category, "Snack");
}
//**************UNIT TEST 8******************
TEST(unittest8, InsertTest4) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].brand, "NoBrand");
}
//**************UNIT TEST 9******************
TEST(Unittest9, deletetest2) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].quantity, -1);
}
//**************UNIT TEST 10******************
TEST(Unittest10, deletetest3) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].category, "");
}
//**************UNIT TEST 11******************
TEST(Unittest11, deletetest4) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].name, "");
}
//**************UNIT TEST 12******************
TEST(Unittest12, Nulltest1) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].name, "");
}
//**************UNIT TEST 13******************
TEST(Unittest13, Nulltest2) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].quantity, -1);
}
//**************UNIT TEST 14******************
TEST(Unittest14, Nulltest3) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].brand, "");
}
//**************UNIT TEST 15******************
TEST(Unittest15, Nulltest4) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].category, "");
}
//**************UNIT TEST 16******************

//**************UNIT TEST 17******************

//**************UNIT TEST 18******************

//**************UNIT TEST 19******************

//**************UNIT TEST 20******************

//**************UNIT TEST 21******************

//**************UNIT TEST 22******************

//**************UNIT TEST 23******************

//**************UNIT TEST 24******************
TEST(unittest24, firstitemfoundtest1) {
	List list1(1);
	bool a = list1.First(list1);
	EXPECT_FALSE(a);
}
//**************UNIT TEST 25******************

//**************UNIT TEST 26******************
TEST(Unittest26, Contcatination2) {
	List list1(2);
	item insertItem("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(insertItem, 0, list1);
	item insertItemTwo("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(insertItemTwo, 1, list1);
	List list2(1);
	item insertItemThree("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list2.INSERT(insertItemThree, 0, list2);
	List newList = list1.concantinate_list(list1, list2);
	EXPECT_EQ(newList.size, 3);
	EXPECT_EQ(newList.dataArray[2].name, "Barbecue sauce");
}

//**************UNIT TEST 27******************
TEST(Unittest27, Contcatination3) {
	List list1(2);
	item insertItem("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(insertItem, 0, list1);
	item insertItemTwo("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(insertItemTwo, 1, list1);
	List list2(1);
	item insertItemThree("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list2.INSERT(insertItemThree, 0, list2);
	List newList = list1.concantinate_list(list1, list2);
	EXPECT_EQ(newList.size, 3);
	EXPECT_EQ(newList.dataArray[2].quantity, 3);
}
//**************UNIT TEST 28******************

//**************UNIT TEST 29******************
TEST(Unittest29, Contcatination4) {
	List list1(2);
	item insertItem("Bisconi", "Snack", 2, "B&B");
	list1.INSERT(insertItem, 0, list1);
	item insertItemTwo("Tomato sauce", "Ketcup", 2, "kutny");
	list1.INSERT(insertItemTwo, 1, list1);
	List list2(1);
	item insertItemThree("Barbecue sauce", "Ketcup", 3, "Mitchels");
	list2.INSERT(insertItemThree, 0, list2);
	List newList = list1.concantinate_list(list1, list2);
	EXPECT_EQ(newList.size, 3);
	EXPECT_EQ(newList.dataArray[2].brand, "Mitchels");
}
//**************UNIT TEST 30******************
