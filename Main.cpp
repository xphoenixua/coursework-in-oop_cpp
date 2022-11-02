#include "Container.h"
#include "Task.h"
#include "Warranty.h"
#include "Maintenance.h"
#include <iostream>

int main()
{
	int i;
	Container* priority_queue = new Container;
	Task* w = new Warranty;
	Task* m = new Maintenance;

	do
	{
		system("cls");
		std::cout << "-----MENU-----\n";
		std::cout << "<1>.Create warranty repair task\n";
		std::cout << "<2>.Create maintanance work task\n";
		std::cout << "<3>.Show all tasks\n";
		std::cout << "<4>.Pop task\n";
		std::cout << "<5>.Remove all tasks\n";
		std::cout << "<6>.Save to file\n";
		std::cout << "<7>.Load from file\n";
		std::cout << "<8>.Do the request\n";
		std::cout << "<9>.Quit\n";

		std::cin >> i;
		switch (i)
		{
			case 1:
			{
				system("cls");
				Task* w = new Warranty;
				w->input();
				priority_queue->push(w);
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				Task* m = new Maintenance;
				m->input();
				priority_queue->push(m);
				system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				priority_queue->show_all();
				system("pause");
				break;
			}
			case 4:
			{
				system("cls");
				priority_queue->pop();
				system("pause");
				break;
			}
			case 5:
			{
				system("cls");
				priority_queue->pop_all();
				system("pause");
				break;
			}
			case 6:
			{
				system("cls");
				priority_queue->outputFile();
				system("pause");
				break;
			}
			case 7:
			{
				system("cls");
				priority_queue->inputFile();
				system("pause");
				break;
			}
			case 8:
			{
				system("cls");
				int count = priority_queue->query();
				std::cout << "Query result: " << count << '\n';
				system("pause");
				break;
			}
			default:
			{
				//виняткова ситуація у меню
				if (i < 1 || i > 9)
				{
					std::cout << "\nInvalid choice. Try again.\n";
					std::cin.clear();
					std::cin.ignore(256, '\n');
					system("pause");
				}
				break;
			}
		}
	}
	while (i != 9);

	//звільнення пам’яті
	delete w;
	delete m;
	delete priority_queue;
	return 0;
}