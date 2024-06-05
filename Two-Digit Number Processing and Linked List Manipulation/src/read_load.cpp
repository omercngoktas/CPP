#include "../include/read_load.h"

// reads given input file and loads lines to vector
vector<vector<vector<int>>> file_read(const char* filename) {
    ifstream input_file(filename);

    // raising error if file could not open
    if (!input_file.is_open()) {
        cerr << "Dosya acilamadi." << endl;
        return {};
    }

    // reading and loading lines to vector
    vector<vector<vector<int>>> numbers;
    string current_line;
    while (getline(input_file, current_line)) {
        vector<int> number_line;
        int number;
        istringstream iss(current_line);
        while (iss >> number) {
            number_line.push_back(number);
        }
        numbers.push_back(separateDigitsInVector(number_line));
    }

    input_file.close();
    return numbers;
}
