#pragma once
#include <string>
#include <iostream>
//#include "../Project5/Source.cpp"
using namespace std;

// TODO: This is an example of a library function
string FakerNameGenerator()
{
    const char* name[10]
           = { "Tomato sauce","Mustard Barbecue sauce","Red - wine vinegar","Salsa","Extra virgin olive oil","canola oil", "nonfat cooking spray","Jarred capers and olives","Hot pepper sauce","Blue & band"};
    return name[(rand() % 10)];
}
string FakerCategoryGenerator()
{
    const char* name[10]
        = { "Meat", "Yougart", "olive Oil", "Flour", "Butter", "Sea food", "Tea", "Rice","solid items", "Liquid items" };
    return name[(rand() % 10)];
}
string FakerBrandGenerator()
{
    const char* name[10]
        = { "Blue and band", "Red bull", "Pakistan Rice", "Karachi Fish", "Orange Planet", "Cofee planet", "chatta", "Butt Karahi","Islamabad Food", "Sara collection" };
    return name[(rand() % 10)];
}
int Fakerquantitygenerator()
{
    
    return (rand() % 10);
}
