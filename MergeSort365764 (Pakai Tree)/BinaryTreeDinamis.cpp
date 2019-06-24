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
#include <limits.h>
#include <malloc.h>
#include "BinaryTreeDinamis.h"
#include <conio.h>

bTree bCreateTree(){
	bTree New;
	New.root = NULL;
	return New;
}

bAddr bCreateNode(bType X){
	bAddr newNode;
	newNode=(bAddr) malloc(sizeof(ElmtBinTree));
	if (newNode != NULL){
		newNode->left=NULL;
		newNode->info=X;
		newNode->right=NULL;
	}
	return newNode;
}

void bInsertRight(bTree *tRoot, bAddr parent, bType X){
	bAddr newNode;
	newNode = bCreateNode(X);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (tRoot->root == NULL){ //JIka belum terdapat root
			tRoot->root = newNode;
		}else{
            if(parent->right == NULL){
                parent->right = newNode;
            }else{
                //pesan error
                printf("\nTidak bisa input");_getch();
            }
		}
	}
}

void bInsertLeft(bTree *tRoot, bAddr parent, bType X){

	bAddr newNode;

	newNode = bCreateNode(X);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (tRoot->root == NULL){ //JIka belum terdapat root
			tRoot->root=newNode;
		}else{
		    if(parent->left == NULL){
                parent->left = newNode;
            }else{
                //pesan error
                printf("\nTidak bisa input");_getch();
            }
		}
	}
}

bAddr bSearch(bAddr root, bType src){
	if(root == NULL){
        return NULL;
	}

	if(root->info == src){
        return root;
	}else{
	    if(bSearch(root->right, src) != NULL){
            return bSearch(root->right, src);
	    }else if(bSearch(root->left, src) != NULL){
            return bSearch(root->left, src);
	    }else{
            return NULL;
	    }
	}
}

bAddr bSearchParent(bAddr root, bType src){
	if((root == NULL) || ((root->left == NULL) && (root->right == NULL))){
        return NULL;
	}

	if((root->left->info == src) || (root->right->info == src)){
        return root;
	}else{
	    if(bSearchParent(root->right, src) != NULL){
            return bSearchParent(root->right, src);
	    }else if(bSearchParent(root->left, src) != NULL){
            return bSearchParent(root->left, src);
	    }else{
            return NULL;
	    }
	}
}

bAddr bDelete(bAddr root, bType data){
    if(root == NULL) return root;
    if(bSearch(root, data) == NULL) return root;

    if(bSearch(root->left, data) != NULL){
        root->left = bDelete(root->left, data);
        return root;
    }else if(bSearch(root->right, data) != NULL){
        root->right = bDelete(root->right, data);
        return root;
    }else{
        if(root->info != data) return NULL; // Jika tidak ada node bernilai data dalam pohon
        if(root->left == NULL){  //Jika node yang di delete punya anak 1 di kanan/tidak punya anak
            bAddr temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){ // Jika node yang di delete punya 1 anak di kiri
            bAddr temp = root->left;
            free(root);
            return temp;
        }else{ //Jika node yang di delete punya 2 anak
            bAddr temp = inOrderSuccessor(root, bSearch(root, data));
            root->info = temp->info;
            root->right = bDelete(root->right, temp->info);
            return root;
        }
    }
}

bAddr inOrderSuccessor(bAddr root, bAddr node){
    if(bIsBiner(node)){
        bAddr temp = node->right;
        if(temp == NULL){
            return NULL;
        }else if(bIsDaun(temp)){
            return temp;
        }else{
            while(temp->left != NULL) temp = temp->left;
            return temp;
        }
    }else{
        return bSearchParent(root, node->info);
    }

}

int bGetDepth(bAddr node)
{
    if(node == NULL){
        return -1;
    }else{
        int rDepth = bGetDepth(node->right);
        int lDepth = bGetDepth(node->left);

        if(rDepth > lDepth){
            return rDepth + 1;
        }else{
            return lDepth + 1;
        }
    }
}

/* ---------------- TRAVERSAL Tree ---------------- */
void bPost(bAddr root){
	if (root!=NULL){
		bPost(root->left);
		bPost(root->right);
		printf("%d ", root->info);
	}
}

void bPre(bAddr root){
	if (root!=NULL){
		printf("%d ", root->info);
		bPre(root->left);
		bPre(root->right);
	}
}

void bIn(bAddr root){
	if (root!=NULL){
		bIn(root->left);
		printf("%d ", root->info);
		bIn(root->right);
	}
}

void bGivenLevel(bAddr root, int level){
    if(!bIsTreeEmpty(root)){
        if(level == 0){
            int a;
            if(bIsDaun(root)){
                a = 0;
            }else if(bIsUnerLeft(root) || bIsUnerRight(root)){
                a = 1;
            }else{
                a = 2;
            }
            printf("%d ", root->info);
        }else if(level > 0){
            bGivenLevel(root->left, level-1);
            bGivenLevel(root->right, level-1);
        }
    }
}

void bLevelOrder(bAddr root)
{
	for(int i = 0; i <= bGetDepth(root); i++){
        bGivenLevel(root, i);
	}

}

int bTreeSize(bAddr root){
    if(root == NULL){
        return 0;
    }else{
        return 1 + bTreeSize(root->left) + bTreeSize(root->right);
    }
}

