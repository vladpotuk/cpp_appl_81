#include "employee.h"
#include <iostream>
#include <fstream>

void Employee::printInfo() const {
    std::cout << "��'�: " << firstName << " " << lastName << ", ³�: " << age << std::endl;
}

void addEmployee(Employee* employees, int& count) {
    Employee newEmployee;
    std::cout << "������ ��'�: ";
    std::cin >> newEmployee.firstName;
    std::cout << "������ �������: ";
    std::cin >> newEmployee.lastName;
    std::cout << "������ ��: ";
    std::cin >> newEmployee.age;

    employees[count++] = newEmployee;
}

void printEmployeesByAge(const Employee* employees, int count, int targetAge) {
    for (int i = 0; i < count; ++i) {
        if (employees[i].age == targetAge) {
            employees[i].printInfo();
        }
    }
}

void printEmployeesByLastName(const Employee* employees, int count, char targetLetter) {
    for (int i = 0; i < count; ++i) {
        if (!employees[i].lastName.empty() && employees[i].lastName.front() == targetLetter) {
            employees[i].printInfo();
        }
    }
}

void saveEmployeesToFile(const Employee* employees, int count, const std::string& filename) {
    std::ofstream outputFile(filename);

    for (int i = 0; i < count; ++i) {
        outputFile << employees[i].firstName << " " << employees[i].lastName << " " << employees[i].age << std::endl;
    }

    outputFile.close();
}

void loadEmployeesFromFile(Employee* employees, int& count, const std::string& filename) {
    std::ifstream inputFile(filename);

    Employee employee;
    while (inputFile >> employee.firstName >> employee.lastName >> employee.age) {
        employees[count++] = employee;
    }

    inputFile.close();
}

void displayFullList(const Employee* employees, int count) {
    std::cout << "\n������ ������ ����������:\n";
    for (int i = 0; i < count; ++i) {
        employees[i].printInfo();
    }
}

void copyEmployeeList(const Employee* source, int sourceCount, Employee* destination, int& destinationCount) {
    for (int i = 0; i < sourceCount; ++i) {
        destination[i] = source[i];
    }
    destinationCount = sourceCount;
    std::cout << "������ ���������� ����������.\n";
}
