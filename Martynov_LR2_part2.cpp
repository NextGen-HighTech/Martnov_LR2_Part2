#include <iostream>
#include <climits>
#include <limits>
#include "Martynov_LR2_part2.h"


using namespace std;

int main() {
    int choice;
    int number;
    string x;

    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Ввести натуральное число X" << endl;
        cout << "2. Найти наибольшую цифру в записи числа X" << endl;
        cout << "3. Найти наименьшую цифру в записи числа X" << endl;
        cout << "4. Выход" << endl;
        cout << "Выберите пункт меню: ";

        if (!(cin >> choice))
         {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Введите натуральное число X: ";
                cin >> x;
                number = UserInput(x);
                break;
            case 2:
                cout << "Наибольшая цифра в числе: " << findMaxDigit(number) << endl;
                break;
            case 3:
                cout << "Наименьшая цифра в числе: " << findMinDigit(number) << endl;
                break;
            case 4:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Ошибка: неверный пункт меню." << endl;
                break;
        }
    }
    return 0;
}