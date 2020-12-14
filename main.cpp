#include "Abonent.h"
#include "Library.h"
#include "Sort.h"
#include <list>
#include <iostream>
#include <fstream>
#include <iomanip>


int main() {
	setlocale(LC_ALL, "rus");
	std::list <Tariff> tariff;
	Vector<Abonent> abonent;
	std::ifstream file;
	std::string nameOfStart;
	std::cout << "Введите название файла с входными данным: ";
	std::cin >> nameOfStart;
	file.open(nameOfStart, std::ios::in);

	if (!file.is_open())
	{
		std::cerr << "Ошибка открытия файла.\n";
		return 1;
	}

	while (!file.eof()) {
		Abonent c;
		file >> c;
		file.ignore(255, '\n');
			
		if (checkAbonent(c))
		{
			tariff.push_back(c.getAbonenttariff());
			abonent.push(c);
		}
		else {
			std::cout << "Неправильный формат ввода" << "\n";
			break;
		}

	}
	std::ofstream outf;
	std::string nameOfResult;
	std::cout << "Введите название файлf для вывода данных: ";
	std::cin >> nameOfResult;
	outf.open(nameOfResult, std::ios::out);
	if (!outf)
	{
		std::cerr << "Ошибка открытия файла.\n";
		return 1;
	}
	outf << "|" << std::setw(20) << "Surname" << "|" << std::setw(20) << "Phone number" << "| " << std::setw(20) << "Tariff name" << std::setw(20) << "Tariff code" << std::setw(20) << "Tariff cost" << "\n";

	for (int i = 0; i < abonent.size(); i++)
		outf << abonent[i] << "\n";

	std::cout << "|" << std::setw(20) << "Surname" << "|" << std::setw(20) << "Phone number" << "| " << std::setw(20) << "Tariff name" << std::setw(20) << "Tariff code" << std::setw(20) << "Tariff cost" << "\n";
	abonent.showVector();
	std::cout << "After sort" << "\n";
	outf << "After sort" << "\n";
	sort(abonent, compare <Abonent>());
	outf << "|" << std::setw(20) << "Surname" << "|" << std::setw(20) << "Phone number" << "| " << std::setw(20) << "Tariff name" << std::setw(20) << "Tariff code" << std::setw(20) << "Tariff cost" << "\n";

	for (int i = 0; i < abonent.size(); i++)
		outf << abonent[i] << "\n";
	
	std::cout << "|" << std::setw(20) << "Surname" << "|" << std::setw(20) << "Phone number" << "| " << std::setw(20) << "Tariff name" << std::setw(20) << "Tariff code" << std::setw(20) << "Tariff cost" << "\n";
	abonent.showVector();
	std::cout << "\n";

	for (auto iter = tariff.begin(); iter != tariff.end(); iter++)
	{
		std::cout << *iter << "\n";
	}
	return 0;
}