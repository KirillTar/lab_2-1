#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "Keeper.h"
#include "Price.h"

using namespace std;

Keeper keeper;

bool Empty() {
	if (!keeper) return false;

	cout << "Список товаров пуст" << endl;
	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню" << endl;
	_getch();
		
	return true;
}

void catalogPrint() {
	if (Empty()) return;

	keeper.sort();
	keeper.print();

	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню" << endl;
	_getch();
}

void searchLoop() {
	if (Empty()) return;

	int namesAmount = 0;
	string name;

	cout << "Введите наименование: ";
	getline(cin, name);

	keeper.sort();

	for (size_t i = 0; i < keeper.getSize(); i++) {
		string wantedName = keeper.getCatalog()[i]->getName();
		if (wantedName == name) {
			keeper.getCatalog()[i]->print();
			namesAmount++;
		}
	}

	if (!namesAmount) {
		cout << endl << endl << "Ничего не найдено" << endl;
	}

	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню" << endl;
	_getch();
}

void saleLoop() {
	if (Empty()) return;

	int namesAmount = 0;
	string name;
	int salePercentage;

	cout << "Введите наименование: ";
	getline(cin, name);

	cout << "Введите скидку в процентах: ";
	cin >> salePercentage;
	cin.ignore();

	keeper.sort();

	for (size_t i = 0; i < keeper.getSize(); i++) {
		string wantedName = keeper.getCatalog()[i]->getName();
		if (wantedName == name) {
			cout << endl << "Старая цена: " << endl;
			keeper.getCatalog()[i]->print();
			keeper.getCatalog()[i]->sale(salePercentage);
			cout << endl <<"Новая цена: " << endl ;
			keeper.getCatalog()[i]->print();
			namesAmount++;
		}
	}

	if (!namesAmount) {
		cout << endl << endl << "Ничего не найдено" << endl;
	}

	cout << endl << "Нажмите любую клавишу чтобы вернутся в меню" << endl;
	_getch();
}

void editLoop() {
	if (Empty()) return;

	while (true) {
		system("@cls||clear");

		for (int i = 0; i < keeper.getSize(); i++) {
			cout << "Номер: " << (i + 1) << endl;
			keeper.getCatalog()[i]->print();
			cout << endl;
		}

		int num;

		cout << "Введите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > keeper.getSize()) {
			cout << endl << "Такого объекта нет" << endl;

			cout << endl << "Нажмите любую клавишу";
			_getch();

			continue;
		};

		system("@cls||clear");
		keeper.getCatalog()[num - 1]->print();
		keeper.getCatalog()[num - 1]->edit();
		return;
	}
}

void removeLoop() {
	if (Empty()) return;
	while (true) {
		system("@cls||clear");

		for (int i = 0; i < keeper.getSize(); i++) {
			cout << "Номер: " << (i + 1) << endl;
			keeper.getCatalog()[i]->print();
			cout << endl;
		}

		int num;

		cout << "Введите номер объекта: ";
		cin >> num;
		cin.ignore();

		if (num < 1 || num > keeper.getSize()) {
			cout << endl << "Такого объекта нет" << endl;

			cout << endl << "Нажмите любую клавишу";
			_getch();

			continue;
		};

		system("@cls||clear");
		keeper.del(num - 1);
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {

		cout << "1. Открыть список объектов" << endl;
		cout << "2. Добавить объект" << endl;
		cout << "3. Редактировать объект" << endl;
		cout << "4. Удалить объект" << endl;
		cout << "5. Удалить все объекты" << endl;
		cout << "6. Сохранить" << endl;
		cout << "7. Загрузить" << endl;
		cout << "8. Найти объект по наименованию" << endl;
		cout << "9. Применить скидку к товару" << endl;
		cout << "0. Выход" << endl;

		cout << "Номер команды:";
		int command;
		cin >> command;
		cin.ignore();

		system("@cls||clear");

		switch (command)
		{
		case 1:
			catalogPrint();
			break;
		case 2:
			keeper.add(new Price());
			break;
		case 3:
			editLoop();
			break;
		case 4:
			removeLoop();
			break;
		case 5:
			keeper.~Keeper();
			break;
		case 6:
			keeper.save();
			break;
		case 7:
			keeper.load();
			break;
		case 8: 
			searchLoop();
			break;
		case 9:
			saleLoop();
			break;
		case 0:
			exit(0);
		default:
			break;
		}
		system("@cls||clear");
	}

}

