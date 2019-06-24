#include "List.h"
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
    int info = 1;
    address head = NULL, pNew = NULL;

    system("cls");
    printf("Input (beres pake 0): ");
    while(true){
        scanf("%d ", &info);
        if(info == 0) break;


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
    address cur = *head;

    for(int i = 1; i < n/2; i++){
        cur = cur->next;
    }
    pecahList(&cur, &right);

    mergeSort(&left, NbElmt(left));
    mergeSort(&right, NbElmt(right));

    *head = merge(left, right);
}

int main()
{
    address head = NULL;
    head = insertList();


    printf("List Awal : ");Tampil_List(head); printf("\n");
    mergeSort(&head, NbElmt(head));
    printf("List Akhir : ");Tampil_List(head); printf("\n");

    _getch();
}
