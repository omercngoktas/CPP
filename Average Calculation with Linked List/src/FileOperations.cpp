#include "../include/FileOperations.h"
#include <fstream>
#include <sstream>

// verilen input dosyasını satır satır okuyup linked listlere eklenmesi ve linked listlerin de listOfLists'e eklenmesi
bool FileOperations::readDataFromFile(const string& fileName, LinkedList& listOfLists) {
    ifstream inputFile(fileName); // Dosyadan veri okumak için gerekli dosya nesnesi

    if (!inputFile) { return false; }

    string line;

    // Dosyanın sonuna gelene kadar satır satır okuyarak bağlı listeleri oluşturuyoruz
    while (getline(inputFile, line)) {
        LinkedList newList; // Yeni bir bağlı liste oluşturuyoruz
        istringstream iss(line);
        int num;
        while (iss >> num) {
            newList.insert(num); // Yeni bağlı listeye sayıları ekliyoruz
        }
        listOfLists.insert(reinterpret_cast<int>(newList.getHead())); // Ana bağlı listeye bu yeni bağlı listeyi ekliyoruz
    }

    inputFile.close(); // Dosya okuma işlemi tamamlandı, dosyayı kapatıyoruz

    return true;
}
