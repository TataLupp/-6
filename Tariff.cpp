#include "String.h"
#include "Tariff.h"
#include <iostream>
#include <iomanip>

Tariff::Tariff() :
	name_(),
	code_(),
	cost_(0) {}

Tariff::Tariff(String name, String code, int cost) :
	name_(name),
	code_(code),
	cost_(cost) {}

String Tariff::getTariffname() {
	return name_;
}
String Tariff::getTariffcode() {
	return code_;
}
int Tariff::getTariffcost() {
	return cost_;
}
void Tariff::setTariffname(String x) {
	name_ = x;
}
void Tariff::setTariffcode(String x) {
	code_ = x;
}
void Tariff::setTariffcost(int z) {
	cost_ = z;
}

void Tariff::print() {

	std::cout << name_ << " " << code_ << " " << cost_;
}

std::ostream& operator<<(std::ostream& stream, const Tariff& tariff) {
	setlocale(LC_ALL, "rus");
	return stream << std::setw(20) << tariff.name_ << "|" << std::setw(20) << tariff.code_ << "|" << std::setw(20) << tariff.cost_ ;
}

std::istream& operator>>(std::istream& stream, Tariff& tariff) {
	stream >> tariff.name_;
	stream >> tariff.code_;
	stream >> tariff.cost_;
	return stream;
}