int bGetLevel(bAddr root, bAddr node){
	if(root == node){
        return 0;
	}else{
	    if(bSearch(root->right, node->info) != NULL){
            return 1 + bGetLevel(root->right, node);
	    }else{
            return 1 + bGetLevel(root->left, node);
	    }
	}
}


bool bIsTreeEmpty(bAddr P){
    return (P == NULL);
}

bool bIsDaun(bAddr P){
    return (!bIsTreeEmpty(P) && bIsTreeEmpty(P->left) && bIsTreeEmpty(P->right) );
}

bool bIsUnerLeft(bAddr P){
    return (!bIsTreeEmpty(P) && !bIsTreeEmpty(P->left) && bIsTreeEmpty(P->right));
}

bool bIsUnerRight(bAddr P){
    return (!bIsTreeEmpty(P) && bIsTreeEmpty(P->left) && !bIsTreeEmpty(P->right));
}

bool bIsBiner(bAddr P){
    return (!bIsTreeEmpty(P) && !bIsTreeEmpty(P->left) && !bIsTreeEmpty(P->right));
}

int bJumlahDaun(bAddr root){
    if((root->left == NULL) && (root->right == NULL)){
        return 1;
    }else{
        if((root->left != NULL) && (root->right == NULL)){
            return bJumlahDaun(root->left);
        }else if((root->left == NULL) && (root->right != NULL)){
            return bJumlahDaun(root->right);
        }else if((root->left != NULL) && (root->right != NULL)){
            return bJumlahDaun(root->left) + bJumlahDaun(root->right);
        }
    }
}

/* ----- Operasi untuk Binary Search Tree ----- */
bAddr insertBST(bAddr root, bType data){
    if(root == NULL){
        root = bCreateNode(data);
    }else if(data <= root->info){
        root->left = insertBST(root->left, data);
    }else{
        root->right = insertBST(root->right, data);
    }
    return root;
}

bAddr searchBST(bAddr root, bType data){
    if(root == NULL) return NULL;
    else if(root->info == data) return root;
    else if(root->info > data) return searchBST(root->left, data);
    else return searchBST(root->right, data);
}

/* ----- Operasi untuk Balanced Tree ----- */

int bHeight(bAddr root){
    if(root == NULL) return 0;

    int leftHeight = bHeight(root->left);
    int rightHeight = bHeight(root->right);

    if(leftHeight > rightHeight) return leftHeight+1;
    else return rightHeight+1;
}

void bDelTree(bAddr root){
    if(root != NULL){
        bDelTree(root->left);
        bDelTree(root->right);
        free(root);
    }
}



/* ---- AVL Tree ---- */
int heightDiff(bAddr root){
    if (root == NULL) return 0;
    else return bHeight(root->left) - bHeight(root->right);
}

bAddr rightRotate(bAddr node){
    bAddr X = node->left;
    bAddr temp = X->right;

    X->right = node;
    node->left = temp;

    return X;
}

bAddr leftRotate(bAddr node){
    bAddr X = node->right;
    bAddr temp = X->left;

    X->left = node;
    node->right = temp;
    return X;
}

bAddr insertAVL(bAddr root, bType data){
    if(root == NULL) root = bCreateNode(data);

    if(data < root->info){
        root->left = insertAVL(root->left, data);
    }else if(data > root->info){
        root->right = insertAVL(root->right, data);
    }else{
        return root;
    }

    int balance = heightDiff(root);

    //Left Left Case
    if(balance > 1 && data < root->left->info) return rightRotate(root);

    //Right Right Case
    if(balance < -1 && data > root->right->info) return leftRotate(root);

    //Left Right Case
    if(balance > 1 && data > root->left->info){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right Left Case
    if(balance < -1 && data < root->right->info){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bAddr minNodeValue(bAddr node){
    bAddr temp = node;
    while(temp->left != NULL) temp = temp->left;
    return temp;
}


bAddr deleteAVL(bAddr root, bType data){
    if(root == NULL) return root;

    if(data < root->info) root->left = deleteAVL(root->left, data);
    else if(data > root->info) root->right = deleteAVL(root->right, data);
    else{
        // Case hanya 1 anak atau tidak ada anak
        if( (root->left == NULL) || (root->right == NULL) ){

            bAddr temp = NULL;
            if(root->left != NULL) temp = root->left;
            else if(root->right != NULL) temp = root->right;

            // Case tidak ada anak
            if (temp == NULL){
                temp = root;
                root = NULL;
            }else{ // case 1 anak
                *root = *temp;
            }
            free(temp);
        }else{ // case ada 2 anak
            bAddr temp = minNodeValue(root->right); //Cari successor in order

            root->info = temp->info;

            root->right = deleteAVL(root->right, temp->info);
        }
    }

    if(root == NULL) return root;

    int balance = heightDiff(root);

    // Left Left Case
    if (balance > 1 && heightDiff(root->left) >= 0) return rightRotate(root);

    // Left Right Case
    if (balance > 1 && heightDiff(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && heightDiff(root->right) <= 0) return leftRotate(root);

    // Right Left Case
    if (balance < -1 && heightDiff(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void print2DUtil(bAddr root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->info);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(bAddr root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
