#include "pch.h"
#include "ParameterizedTest.h"
#include "../Project5/List.h"

class PT1 :public ::testing::TestWithParam<int> {

protected:
	void SetUp() override {
		item itm = item("Bisconi", "Snack", 2, "B&B");
		listToTest.INSERT(itm, 0, listToTest);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		listToTest.INSERT(itm1, 1, listToTest);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		listToTest.INSERT(itm2, 2, listToTest);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		listToTest.INSERT(itm3, 3, listToTest);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm4, 4, listToTest);
		item itm5 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm5, 5, listToTest);
	}
	List listToTest = List(6);

};
TEST_P(PT1, DeleteParametizedTest) {
	int index = GetParam();
	ASSERT_TRUE(listToTest.deleteElement(index, listToTest));
}

INSTANTIATE_TEST_CASE_P(
	DeleteParametizedTest,
	PT1,
	::testing::Values(0, 1, 2, 3, 4
	));

class PT2 :public ::testing::TestWithParam<int> {

protected:
	void SetUp() override {
		item itm = item("Bisconi", "Snack", 2, "B&B");
		listToTest.INSERT(itm, 0, listToTest);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		listToTest.INSERT(itm1, 1, listToTest);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		listToTest.INSERT(itm2, 2, listToTest);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		listToTest.INSERT(itm3, 3, listToTest);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm4, 4, listToTest);
		item itm5 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm5, 5, listToTest);
	}
	List listToTest = List(6);

};
TEST_P(PT2, PreviousItemParametizedTest) {
	int index = GetParam();
	ASSERT_TRUE(listToTest.Next(index, listToTest));
}

INSTANTIATE_TEST_CASE_P(
	PreviousItemParametizedTest,
	PT2,
	::testing::Values(0, 1, 2, 3, 4
	));
class PT3 :public ::testing::TestWithParam<int> {

protected:
	void SetUp() override {
		item itm = item("Bisconi", "Snack", 2, "B&B");
		listToTest.INSERT(itm, 0, listToTest);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		listToTest.INSERT(itm1, 1, listToTest);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		listToTest.INSERT(itm2, 2, listToTest);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		listToTest.INSERT(itm3, 3, listToTest);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm4, 4, listToTest);
		item itm5 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm5, 5, listToTest);
	}
	List listToTest = List(6);

};
TEST_P(PT3, NextItemParametizedtest) {
	int index = GetParam();
	ASSERT_TRUE(listToTest.Next(index, listToTest));
}

INSTANTIATE_TEST_CASE_P(
	NextItemParametizedtest,
	PT3,
	::testing::Values(0, 1, 2, 3, 4
	));
class PT4 :public ::testing::TestWithParam<int> {

protected:
	void SetUp() override {
		item itm = item("Bisconi", "Snack", 2, "B&B");
		listToTest.INSERT(itm, 0, listToTest);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		listToTest.INSERT(itm1, 1, listToTest);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		listToTest.INSERT(itm2, 2, listToTest);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		listToTest.INSERT(itm3, 3, listToTest);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm4, 4, listToTest);
	}
	List listToTest = List(5);

};
TEST_P(PT4, ReterievedataParametizedtest) {
	int index = GetParam();
	ASSERT_TRUE(listToTest.Retrieve(index, listToTest));
}

INSTANTIATE_TEST_CASE_P(
	ReterievedataParametizedtest,
	PT4,
	::testing::Values(0, 1, 2, 3, 4
	));
class PT5 :public ::testing::TestWithParam<string> {

protected:
	void SetUp() override {
		item itm = item("Bisconi", "Snack", 2, "B&B");
		listToTest.INSERT(itm, 0, listToTest);
		item itm1 = item("Tomato sauce", "Ketcup", 2, "kutny");
		listToTest.INSERT(itm1, 1, listToTest);
		item itm2 = item("Barbecue sauce", "Ketcup", 3, "Mitchels");
		listToTest.INSERT(itm2, 2, listToTest);
		item itm3 = item("Whole-grain or multigrain cereals", "Flour", 10, "DESI");
		listToTest.INSERT(itm3, 3, listToTest);
		item itm4 = item("Frozen shrimp", "Sea Food", 25, "F&F");
		listToTest.INSERT(itm4, 4, listToTest);
	}
	List listToTest = List(5);

};
TEST_P(PT5, LocateItemParametizedtest) {
	string name = GetParam();
	ASSERT_TRUE(listToTest.Locate(name, listToTest));
}

INSTANTIATE_TEST_CASE_P(
	LocateItemParametizedtest,
	PT5,
	::testing::Values(
		"Bisconi", "Tomato sauce", "Barbecue sauce", "Whole-grain or multigrain cereals", "Frozen shrimp"
	));
	