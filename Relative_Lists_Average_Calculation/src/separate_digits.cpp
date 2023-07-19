#include "../include/separate_digits.h"

// Fonksiyon: Bir vector<int>'i alıp basamağına göre ayırır
vector<vector<int>> separateDigitsInVector(const vector<int>& vec) {
    vector<vector<int>> separated_digits;
    for (int num : vec) {
        vector<int> digits;

        while (num != 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        separated_digits.push_back(digits);
    }
    return separated_digits;
}