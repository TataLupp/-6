#pragma once
#include "String.h"
#include "Tariff.h"

class Abonent {
public:
	Abonent();
	Abonent(String x, String y, Tariff z);

	String getAbonentname();
	String getAbonentnumber();
	Tariff getAbonenttariff();

	void setAbonentname(String x);
	void setAbonentnumber(String y);
	void setAbonenttariff(Tariff z);
	friend bool checkAbonent(const Abonent&);
	
	friend std::ostream& operator<<(std::ostream&, const Abonent&);
	friend std::istream& operator>>(std::istream&, Abonent&);

	Abonent& operator= (const Abonent& abonent);
	friend bool operator== (const Abonent&, const Abonent&);
	friend bool operator!= (const Abonent&, const Abonent&);
	bool operator< (Abonent);
	friend bool operator>(const Abonent& a, const Abonent& b);
	friend bool cmpNumber(const Abonent&, const Abonent&);
	friend bool cmpSurname(const Abonent&, const Abonent&);

private:
	String surname_;
	String number_;
	Tariff tariff_;

};