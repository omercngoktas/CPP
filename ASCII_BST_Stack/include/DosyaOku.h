#ifndef DOSYAOKU_H
#define DOSYAOKU_H

#include <fstream>
#include <iostream>
#include <sstream>
#include "Yigin.h"
#include "IkiliAramaAgaci.h"
using namespace std;

void dosya_oku(string dosya_adi);
void addToStack(int current_number, Stack* &current_stack, StackList* &stack_list);
void addToBinaryTree(IkiliAramaAgaciListesi* &binary_tree_list, StackList* &stack_list);
IkiliAramaAgaci* findBinaryTree(IkiliAramaAgaciListesi* binary_tree_list);



#endif
