// File			: mergeSort.h
// Description	: Prototype ADT Merge Sort using Binary Tree
// Created By   : M. Zaki Devara - 181511057
//				  Rhio Adjie F.  - 181511064
// Last Updated	: 29 June 2019 By Agung Tri Atmojo

#include "List.h"
#include "BinaryTreeDinamis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

bool isInteger(char str[]);

void insertList(address* head);

address merge(address left, address right);

void deleteList(address* p, bType data);

void insertListToTree(bTree* pohon, address* head);

void insertTreeToList(bAddr root, address* head);

void mergeSort(address* head);

void menu();