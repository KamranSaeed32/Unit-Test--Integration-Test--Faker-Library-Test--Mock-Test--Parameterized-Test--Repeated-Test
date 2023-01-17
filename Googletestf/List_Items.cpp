#include "pch.h"
#include "List_Items.h"
#include "pch.h"
#include "../Project5/Source.cpp"
#include "../fakelibrary/FakeLib.h"
#include "gtest/gtest.h"
using namespace fakeit;

using namespace ::testing;

TEST_F(List_Items, Contcatination_Unit_Test) {
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

TEST_F(List_Items, Faker_Library_Random_Test)
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


TEST_F(List_Items, Name_Insertion_Unit_test) {
	List list1(1);

	item insertItem("Bisconi", "Snack", 1, "Blue & Brand"
	);
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].name, "Bisconi");
}

TEST_F(List_Items, Faker_Library_Category_Test)
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

TEST_F(List_Items, Reterieve_Repeated_test) {
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

TEST_F(List_Items, Delete_Unit_test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].brand, "");
}

TEST_F(List_Items, Faker_Libray_Quantity_Test)
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

TEST_F(List_Items, Faker_Library_Brand_Test)
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

TEST_F(List_Items,Find_First_Item_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	bool a = list1.First(list1);
	EXPECT_TRUE(a);
}

TEST_F(List_Items,First_Item_Integration_Test) {
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

TEST_F(List_Items, Faker_Library_Name_Test)
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

TEST_F(List_Items, Delete_Repeated_Test) {
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

TEST_F(List_Items, Insert_Quantity_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].quantity, 2);
}

TEST_F(List_Items, Insert_CAtegory_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].category, "Snack");
}

TEST_F(List_Items, Insert_Brand_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.INSERT(insertItem, 0, list1);
	EXPECT_EQ(list1.dataArray[0].brand, "NoBrand");
}

TEST_F(List_Items, Delete_Quantity_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].quantity, -1);
}

TEST_F(List_Items, Delete_Category_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand");
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].category, "");
}

TEST_F(List_Items, Delete_Name_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.deleteElement(0, list1);
	EXPECT_EQ(list1.dataArray[0].name, "");
}

TEST_F(List_Items, Null_Name_Unit_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].name, "");
}

TEST_F(List_Items, Null_Quantity_test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].quantity, -1);
}

TEST_F(List_Items, Null_Brand_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].brand, "");
}

TEST_F(List_Items, Null_Category_Test) {
	List list1(1);
	item insertItem("Bisconi", "Snack", 2, "NoBrand"
	);
	list1.MakeNull(list1);
	EXPECT_EQ(list1.dataArray[0].category, "");
}

TEST_F(List_Items, first_item_found_Unit_test) {
	List list1(1);
	bool a = list1.First(list1);
	EXPECT_FALSE(a);
}

TEST_F(List_Items, Contcatination_Name_Unit_Test) {
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

TEST_F(List_Items, Contcatination_Quantity_Unit_Test) {
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


TEST_F(List_Items, Contcatination_Bran_Unit_Test) {
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
