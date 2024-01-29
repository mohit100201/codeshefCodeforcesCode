#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int salary;
    Employee(int i, int s)
    {
        id = i;
        salary = s;
    }
    Employee()
    {
        cout << "base class default constructor called " << endl;
    }
};

class Programmer : public Employee
{
public:
    Programmer(int i, int s)
    {
        cout << "derived class constructor called " << endl;
        id = i;
        salary = s;
    }
};

int main()
{

    Programmer mohit(1, 10000);
    cout << mohit.id << endl;
    cout << mohit.salary << endl;

    return 0;
}