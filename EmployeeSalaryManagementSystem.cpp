#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Employee{
    int id;
    string name;
    int monthlySalary;
};

int main(){
    vector<Employee> employees;
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Employee e;
        cout << "\nEnter Employee ID: ";
        cin >> e.id;
        cout << "Enter Name: ";
        cin >> e.name;
        cout << "Enter Monthly Salary: ";
        cin >> e.monthlySalary;
        employees.push_back(e);
    }
     int limit;
    cout<< "\nEnter the4 yearly salary limit: ";
    cin>> limit;
    ofstream outFile("high_salary.txt");
    if (!outFile)
    {
    cout << "File not opened!";
        return 0;
    }

    for (int i = 0; i<employees.size(); i++)
    {
        int yearlySalary = employees[i].monthlySalary * 12;
           if (yearlySalary > limit)
        {
            outFile<<employees[i].id<<" "<<employees[i].name<<" "<<yearlySalary<<endl;
        }
    }
    outFile.close();
    ifstream inFile("high_salary.txt");
    if (!inFile)
    {
        cout << "File not opened!";
        return 0;
    }
    cout << "\nEmployees with High Salary:\n";
    int id, salary;
    string name;
     while (inFile >> id >> name >> salary)
    {
        cout<<"ID:"<<id<<"Name:"<<name<<"Yearly Salary:"<<salary<<endl;
    }

    inFile.close();
    return 0;
}
