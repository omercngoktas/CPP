#include "radixSort.h"

void radix_sort(std::vector<int>& arr) {
    int radix = 1;
    // Largest element in unsorted array
    int max = *(std::max_element(arr.begin(), arr.end()));
    while(max / radix) {
        // Buckets used for sorting. Each bucket representing a digit.
        std::vector<std::vector<int>> buckets(10, std::vector<int>());
        for(const auto& num : arr) {
            int digit = num / radix % 10;
            buckets[digit].push_back(num);
        }
        std::size_t k = 0;
        // Take the elements out of buckets into the array
        for(std::size_t i = 0; i < 10; i++) {
            for(std::size_t j = 0; j < buckets[i].size(); j++) {
                arr[k] = buckets[i][j];
                k++;
            }
        }
        // Change the place of digit used for sorting
        radix *= 10;
    }
}

void print_arr(std::vector<int>& arr) {
    for(auto elem : arr) {
        std::cout << elem << "\t";
    }
    std::cout << "\n";
}

std::vector<int> tokenize(std::string s) {
    std::stringstream iss( s );
    int hucre;
    std::vector <int> hucreler;
    while(iss >> hucre)
        hucreler.push_back( hucre );
    return hucreler;
}