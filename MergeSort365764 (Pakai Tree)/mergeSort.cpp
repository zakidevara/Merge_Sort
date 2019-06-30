// File         : mergeSort.cpp
// Description  : Body ADT Merge Sort using Binary Tree
// Created By   : M. Zaki Devara - 181511057
//                Rhio Adjie F.  - 181511064
// Last Updated : 29 June 2019 By Agung Tri Atmojo

#include "mergeSort.h"

bool isInteger(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] < '0' && str[i] > '9')
            return false;
    }
    return true;
}

void insertList(address* head){
    int info;
    address pNew = NULL;
    int jumlah;

    system("cls");
    printf("Jumlah Input : ");
    scanf("%d", &jumlah);

    printf("Input: \n");
    for(int i = 1; i <= jumlah; i++){
        printf("Node %d->info : ",i);
        scanf("%d", &info);
        pNew = Create_Node();
        Isi_Node(&pNew, info);
        Ins_Akhir(head, pNew);
    }
}

address merge(address left, address right){
    address result = NULL;

    while(!isEmpty(left) && !isEmpty(right)){
        if(left->info <= right->info){
            address pNew = Del_Awal(&left);
            Ins_Akhir(&result, pNew);
        }else{
            address pNew = Del_Awal(&right);
            Ins_Akhir(&result, pNew);
        }
    }
    while(!isEmpty(left)){
        address pNew = Del_Awal(&left);
        Ins_Akhir(&result, pNew);
    }
    while(!isEmpty(right)){
        address pNew = Del_Awal(&right);
        Ins_Akhir(&result, pNew);
    }
    return result;
}



void deleteList(address* p, bType data)
{
    address pBef = NULL;
    if(Search(*p, data) != NULL){
        if((*p)->info == data){
            free(Del_Awal(p));
        }else{
            pBef = SearchBfr(*p, data);
            free(Del_After(pBef));
        }
    }
}
void insertListToTree(bTree* pohon, address* head){
    if(*head == NULL) return;

    while(*head != NULL){
        address temp = Del_Awal(head);
        pohon->root = insertAVL(pohon->root, temp->info);
    }
}

void insertTreeToList(bAddr root, address* head){
    if(root != NULL){
        insertTreeToList(root->left, head);
        address pNew = Create_Node();
        Isi_Node(&pNew, root->info);
        Ins_Akhir(head, pNew);
        insertTreeToList(root->right, head);
    }
}

void mergeSort(address* head){
    if(*head == NULL || (*head)->next == NULL) return;
    address left=Nil, right=Nil;

    pecahList(*head, &left, &right);
    printf("\n\nList dipecah menjadi 2 bagian\n");
    printf("\nList Left : ");Tampil_List(left);
    printf("\nList Right : ");Tampil_List(right);
    printf("\n\nPress any key to continue..."); _getch();

    bTree pohonKiri = bCreateTree();
    bTree pohonKanan = bCreateTree();

    insertListToTree(&pohonKiri, &left);
    insertListToTree(&pohonKanan, &right);
    printf("\n\nKedua list dimasukkan ke dalam tree AVL\n");
    printf("\nPohon Kiri : \n");
    print2D(pohonKiri.root);
    printf("\n\nPohon Kanan : \n");
    print2D(pohonKanan.root);
    printf("\n\nPress any key to continue..."); _getch();

    insertTreeToList(pohonKiri.root, &left);
    insertTreeToList(pohonKanan.root, &right);

    printf("\n\nKedua tree dimasukkan secara in order ke listnya masing - masing");
    printf("\n\nList Left : ");Tampil_List(left);
    printf("\nList Right : ");Tampil_List(right);

    printf("\n\nPress any key to see the result..."); _getch();

    // hapus list
    while(*head != NULL) Del_Awal(head);

    // gabung list
    *head = merge(right, left);
    printf("\n\nKedua list digabungkan kembali menjadi satu secara berurutan");
    printf("\n\nList Sorted : "); Tampil_List(*head);
    _getch();
}


void menu()
{
    address head = Nil, pDel = Nil;
    int pil, del;
    char sure;
    address pBef=Nil;
    bool pulang = true;
    do{
    system("cls");
    printf("List : "); Tampil_List(head);
    printf("\nJumlah elemen : %d", NbElmt(head));
    printf("\n\n/*********************MENU*********************/\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Sort\n");
    printf("0. Exit\n");
    printf("Pilihan : ");
    scanf("%d",&pil);
        switch(pil)
        {
            case 0 :    printf("\n-->Thank You<--");
                        pulang = false;
                        break;

            case 1 :    sure = 'Y';
                        system("cls");
                        while(sure == 'Y'){
                            insertList(&head);
                            printf("List Saat ini : "); Tampil_List(head); printf("\n");
                            printf("Apakah anda ingin tambah? Y/T : "); fflush(stdin);
                            scanf("%c",&sure);
                            sure = toupper(sure);
                        }
                        break;
            case 2 :    system("cls");
                        printf("List Sekarang : "); Tampil_List(head);
                        printf("\nMasukkan nilai yang ingin anda hapus : ");
                        scanf("%d",&del);
                        deleteList(&head, del);
                        printf("List Terbaru : "); Tampil_List(head);
                        _getch();
                        break;
            case 3 :    system("cls");
                        printf("List Sekarang : "); Tampil_List(head);
                        mergeSort(&head);
                        break;

        }
    }while(pulang == true);
}