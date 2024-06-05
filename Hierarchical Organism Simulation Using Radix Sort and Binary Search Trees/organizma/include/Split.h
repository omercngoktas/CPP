#ifndef SPLIT_H
#define SPLIT_H
#include <string>
#include <vector>
#include <sstream>

class Split {
    private:
        std::string textToSplit;

    public:
        Split(std::string);
        ~Split();
        std::vector <int> splitTextBySpace();
};

#endif