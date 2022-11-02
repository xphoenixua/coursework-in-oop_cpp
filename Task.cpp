#include "Task.h"
#include <iostream>
#include <string>

Task::Task()
{
}

Task::Task(std::string lserial_number, short int lpriority) :
    serial_number(lserial_number)
	, priority(lpriority)
{
}

Task::~Task()
{
}

void Task::setSerial(std::string lserial_number)
{
    serial_number = lserial_number;
}

std::string Task::getSerial()const
{
	return serial_number;
}

void Task::setPriority(short int lpriority)
{
    priority = lpriority;
}

unsigned short int Task::getPriority()const
{
	return priority;
}

//демонстрація значень полів класу
void Task::show()const
{
	std::cout << "\nSerial number: " << serial_number;
	std::cout << "\nPriority: " << priority;
}

//введення значень полів класу
void Task::input()
{
    std::cout << "Enter serial number: ";
    std::cin >> serial_number;
    std::cout << "Enter its priority in weeks: ";
    try
    {
        std::cin >> priority;
        if (std::cin.fail() || priority < 0)
            throw (priority);
        else
            return;
    }
    catch (short int exc_priority)
    {
        while (std::cin.fail() || exc_priority < 0)
        {
            std::cout << "Try entering again.\n";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Enter its priority in weeks: ";
            std::cin >> exc_priority;
            setPriority(exc_priority);
        }
    }
}

//перевантаження оператора порівняння <
bool operator<(Task& lobject1, Task& lobject2)
{
    if (lobject1.priority < lobject2.priority)
        return true;
    else
        return false;
}

//перевантаження оператора порівняння >
bool operator>(Task& lobject1, Task& lobject2)
{
    if (lobject1.priority > lobject2.priority)
        return true;
    else
        return false;
}