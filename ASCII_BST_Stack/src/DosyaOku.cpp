#include "../include/DosyaOku.h"

IkiliAramaAgaci* findBinaryTree(IkiliAramaAgaciListesi* binary_tree_list) {
    IkiliAramaAgaci* max_height_tree = nullptr;
    int max_height = -1;
    int max_height_value_sum = 0;
    int max_height_tree_index = -1;

    int tree_index = 0;
    IkiliAramaAgaci* current_tree = binary_tree_list->getTreeByIndex(tree_index);

    while (current_tree) {
        int current_height = current_tree->getHeight();
        int current_value_sum = current_tree->getSum();

        if (current_height > max_height ||
            (current_height == max_height && current_value_sum > max_height_value_sum) ||
            (current_height == max_height && current_value_sum == max_height_value_sum && tree_index < max_height_tree_index)) {
            max_height = current_height;
            max_height_value_sum = current_value_sum;
            max_height_tree = current_tree;
            max_height_tree_index = tree_index;
        }

        tree_index++;
        current_tree = binary_tree_list->getTreeByIndex(tree_index);
    }
    return max_height_tree;
}


// güncel satırdaki tüm sayılar stack'lere eklendi ve bu stackler stack_list' yerleştirildi
// stack_list'te gezilip her stack'le bir binary tree oluşturulacak
void addToBinaryTree(IkiliAramaAgaciListesi* &binary_tree_list, StackList* &stack_list) {
    // satırdan oluşturulan tüm stacklerde gezmek için index değeri
    int stack_index = 0;

    // güncel olarak değerleri ikili arama ağacına eklenecek stack
    Stack* currentStack = stack_list->getStack(stack_index);

    // stack'lerin içinde gezme
    while(currentStack) {
        // stack değerlerinin ekleneceği ikili arama ağacı
        IkiliAramaAgaci* currentBinaryTree = new IkiliAramaAgaci;

        // stack boşaltılana kadar değerleri ikili arama ağacına eklenir
        while(!currentStack->empty()) {
            currentBinaryTree->insert(currentStack->top());
            currentStack->pop();
        }

        // stack'teki değerlerin eklendiği ikili arama ağaçlarının listeye eklenmesi
        binary_tree_list->addTree(currentBinaryTree);
        stack_index++; // sonraki stack için indexin arttırılması
        currentStack = stack_list->getStack(stack_index);
    }
}

// dosyadan okunan güncel satırdaki sayının stack'e eklenme işlemi
void addToStack(int current_number, Stack* &current_stack, StackList* &stack_list) {
    // stack boşsa bellekten yer ayrılır
    if (!current_stack) {
        current_stack = new Stack;
    } 
    // stack daha önceden oluşturulmuş
    else {
        // yeni gelen sayı çift ve son sayıdan daha büyükse yeni bir stack oluşturulur
        // ve eski stack stacklerin bulunduğu listeye yerleştirilir
        if (current_number > current_stack->top() && current_number % 2 == 0) {
            // yeni stack oluşturulmadan önce şu anki stack stack listesine yerleştirilir
            stack_list->addStack(current_stack);
            // yeni stack oluşturulur
            current_stack = new Stack;
        }
    }
    // sayı stack'e eklenir
    current_stack->push(current_number);
}

void dosya_oku(string dosya_adi) {
    ifstream input_dosyasi(dosya_adi);
    if (!input_dosyasi) {
        cout << "Dosya adini kontrol edin." << endl;
        return;
    }
    string guncel_satir; //dosyadan okunan satırlar line'a koyuluyor
    // satırdan okunan sayıların stacklere eklenip stacklerin de tutulacağı liste
    StackList* stack_listesi = new StackList; 
    Stack* guncel_stack = nullptr;

    while (getline(input_dosyasi, guncel_satir)) {
        istringstream iss(guncel_satir);
        int guncel_sayi; // satırda okunan güncel sayının bulunduğu değişken

        // güncel satır kurala göre stack'lere eklendikten sonra
        // ikili arama ağaclarına yerleştirilir ve bu ikili arama
        // ağaçları da binary_tree_list'te bulunur
        IkiliAramaAgaciListesi* binary_tree_list = new IkiliAramaAgaciListesi;


        while (iss >> guncel_sayi) {
            // güncel satırın sayıları okunur ve stack'e eklenir
            addToStack(guncel_sayi, guncel_stack, stack_listesi);
        }
        // değerler guncel_stack'e eklendi ve bu stack de listeye eklenir
        stack_listesi->addStack(guncel_stack);
        
        // güncel satıra ait tüm stackler listelere eklendi ve listeden ulaşılıp
        // ikili arama ağaçlarına yerleştirilmesi
        addToBinaryTree(binary_tree_list, stack_listesi);


        // binary_tree_list->printAllTrees();
        findBinaryTree(binary_tree_list)->display();
        // cout << "--------------------------------" << endl;

        guncel_stack = nullptr;
        stack_listesi->removeStacks();
        delete binary_tree_list;
    }

    delete stack_listesi;
    input_dosyasi.close();
}
