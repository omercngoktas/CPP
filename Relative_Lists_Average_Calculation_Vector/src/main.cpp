#include <iostream>
#include <vector>
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
            newLineA.insert_node(numbers[i][j][index]);
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

    vector<vector<vector<int>>> numbers = file_read(argv[1]);
    if (numbers.empty()) {
        return 1;
    }

    vector<LinkedList> listA = parse_numbers(numbers, 0);
    vector<LinkedList> listB = parse_numbers(numbers, 1);

    int konumA, konumB;
    std::cout << "Konum A: ";
    std::cin >> konumA;
    std::cout << "Konum B: ";
    std::cin >> konumB;

    if (konumA < 0 || static_cast<std::size_t>(konumA) >= listA.size() ||
        konumB < 0 || static_cast<std::size_t>(konumB) >= listB.size()) {
        std::cout << "Girilen konum degerlerini kontrol edin. 0'dan kucuk ve listenin boyutundan buyuk olamaz." << std::endl;
        return 1;
    }

    LinkedList temp = listA[konumA];
    listA[konumA] = listB[konumB];
    listB[konumB] = temp;

    double ortalama_list_a = calculate_mean(listA);
    double ortalama_list_b = calculate_mean(listB);

    cout << "Ust: " << ortalama_list_a << endl;
    cout << "Alt: " << ortalama_list_b << endl;


    return 0;
}
