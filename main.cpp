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
        std::cout << "\n1. Додати працівника\n2. Вивести працівників за віком\n";
        std::cout << "3. Вивести працівників за прізвищем\n4. Показати повний список працівників\n";
        std::cout << "5. Скопіювати список працівників\n6. Зберегти та вийти\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addEmployee(employees, employeeCount);
            break;
        case 2:
            int targetAge;
            std::cout << "Введіть цільовий вік: ";
            std::cin >> targetAge;
            printEmployeesByAge(employees, employeeCount, targetAge);
            break;
        case 3:
            char targetLetter;
            std::cout << "Введіть цільову літеру для прізвища: ";
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
            std::cout << "Список працівників скопійовано.\n";
            break;
        }
        case 6:
            saveEmployeesToFile(employees, employeeCount, filename);
            break;
        default:
            std::cout << "Невірний вибір. Будь ласка, спробуйте ще раз.\n";
        }
    } while (choice != 6);

    return 0;
}
