#include <iostream>
#include <climits>
#include <limits>


using namespace std;

int inputNumber() {
    int x;
    while (true) {
        cout << "Введите натуральное число X: ";
        cin >> x;
        
        if (cin.fail() || x <= 0) {
            cout << "Ошибка: должно быть положительное целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return x;
        }
    }
}

void findMaxDigit(int x)
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
}

void findMinDigit(int x)
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
}

int main() {
    int choice;
    int number;

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
                number = inputNumber();
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