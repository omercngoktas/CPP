#include "../include/calculate.h"

double calculate_mean(const std::vector<LinkedList>& linkedLists) {
    int maxSize = 0;
    double sum_of_means = 0.0;
    for (const auto& list : linkedLists) {
        int listSize = 0;
        Node* temp = list.get_root();
        while (temp != nullptr) {
            listSize++;
            temp = temp->sonraki;
        }
        maxSize = std::max(maxSize, listSize);
    }

    cout << maxSize << endl;

    // Calculate the sum for each position in the linked lists
    std::vector<double> sums(maxSize, 0.0);
    std::vector<double> counts(maxSize, 0.0);

    for (const auto& list : linkedLists) {
        Node* temp = list.get_root();
        int position = 0;
        while (temp != nullptr) {
            sums[position] += static_cast<double>(temp->sayi);
            counts[position]++;
            temp = temp->sonraki;
            position++;
        }
    }

    // Calculate the mean for each position
    std::vector<double> means(maxSize, 0.0);
    for (int i = 0; i < maxSize; i++) {
        if (counts[i] > 0) {
            means[i] = sums[i] / counts[i];
        }
    }

    // Calculate the overall mean
    double overallSum = 0.0;
    for (const auto& sum : sums) {
        overallSum += sum;
    }

    // Print the means for each position
    std::cout << std::fixed; // Ondalık sayıları her zaman nokta ile göster
    std::cout.precision(5); // 5 ondalık hane göster

    // std::cout << "Means for each position:" << std::endl;
    for (int i = 0; i < maxSize; i++) {
        if (counts[i] > 0) {
            // std::cout << "Position " << i << ": ";
            // Show the numbers being added
            for (size_t k = 0; k < linkedLists.size(); k++) {
                Node* temp = linkedLists[k].get_root();
                for (int j = 0; j < i; j++) {
                    if (temp) {
                        temp = temp->sonraki;
                    }
                }
                if (temp) {
                    // std::cout << temp->sayi;
                    if (k < linkedLists.size() - 1) {
                        // std::cout << " + ";
                    }
                }
            }
            sum_of_means += means[i];
        }
    }

    return sum_of_means;
}