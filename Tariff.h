#pragma once
#include "String.h"
#include <string>

class Tariff {

public:
	Tariff();
	Tariff(String name, String code, int cost);
	String getTariffname();
	String getTariffcode();
	int getTariffcost();

	void setTariffname(String x);
	void setTariffcode(String y);
	void setTariffcost(int z);
	
	void print();
	friend std::ostream& operator<<(std::ostream&, const Tariff&);
	friend std::istream& operator>>(std::istream&, Tariff&);
private:
	String name_;
	String code_;
	int cost_;
};
