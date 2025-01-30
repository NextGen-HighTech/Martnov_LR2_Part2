#include <iostream>
#include <climits>
#include <limits>


using namespace std;

int UserInput(string input) {
    if (input.empty()) return -1;
    try {
        int number = stoi(input);
        if (number >= 0) {
            return number;
        } else {
            return -1;
        }
    }
    catch (...) {
        return -1;
    }
}

int findMaxDigit(int x)
{
    int maxDigit = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit > maxDigit) {
            maxDigit = digit;
        }
        x /= 10;
    }
    cout << "Наибольшая цифра в числе: " << maxDigit << endl;
    return maxDigit;
}

int findMinDigit(int x)
{
    int minDigit = 9;
    while (x > 0) {
        int digit = x % 10;
        if (digit < minDigit) {
            minDigit = digit;
        }
        x /= 10;
    }
    cout << "Наименьшая цифра в числе: " << minDigit << endl;
    return minDigit;
}

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
                findMaxDigit(number);
                break;
            case 3:
                findMinDigit(number);
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