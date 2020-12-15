#include "Abonent.h"
#include "Library.h"
#include "Sort.h"
#include <fstream>
#include <iomanip>


int main() {
	setlocale(LC_ALL, "rus");
	Vector <Tariff> tariff;
	Vector<Abonent> abonent;
	std::ifstream file;
	std::string nameOfStart;
	std::cout << "Введите название файла с входными данным: ";
	std::cin >> nameOfStart;  //файл с входными данными start.txt, файлы с ошибками exc1.txt exc2.txt exc3.txt 
	file.open(nameOfStart, std::ios::in);
	std::ofstream outf;
	std::string nameOfResult;
	std::cout << "Введите название файла для вывода данных: ";
	std::cin >> nameOfResult;  //файл для вывода result.txt
	if (!file.is_open())
	{
		std::cerr << "Ошибка открытия файла.\n";
		return 1;
	}
	while (!file.eof()) {
		Abonent c;
		file >> c;
		file.ignore(255, '\n');
		if (checkAbonent(c) && checkName(c) && c.checkTariff())
		{
			tariff.push(c.getAbonenttariff());
			abonent.push(c);
		}
		else {
			std::cout << "Неправильный формат ввода" << "\n";
			break;
		}
	}
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
	sort(tariff, compare <Tariff>());
	std::cout << "List of tariffs" << "\n";
	std::cout << std::setw(20) << "Tariff name" << std::setw(20) << "Tariff code" << std::setw(20) << "Tariff cost" << "\n";
	std::cout << tariff[0] << "\n";
	for (int i = 1; i < tariff.size(); i++)
	{		
		if(!(tariff[i-1]==tariff[i]))
		std::cout << tariff[i] << "\n";
	}
	outf.close();
	file.close();
	return 0;
}