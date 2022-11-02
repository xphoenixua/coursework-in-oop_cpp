#pragma once
#include <string>

//батьківський абстрактний клас для похідних Warranty та Maintenance
class Task
{
protected:
	std::string serial_number;
	short int priority;

public:
	Task();
	Task(std::string lserial_number, short int lpriority);
	virtual ~Task();
	void setSerial(std::string lserial_number);
	std::string getSerial()const;
	void setPriority(short int lpriority);
	unsigned short int getPriority()const;
	virtual void show()const;
	virtual void input();
	friend bool operator<(Task& lobject1, Task& lobject2);
	friend bool operator>(Task& lobject1, Task& lobject2);
};