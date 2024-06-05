#include <iostream>
#include "../include/LinkedList.h"
#include "../include/FileOperations.h"
#include "../include/Digits.h"
#include "../include/Swap.h"

using namespace std;

// alınan tüm sayıların birler ve onlar basamaklarının ayrıştırılıp
// listA ve listB'ye linked listler halinde eklenmesi
void createDigitLists(LinkedList* currentHead, LinkedList& listA, LinkedList& listB) {
    LinkedList ones;
    LinkedList tens;
    
    Node* current = currentHead->getHead();
    while(current) {
        int number = current->data;
        int onesDigit = getOnesDigit(number);
        int tensDigit = getTensDigit(number);
        ones.insert(onesDigit);
        tens.insert(tensDigit);
        current = current->next;
    }
    
    listA.insert(reinterpret_cast<int>(tens.getHead()));
    listB.insert(reinterpret_cast<int>(ones.getHead()));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Kullanim: " << argv[0] << " <dosya_adi>" << endl;
        return 1;
    }

    // input dosyası okunup her bir satır linked listlere yerleştirilecek
    // ve her linked list listOfLists'in içerisinde tutulacak
    LinkedList listOfLists; 
    
    // dosyanın okunup linked listlerin listOfLists'e yerleştirilmesi
    if (!FileOperations::readDataFromFile(argv[1], listOfLists)) {
        cout << "Dosya acilamadi!" << endl;
        return 1;
    }
    
    LinkedList listA, listB;
    // birler ve onlar basamağına göre sayıların ayrıştırılması,
    // listA ve listB'ye birler ve onlar basamağının linked listlerle eklenmesi
    Node* currentList = listOfLists.getHead();
    while (currentList) {
        LinkedList* currentHead = reinterpret_cast<LinkedList*>(currentList);
        createDigitLists(currentHead, listA, listB);
        currentList = currentList->next;
    }

    // kullanıcıdan konumların alınması
    int konumA, konumB;
    std::cout << "Konum A: ";
    std::cin >> konumA;
    std::cout << "Konum B: ";
    std::cin >> konumB;

    // alınan konumlara göre konum değiştirme işleminin gerçekleştirilmesi
    swapLists(listA, listB, konumA, konumB);

    // ekrana double değer bastırırken noktadan sonra basamak yazdırılması
    cout << std::fixed;
    cout.precision(1);

    // listA ve listB'nin ortalamalarının toplam değerlerinin hesaplanması
    double ustOrtalamaToplami = listA.getAverage();
    double altOrtalamaToplami = listB.getAverage();

    // hesaplanan ortalamaların toplam değerlerinin ekrana yazdırılması
    cout << "Ust: " << ustOrtalamaToplami << endl;
    cout << "Alt: " << altOrtalamaToplami << endl;

    return 0;
}
