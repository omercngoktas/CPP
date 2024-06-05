#include "../include/Digits.h"

// birler basamağını döndür
int getOnesDigit(int number) {
    return number % 10;
}

// onlar basamağını döndür
int getTensDigit(int number) {
    return (number / 10) % 10;
}
