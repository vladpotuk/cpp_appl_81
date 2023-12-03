#include "employee.h"
#include <iostream>

int main() {
    system("chcp 1251");
    system("cls");
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    std::string filename = "employees.txt";

    loadEmployeesFromFile(employees, employeeCount, filename);

    int choice;
    do {
        std::cout << "\n1. ������ ����������\n2. ������� ���������� �� ����\n";
        std::cout << "3. ������� ���������� �� ��������\n4. �������� ������ ������ ����������\n";
        std::cout << "5. ��������� ������ ����������\n6. �������� �� �����\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(employees, employeeCount);
            break;
        case 2:
            int targetAge;
            std::cout << "������ �������� ��: ";
            std::cin >> targetAge;
            printEmployeesByAge(employees, employeeCount, targetAge);
            break;
        case 3:
            char targetLetter;
            std::cout << "������ ������� ����� ��� �������: ";
            std::cin >> targetLetter;
            printEmployeesByLastName(employees, employeeCount, targetLetter);
            break;
        case 4:
            displayFullList(employees, employeeCount);
            break;
        case 5: {
            const int MAX_COPY_EMPLOYEES = 100;
            Employee copiedEmployees[MAX_COPY_EMPLOYEES];
            int copiedCount = 0;
            copyEmployeeList(employees, employeeCount, copiedEmployees, copiedCount);
            std::cout << "������ ���������� ����������.\n";
            break;
        }
        case 6:
            saveEmployeesToFile(employees, employeeCount, filename);
            break;
        default:
            std::cout << "������� ����. ���� �����, ��������� �� ���.\n";
        }
    } while (choice != 6);

    return 0;
}
