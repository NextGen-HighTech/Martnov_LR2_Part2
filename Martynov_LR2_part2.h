#ifndef _MARTYNOV_MATHTASK_H_
#define _MARTYNOV_MATHTASK_H_

#include <string>
#include <cstring>

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
    return minDigit;
}

#endif