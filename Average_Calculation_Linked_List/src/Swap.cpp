#include "../include/Swap.h"

// verilen konum değerlerine göre satırların yer değiştirilmesi
void swapLists(LinkedList& listA, LinkedList& listB, int konumA, int konumB) {
    if (konumA < 0 || konumA >= listA.size() || konumB < 0 || konumB >= listB.size()) {
        cout << "Girilen index degerlerini kontrol edin!" << endl;
        return;
    }

    LinkedList* listANode = listA.getNodeAtIndex(konumA);
    LinkedList* listBNode = listB.getNodeAtIndex(konumB);
    LinkedList newCopiedList = listANode->copyList();

    // İlgili düğümleri değiştiriyoruz
    listA.setNodeAtIndex(konumA, listBNode);
    listB.setNodeAtIndex(konumB, &newCopiedList);
}
