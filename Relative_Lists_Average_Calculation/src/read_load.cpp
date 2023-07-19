#include "../include/read_load.h"

vector<vector<vector<int>>> file_read(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Dosya acilamadi." << endl;
        return {};
    }

    vector<vector<vector<int>>> numbers;
    string line;
    while (getline(file, line)) {
        vector<int> row;
        int num;
        istringstream iss(line);
        while (iss >> num) {
            row.push_back(num);
        }
        numbers.push_back(separateDigitsInVector(row));
    }
    file.close();

    return numbers;
}
