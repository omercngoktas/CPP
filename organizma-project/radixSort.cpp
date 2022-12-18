#include "radixSort.h"

void radix_sort(std::vector <int> &hucreDegerleri) {
    int radix = 1;
    // Largest element in unsorted hucreDegerleri
    int max = *(std::max_element(hucreDegerleri.begin(), hucreDegerleri.end()));
    while(max / radix) {
        // Buckets used for sorting. Each bucket representing a digit.
        std::vector<std::vector<int>> buckets(10, std::vector<int>());
        for(const auto& num : hucreDegerleri) {
            int digit = num / radix % 10;
            buckets[digit].push_back(num);
        }
        std::size_t k = 0;
        // Take the elements out of buckets into the hucreDegerleri
        for(std::size_t i = 0; i < 10; i++) {
            for(std::size_t j = 0; j < buckets[i].size(); j++) {
                hucreDegerleri[k] = buckets[i][j];
                k++;
            }
        }
        // Change the place of digit used for sorting
        radix *= 10;
    }
}

std::vector<int> splitBySpace(std::string text) {
    std::stringstream iss(text);
    int hucreDegeri;
    std::vector <int> hucreler;
    while(iss >> hucreDegeri)
        hucreler.push_back(hucreDegeri);
    return hucreler;
}