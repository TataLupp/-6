#include "Abonent.h"
#include "String.h"
#include "Tariff.h"
#include <iostream>
#include <iomanip>

Abonent::Abonent() :
	surname_(),
	number_(),
	tariff_() {}

Abonent::Abonent(String x, String y, Tariff z) :
	surname_(x),
	number_(y),
	tariff_(z) {}

String Abonent::getAbonentname() const {
	return surname_;
}
String Abonent::getAbonentnumber() const {
	return number_;
}
Tariff Abonent::getAbonenttariff() const {
	return tariff_;
}

void Abonent::setAbonentname(String x) {
	surname_ = x;
}
void Abonent::setAbonentnumber(String y) {
	if (y.length() == 10)
		number_ = y;
}
void Abonent::setAbonenttariff(Tariff z) {
	tariff_ = z;
}

std::ostream& operator<<(std::ostream& stream, const Abonent& abonent) {
	return stream << "|" << std::setw(20) << abonent.surname_ << "|" << std::setw(20) << abonent.number_ << "|" << abonent.tariff_;
}

std::istream& operator>>(std::istream& stream, Abonent& abonent) {
	stream >> abonent.surname_;
	stream >> abonent.number_;
	stream >> abonent.tariff_;
	return stream;
}

bool Abonent::operator<(const Abonent& a)
{
	return surname_ < a.surname_;
}
bool operator>(const Abonent& a, const Abonent& b)
{
	return a.surname_ > b.surname_;
}
bool operator==(const Abonent& a, const Abonent& b)
{
	return b.number_ == a.number_;
}
bool operator!=(const Abonent& a, const Abonent& b)
{
	bool x = (b.number_ == a.number_);
	return !x;
}

Abonent& Abonent::operator= (const Abonent& abonent)
{
	if (this == &abonent)
	{
		return *this;
	}
	surname_ = abonent.surname_;
	number_ = abonent.number_;
	tariff_ = abonent.tariff_;
	return *this;
}
bool cmpNumber(const Abonent& abonent1, const Abonent& abonent2) {
	if (abonent1.number_ > abonent2.number_)
		return true;
	else return true;
}
bool cmpSurname(const Abonent& abonent1, const Abonent& abonent2) {
	if (abonent1.surname_ > abonent2.surname_)
		return true;
	else return true;
}
bool checkAbonent(const Abonent& abonent) {
	bool result = true;
	if (abonent.number_.length() != 10) result = false;
	for (int i = 0; i < 10; i++) {
		if (!isdigit(abonent.number_[i])) {
			result = false;
			break;
		}
	}
	return result;
}
bool checkName(const Abonent& abonent) {
	bool result = true;
	int length = abonent.surname_.length();
	if (isupper(abonent.surname_[0]) == 0) 	result = false;
	if (abonent.surname_[length - 3] != ' ') result = false;
	if (isupper(abonent.surname_[length - 1] == 0) || isupper(abonent.surname_[length - 2]) == 0) result = false;
	for (int i = 1; i < length - 3; i++) {
		if (islower(abonent.surname_[i]) == 0) {
			result = false;
			break;
		}
	}
	return result;
}
bool Abonent::checkTariff() const {
	if (checkCode(this->tariff_))
		return true;
	else return false;
}