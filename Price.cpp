#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <conio.h>

#include "Price.h"
using namespace std;

Price::Price ()
{
setName();
setStore();
setPrice();
}

Price::Price(string* lines) {
	name = lines[0];
	store = lines[1];
	price = stoi(lines[2]);
}


void Price::setName() {
	cout << "������������: ";
	getline(cin, name);
}

void Price::setStore() {
	cout << "��������: ";
	getline(cin, store);
}

void Price::setPrice() {
	cout << "����: ";
	cin >> price;
	cin.ignore();
}

string Price::getName() {
	return name;
}

string Price::getStore() {
	return store;
}

int Price::getPrice() {
	return price;
}

void Price::edit() {

	int def;
	cout << endl << endl << "�������:" << endl << "1-3. ����� ���� ��� ��������������" << endl << "4. ���� ������" << endl << "0. �����" << endl << "����:";
	cin >> def;
	cin.ignore();

	switch (def)
	{
	case 1:
		setName();
		break;
	case 2:
		setStore();
		break;
	case 3:
		setPrice();
		break;
	case 4:
		setName();
		setStore();
		setPrice();
		break;
	case 0:
		break;
	default:
		break;
	}
}

void Price::print() {
	cout.width(25); cout << left << "//1.������������: ";
	cout.width(15); cout << right << name;
	cout << "//" << endl;
	cout.width(25); cout << left << "//2.��������: ";
	cout.width(15); cout << right << store;
	cout << "//" << endl; 
	cout.width(25); cout << left << "//3.����: ";
	cout.width(15); cout << right << price;
	cout << "//" << endl;
}

void Price::sale(int num) {
	price = price * (100 - num)/ 100;
}