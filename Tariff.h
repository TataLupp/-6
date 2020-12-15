#pragma once
#include "String.h"
#include <string>

class Tariff {

public:
	Tariff();
	Tariff(String name, String code, int cost);
	~Tariff() = default;
	String getTariffname() const;
	String getTariffcode() const;
	int getTariffcost() const;

	void setTariffname(String x);
	void setTariffcode(String y);
	void setTariffcost(int z);

	void print() const;
	friend std::ostream& operator<<(std::ostream&, const Tariff&);
	friend std::istream& operator>>(std::istream&, Tariff&);
	friend bool operator==(const Tariff& a, const Tariff& b);
	friend bool operator>(const Tariff& a, const Tariff& b);
	friend bool checkCode(const Tariff& tariff);
private:
	String name_;
	String code_;
	int cost_;
};
