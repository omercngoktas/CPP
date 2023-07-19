#include <iostream>
#include <vector>
#include <chrono>
#include "../include/read_load.h"
#include "../include/separate_digits.h"
#include "../include/calculate.h"
#include "../include/singly_linked_list.h"
using namespace std;

// from the given vectors of parsed numbers, takes digits and puts them into vector of linkedlist
vector<LinkedList> parse_numbers(vector<vector<vector<int>>> numbers, int index) {
    vector<LinkedList> list;
    for(size_t i = 0; i < numbers.size(); i++) {
        LinkedList newLineA;
        for(size_t j = 0; j < numbers[i].size(); j++) {
            newLineA.insertNode(numbers[i][j][index]);
        }
        list.push_back(newLineA);
    }
    return list;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Kullanim: " << argv[0] << " <dosya_adi>" << endl;
        return 1;
    }

    // Zaman başlangıcını kaydediyoruz
    auto start = chrono::high_resolution_clock::now();

    vector<vector<vector<int>>> numbers = file_read(argv[1]);
    if (numbers.empty()) {
        return 1;
    }

    vector<LinkedList> listA = parse_numbers(numbers, 0);
    vector<LinkedList> listB = parse_numbers(numbers, 1);

    int konumA, konumB;
    // Get user inputs for the indices to swap
    std::cout << "Konum A: ";
    std::cin >> konumA;
    std::cout << "Konum B: ";
    std::cin >> konumB;

    // Check if the given indices are within the range of the vectors.
    if (konumA < 0 || static_cast<std::size_t>(konumA) >= listA.size() ||
        konumB < 0 || static_cast<std::size_t>(konumB) >= listB.size()) {
        std::cout << "Girilen konum degerlerini kontrol edin. 0'dan kucuk ve listenin boyutundan buyuk olamaz." << std::endl;
        return 1;
    }

    // Swap the LinkedList objects between listA[indexA] and listB[indexB].
    LinkedList temp = listA[konumA];
    listA[konumA] = listB[konumB];
    listB[konumB] = temp;

    double ortalama_list_a = calculate_mean(listA);
    double ortalama_list_b = calculate_mean(listB);

    cout << "Ortalamalar: " << ortalama_list_a << " " << ortalama_list_b << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "Execution time: " << duration << " ms" << endl;

    return 0;
}
