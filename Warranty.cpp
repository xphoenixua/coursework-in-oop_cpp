#include "Warranty.h"
#include <iostream>
#include <string>

Warranty::Warranty()
{
}

Warranty::Warranty(std::string lserial_number, short int lpriority, std::string lcompany_name) :
	Task(lserial_number, lpriority)
	, company_name(lcompany_name)
{
}

Warranty::~Warranty()
{
}

void Warranty::setCompany(std::string lcompany_name)
{
	company_name = lcompany_name;
}

std::string Warranty::getCompany()const
{
	return company_name;
}

//демонстрація значень полів класу
void Warranty::show()const
{
	std::cout << "WARRANTY TASK";
	Task::show();
	std::cout << "\nCompany: " << company_name << '\n';
}

//введення значень полів класу
void Warranty::input()
{
	Task::input();
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "Enter company name: ";
	std::cin >> company_name;
}

//перевантаження оператора виведення потоку
std::ostream& operator<<(std::ostream& out, Warranty& lobject)
{
	out << lobject.serial_number << '\n' << lobject.priority << '\n' << lobject.company_name;
	return out;
}

//перевантаження оператора зчитування потоку
std::istream& operator>>(std::istream& in, Warranty& lobject)
{
	in >> lobject.serial_number >> lobject.priority >> lobject.company_name;
	return in;
}