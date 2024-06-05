#ifndef READ_LOAD
#define READ_LOAD
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include "../include/separate_digits.h"
#include "../include/singly_linked_list.h"

using namespace std; // Kullanım örneği için kullanıyoruz.

vector<vector<vector<int>>> file_read(const char* filename);

#endif