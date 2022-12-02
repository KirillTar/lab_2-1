#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "Price.h"

using namespace std;

class Keeper
{
public:

	Keeper();
	~Keeper();

	void add(Price* product);
	void del(int number);
	void sort();
	void save();
	void load();
	void print();
	int nameComparator(int i, int j);

	size_t getSize();

	Price** getCatalog() ;

	friend const bool operator! (Keeper& keeper)
	{
		return (bool) keeper.getSize();
	}

private:
	Price** catalog = {};
	size_t catalogSize = 0;
	string fileName = "catalog.txt";
};


