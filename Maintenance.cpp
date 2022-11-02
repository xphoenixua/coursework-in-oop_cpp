#include "Maintenance.h"
#include <iostream>
#include <string>

Maintenance::Maintenance()
{
}

Maintenance::Maintenance(std::string lserial_number, short int lpriority, double lprice) :
	Task(lserial_number, lpriority)
	, price(lprice)
{
}

Maintenance::~Maintenance()
{
}

void Maintenance::setPrice(double lprice)
{
	price = lprice;
}

double Maintenance::getPrice()const
{
	return price;
}

//демонстрація значень полів класу
void Maintenance::show()const
{
	std::cout << "MAINTENANCE TASK";
	Task::show();
	std::cout << "\nPrice: " << price << '\n';
}

//введення значень полів класу
void Maintenance::input()
{
	Task::input();
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "Enter price: ";
    try
    {
        std::cin >> price;
        if (std::cin.fail() || price < 0)
            throw (price);
        else
            return;
    }
    catch (double exc_price)
    {
        while (std::cin.fail() || exc_price < 0)
        {
            std::cout << "Try entering again.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Enter price: ";
            std::cin >> exc_price;
            setPrice(exc_price);
        }
    }
}

//перевантаження оператора виведення потоку
std::ostream& operator<<(std::ostream& out, Maintenance& lobject)
{
	out << lobject.serial_number << '\n' << lobject.priority << '\n' << lobject.price;
	return out;
}

//перевантаження оператора зчитування потоку
std::istream& operator>>(std::istream& in, Maintenance& lobject)
{
	in >> lobject.serial_number >> lobject.priority >> lobject.price;
	return in;
}