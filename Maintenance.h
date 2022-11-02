#pragma once
#include "Task.h"

class Maintenance : public Task
{
private:
	double price;

public:
	Maintenance();
	Maintenance(std::string lserial_number, short int lpriority, double lprice);
	~Maintenance();
	void setPrice(double lprice);
	double getPrice()const;
	void show()const;
	void input();
	friend std::ostream& operator<<(std::ostream& out, Maintenance& lobject);
	friend std::istream& operator>>(std::istream& in, Maintenance& lobject);
};