#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class Price
{
public: 
	Price();

	Price(string* lines);

	void setName();
	void setStore();
	void setPrice();
	void edit();
	void print();
	void sale(int num);

	string getName();
	string getStore();
	int getPrice();

	friend ofstream& operator<< (ofstream& file, const Price& price){
		file << price.name << endl;
		file << price.store << endl;
		file << price.price << endl << endl;
		return file;
	}

private:
	string name;
	string store;
	int price;
};

