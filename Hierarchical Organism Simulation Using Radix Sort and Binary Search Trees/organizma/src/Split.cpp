#include "Split.h"

Split::Split(std::string text) { textToSplit = text; }

Split::~Split() {

}

std::vector <int> Split::splitTextBySpace() {
    std::stringstream iss(textToSplit);
    int hucreDegeri;
    std::vector <int> hucreler;
    while(iss >> hucreDegeri) { hucreler.push_back(hucreDegeri); }
    return hucreler;
}