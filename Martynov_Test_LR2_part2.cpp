#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"

using namespace cute;
#include "Martynov_LR2_part2.cpp"

void testfindMaxDigit() {
    // входное значение
    int a = 564738;

    //ожидаемый результат
    int expected = 8;
    // получение значения с помощью тестируемого метода
    int actual = findMaxDigit(a);

    //сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

void testfindMinDigit() {
    // входное значение
    int a = 564738;

    //ожидаемый результат
    int expected = 4;
    // получение значения с помощью тестируемого метода
    int actual = findMinDigit(a);

    //сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

//тест, проверяющий отсев пустых значений
void testUserInput_Empty() {
    // исходные данные
    string str = "";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

//тест, проверяющий отсев нецифровых символов
void testUserInput_Letter(){
    // исходные данные
    string str = "a";
    // ожидаемое значение результата работы функции UserInput
    bool expected = false;
    // получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    // сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

//тест, проверяющий отсев отрицательных значений
void testUserInput_NegativeValue(){
    //исходные данные
    string str = "-5";
    //ожидаемое значение pезультата работы функции UserInput
    bool expected = false;
    //получение значения с помощью тестируемого метода
    bool actual = UserInput(str);
    //сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}

int main() {
    suite s;

    s.push_back(CUTE(testfindMaxDigit));
    s.push_back(CUTE(testfindMinDigit));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter)); 
    s.push_back(CUTE(testUserInput_NegativeValue));

    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All Tests");

    return 0;
}