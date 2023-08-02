#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include "LinkedList.h"

using namespace std;

class FileOperations {
public:
    static bool readDataFromFile(const string& fileName, LinkedList& listOfLists);
};

#endif
