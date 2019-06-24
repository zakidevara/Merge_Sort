#include "List.h"
#include "BinaryTreeDinamis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

bool isInteger(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] < '0' && str[i] > '9')
            return false;
    }
    return true;
}

address insertList(){
    char str[11];
    int info;
    address head = NULL, pNew = NULL;
    int jumlah;

    system("cls");
    printf("Jumlah Input : ");
    scanf("%d", &jumlah);

    printf("Input: ");
    for(int i = 1; i <= jumlah; i++){
        scanf("%d ", &info);

        pNew = Create_Node();
        Isi_Node(&pNew, info);
        Ins_Akhir(&head, pNew);
    }
    return head;
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

void mergeSort(address* head, int n){
    if(*head == NULL || (*head)->next == NULL) return;

    address left = *head;
    address right = NULL;

    pecahList(*head, &left, &right);

    mergeSort(&left, NbElmt(left));
    mergeSort(&right, NbElmt(right));

    *head = merge(left, right);
}


void insertListToTree(bTree* pohon, address head){
    if(head == NULL) return;

    while(head != NULL){
        insertAVL(pohon->root, head->info);
        head = head->next;
    }


}

int main()
{
    address head = NULL;
    head = insertList();
    bTree pohonKiri = bCreateTree();
    bTree pohonKanan = bCreateTree();

    address left, right;

    printf("List Awal : ");Tampil_List(head); printf("\n");

    pecahList(head, &left, &right);
    printf("List Left : ");Tampil_List(left); printf("\n");
    printf("List Right : ");Tampil_List(right); printf("\n");

    insertListToTree(&pohonKiri, left);
    insertListToTree(&pohonKanan, right);


//    bInsertLeft(&pohon, NULL, head);
//    Tampil_List(pohon.root->info);

    //mergeSort(&head, NbElmt(head));
    //printf("List Akhir : ");Tampil_List(head); printf("\n");

    _getch();
}
