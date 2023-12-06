#ifndef AVLTREE_LIST_H
#define AVLTREE_LIST_H

#include "AvlTree.h"
#include "Yigin.h"


class AvlTreeList {
    private:
        class AvlDugum {
            public:
                AvlDugum(AvlTree* avlTree);
                AvlTree* avlTree;
                AvlDugum* onceki;
                AvlDugum* sonraki;
                Yigin yigin;
                int avlToplamDugumDegeri;
                void postOrderYiginaEkle(Dugum* dugum);
        };
        

    public:
        AvlTreeList();
        AvlDugum* bas;
        AvlDugum* son;
        void ekle(AvlTree* avlTree);
        void agaclariGoruntule();
        void postOrder();
        void yiginlariGoruntule();
        bool yigindanMinMaxCikar();
        bool avlDugumKaldir(AvlDugum* silinecekDugum);
};

#endif