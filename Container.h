#pragma once
#include "Task.h"
#include <string>

//�����, �� ������ � ����� ����� �������� �� �ᒺ�� ������������ �����
struct Node
{
public:
    Task* object;
    Node* next;
};

class Container
{
private:
    Node* head;

public:
    Container();
    ~Container();
    bool isEmpty();
    void push(Task* lobject);
    void pop();
    void pop_all();
    void show_all();
    std::string enter_fileName();
    void outputFile();
    void inputFile();
    int query();
};