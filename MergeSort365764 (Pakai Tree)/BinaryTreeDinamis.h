/* Nama File        : BinaryTreeDinamis.cpp                                                                   */
/* Deskripsi        : ADT Tree Binary dengan alokasi dinamis
                      Struktur data 1 node(bTreeNode) :
                      - info    : bType(integer)
                      - left      : bAddr(pointer of bTreeNode) => pointer ke anak kiri
                      - right      : bAddr(pointer of bTreeNode) => pointer ke anak kanan
                      Struktur data 1 tree(bTree)  :
                      - root    : bAddr(pointer of bTreeNode) => pointer ke node root dari tree
                                                                                                            */
/* Nama Pembuat     : Muhammad Zaki Devara / 181511057                                                      */
/* Terakhir update  : 17 Juni 2019                                                                           */
/* Referensi :  https://www.geeksforgeeks.org/avl-tree-set-2-deletion/ (AVL Tree Deletion)
                https://www.geeksforgeeks.org/avl-tree-set-1-insertion/ (AVL Tree Insertion)
                https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/ (Print binary tree)       */

#ifndef btree_d_H
#define btree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct bTreeNode *bAddr;
typedef int bType;

typedef struct bTreeNode{
	bAddr left = NULL;
	bType info;
	bAddr right = NULL;
}ElmtBinTree;

struct bTree{
	bAddr root = NULL;
};

/* ---------------- Konstruktor Tree ---------------- */
bTree bCreateTree();
//Membuat tree kosong (X.root=NULL)


/* ---------------- Alokasi node baru Tree ---------------- */
bAddr bCreateNode(bType X);
//Alokasi untuk membuat node baru


/* ---------------- Operasi-operasi Tree ---------------- */
void bInsertRight(bTree *tRoot, bAddr parent, bType X);
// Menambah element pada node parent

void bInsertLeft(bTree *tRoot, bAddr parent, bType X);
// Menambah element pada node parent

bAddr bSearch(bAddr root, bType src);
// Mencari node dengan info tertentu dan mengembalikan addressnya

bAddr bSearchParent(bAddr root, bType src);
// mencari node parent dari info tertentu dan mengembalikan addressnya


bAddr bDelete(bAddr root, bType data);
// Delete satu node secara rekursif
// Node Daun langsung dihapus
// Node yang anaknya satu akan digantikan oleh anaknya tsb
// Node yang punya anak 2 akan diganti dengan successor in order nya

void bDelTree(bAddr root);
// Delete root dari tree beserta node anak - anaknya

bAddr inOrderSuccessor(bAddr root, bAddr node);
// return pointer yang menunjuk ke successor in order dari node
// Masih error untuk node right son yang berupa leaf

/* ---------------- TRAVERSAL Tree ---------------- */
void bPost(bAddr root); // Postorder traversing
void bPre(bAddr root); // Preorder traversing
void bIn(bAddr root); // Inorder traversing
void bGivenLevel(bAddr root, int level); // Traversing pada level yang dimasukkan
void bLevelOrder(bAddr root); // Levelorder traversing


/*  --------------- PROPERTY Tree ------------------ */
int bTreeSize(bAddr root);
// Mengembalikan jumlah node di dalam suatu tree

int bJumlahDaun(bAddr root);
// Mengembalikan jumlah node daun

/*  --------------- PROPERTY Node ------------------ */
int bGetLevel(bAddr root, bAddr node);
// Mengembalikan level/tingkat dari suatu node

int bGetDepth(bAddr node);
// Mengukur kedalaman suatu node dalam tree
// untuk mengukur kedalaman tree masukkan parameter node root

int bHeight(bAddr root);
// Mengembalian height dari suatu node

/*  --------------- Predikat - Predikat Penting ------------------ */
bool bIsTreeEmpty(bAddr P);

bool bIsDaun(bAddr P);

bool bIsUnerLeft(bAddr P);

bool bIsUnerRight(bAddr P);

bool bIsBiner(bAddr P);


/*  --------------- Operasi Binary Search Tree ------------------ */
bAddr insertBST(bAddr root, bType data);
// Insert node dengan aturan nilai yang lebih besar ada di kanan, nilai data yang kecil di sebelah kiri
// Tidak boleh ada info node yang sama

bAddr searchBST(bAddr root, bType data);
// Proses Searching untuk Binary Search Tree

/*  --------------- Operasi AVL Tree ------------------ */
bAddr minNodeValue(bAddr node);


int heightDiff(bAddr root);
// Mencari selisih dari height subtree kiri dan height subtree kanan

bAddr rightRotate(bAddr node);
// Putar ke arah kanan dengan root awal berupa parameter node
// return root baru setelah dirotate

bAddr leftRotate(bAddr node);
// Putar ke arah kiri dengan root awal berupa parameter node
// return root baru setelah dirotate

bAddr insertAVL(bAddr root, bType data);
// Insert node dengan aturan BST dan balancing sehingga selisih height subtree kiri dan subtree kanan <= 1

bAddr deleteAVL(bAddr root, bType data);
// Delete node dan lakukan balancng jika setelah penghapusan node jadi tidak seimbang


void print2DUtil(bAddr root, int space);

void print2D(bAddr root);
#endif

