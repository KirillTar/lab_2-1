#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <iomanip>

#include "Keeper.h"
#include "Price.h"

Keeper::Keeper(){}

Keeper::~Keeper()
{
	delete[] catalog;
	catalogSize = 0;
	cout << "Каталог очищен";
	_getch();
}

void Keeper::add(Price* product) {
	Price** newList = new Price * [catalogSize + 1];

	for (int i = 0; i < catalogSize; i++) {
		newList[i] = catalog[i];
	}

	newList[catalogSize++] = product;
	delete[]catalog;
	catalog = newList;
}

void Keeper::del(int num) {

	Price** newCatalog = new Price * [catalogSize - 1];
	int i_new = 0;

	for (int i = 0; i < catalogSize; i++) {
		if (i == num) continue;

		newCatalog[i_new] = catalog[i];
		i_new++;
	}

	delete[] catalog;
	catalog = newCatalog;
	catalogSize--;
}

int Keeper::nameComparator(int i, int j)
{
	return _stricmp(catalog[i]->getName().c_str(), catalog[j]->getName().c_str());
}

void Keeper::sort() {
	Price* swtch;

	for (int i = 0; i < catalogSize - 1; i++)
	{
		for (int j = i + 1; j < catalogSize; j++)
		{
			if (nameComparator (i, j) > 0) 
			{
				swtch = catalog[i];
				catalog[i] = catalog[j];
				catalog[j] = swtch;
			}
		}
	}
}

void Keeper::save() {

	ofstream fout;

	fout.open(fileName);
	try
	{
		if (!fout.is_open())
			throw exception("Не удалось открыть файл.");

		for (size_t i = 0; i < catalogSize; i++)
		{
			fout << *catalog[i];
		}
		cout << "Сохранено!";
		fout.close();

		cout << endl << "Нажмите любую клавишу";
		_getch();
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка!";
	}
}

void Keeper::load() {

	string line;

	ifstream fin(fileName);

	try
	{
		const int linesAmount = 4;

		if (!fin.is_open()) 
			throw exception("Не удалось открыть файл.");

		char* s = new char[1024];
		int linesCounter = 0;

		while (!fin.eof()) {
			fin.getline(s, '\n');
			linesCounter++;
		}
		linesCounter--;

		/*int linesCounter = count(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>(), '\n');*/
		if (linesCounter <= 0 || linesCounter % linesAmount != 0)
		{
			cout << linesCounter << endl;
			throw exception("Файл поврежден!");
		}
			
		fin.clear();
		fin.seekg(ios::beg);

		int lineNum = 0;
		Price** newCatalog = new Price * [(int)linesCounter / linesAmount];
		string lines[linesAmount ];

		while (getline(fin, line))
		{
			string str = line;
			lines[(lineNum++) % linesAmount] = str;
			int i = lineNum / linesAmount - 1;

			if (lineNum % linesAmount == 0) {
				newCatalog[i] = new Price(lines);
			}
		}

		delete[]catalog;
		catalog = newCatalog;
		catalogSize = (int)linesCounter / linesAmount;

		cout << "Загружено!";
	}
	catch (const exception& err)
	{
		cout << err.what() << endl;
	}
	catch (...)
	{
		cout << "Неизвестная ошибка!";
	}

	fin.close();

	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню" << endl;
	cin.get();

}

void Keeper::print()
{
	for (int i = 0; i < catalogSize; i++) {
		catalog[i]->print();
		cout << endl;
	}
}

Price** Keeper::getCatalog() {
	return catalog;
}

size_t Keeper::getSize() {
	return catalogSize;
}