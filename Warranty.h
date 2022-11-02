#pragma once
#include "Task.h"
#include <iostream>
#include <string>

class Warranty : public Task
{
private:
	std::string company_name;

public:
	Warranty();
	Warranty(std::string lserial_number, short int lpriority, std::string lcompany_name);
	~Warranty();
	void setCompany(std::string lcompany_name);
	std::string getCompany()const;
	void show()const;
	void input();
	friend std::ostream& operator<<(std::ostream& out, Warranty& lobject);
	friend std::istream& operator>>(std::istream& in, Warranty& lobject);
};