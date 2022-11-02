#include "Container.h";
#include "Warranty.h"
#include "Maintenance.h"
#include <iostream>
#include <fstream>

Container::Container() : head(NULL)
{
}

Container::~Container()
{
    if (head != NULL)
    {
        Node* curr_node = head;
        Node* next = NULL;

        while (curr_node != NULL)
        {
            next = curr_node->next;
            delete curr_node;
            curr_node = next;
        }
    }
}

//Перевірити чи контейнер пустий
bool Container::isEmpty()
{
    if (head == NULL)
    {
        std::cout << "No tasks. The container is empty.\n";
        return true;
    }
    else
        return false;
}

//додавання елемента у контейнер
void Container::push(Task* lobject)
{
    Node* temp = head;
    Node* new_node = new Node;
    new_node->object = lobject;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    if (*(head->object) > *lobject)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        while (temp->next != NULL && *(temp->next->object) < *lobject)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

//видалення елемента із контейнера
void Container::pop()
{
    if (isEmpty())
        return;

    Node* pop_node = head;
    head = head->next;
    delete pop_node;
}

//видалення усіх елементів контейнера
void Container::pop_all()
{
    if (isEmpty())
        return;

    while (head != NULL)
        this->pop();
    std::cout << "All tasks have been removed.\n";
}

//демонстрація усіх елементів контейнера на екран
void Container::show_all()
{
    if (isEmpty())
        return;

    Node* curr_node = head;
    while (curr_node != NULL)
    {
        curr_node->object->show();
        std::cout << '\n';
        curr_node = curr_node->next;
    }
}

//введення імені файлу та його перевірка згідно формату
std::string Container::enter_fileName()
{
    std::string file_name;
    std::cout << "*file_name*.dat: ";
    std::cin >> file_name;
    while (file_name.find(".dat") == std::string::npos || file_name.length() < 5
        || file_name.substr(file_name.length() - 4) != ".dat")
    {
        std::cout << "Try entering again.\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "*file_name*.dat: ";
        std::cin >> file_name;
    }
    return file_name;
}

//вивід вмісту контейнера у файл
void Container::outputFile()
{
    if (this->isEmpty())
        return;

    std::string file_name;
    file_name = enter_fileName();
    std::ofstream out(file_name);

    if (!out.is_open())
    {
        std::cout << "\nError opening file.\n";
        return;
    }
    else
    {
        Node* curr_node = head;
        while (curr_node != NULL)
        {
            if (typeid(*(curr_node->object)) == typeid(Warranty))
            {
                out << '\n' << 1 << '\n';
                out << (*((Warranty*)(curr_node->object)));
            }
            else if (typeid(*(curr_node->object)) == typeid(Maintenance))
            {
                out << '\n' << 2 << '\n';
                out << (*((Maintenance*)(curr_node->object)));
            }
            curr_node = curr_node->next;
        }
        std::cout << "\nTasks have been successfully written.\n";
        out.close();
    }
}

//зчитування із файлу
void Container::inputFile()
{
    std::string file_name;
    file_name = enter_fileName();
    std::ifstream in(file_name);

    if (!in.is_open())
    {
        std::cout << "\nError opening file.\n";
        return;
    }
    else
    {
        int k, count = 0;
        while (!in.eof())
        {
            if (count == 0)
                in.ignore(1, '\n');
            in >> k;
            if (k == 1)
            {
                Warranty* object = new Warranty();
                in >> (*object);
                this->push(object);
                count++;
            }
            else if (k == 2)
            {
                Maintenance* object = new Maintenance();
                in >> (*object);
                this->push(object);
                count++;
            }
        }
        std::cout << "\nTasks have been successfully read.\n";
        in.close();
        return;
    }
}

//виконання запиту користувача згідно із варіантом у курсовій роботі
int Container::query()
{
    if (this->isEmpty())
        return 0;

    std::string company_name;
    Node* curr_node = head;
    int count = 0;
    std::cout << "Number of warranty tasks by company name\n";
    std::cout << "Enter company name: ";
    std::cin >> company_name;
    while (std::cin.fail())
    {
        std::cout << "Try entering again\n";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Enter company name: ";
        std::cin >> company_name;
    }
    while (curr_node != NULL)
    {
        if (typeid(*(curr_node->object)) == typeid(Warranty))
        {
            if (((Warranty*)(curr_node->object))->getCompany() == company_name)
                count++;
        }
        curr_node = curr_node->next;
    }
    return count;
}