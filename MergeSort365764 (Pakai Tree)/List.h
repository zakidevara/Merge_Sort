/* File : linked57.h                                               */
/* Deskripsi : ADT linked list dengan representasi fisik pointer     */
/* Representasi address dengan pointer                               */
/* InfoType adalah integer                                           */

/* Dibuat oleh  : Muhammad Zaki Devara / 181511057                   */
/* Last Updated : 18 Maret 2019                                      */

#ifndef linked_H
#define linked_H
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef int infotype; // infotype adalah tipe data dari info dalam list, yaitu integer
typedef struct tElmtList *address; // tipe data address adalah pointer yang menunjuk ke tipe komposit tElmtList
typedef struct tElmtList {
 infotype info;
 address next;
 } ElmtList; //tipe data komposit tElmtList bernama ElmtList dengan subvariabel info bertipe infotype dan next bertipe address


bool isEmpty(address p);
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == NULL
address Create_Node ();
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan NULL
// Parameter : P (parameter Output)
void Isi_Node (address *p , infotype nilai);
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak NULL
// *p.next diisi NULL
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
void Tampil_List (address p);
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)
void Ins_Awal (address *p, address PNew);
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)
void Ins_Akhir (address *p, address PNew);
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */
address Search (address p, infotype nilai);
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
address SearchBfr(address p, infotype nilai);
void InsertAfter (address * pBef, address PNew);
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */
address Del_Awal (address * p);
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */
void Del_Akhir (address * p, infotype * X);
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */
address Del_After (address pBef);
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */
void DeAlokasi (address * p);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
int NbElmt (address p);
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
// Recursif Mode
infotype Min (address p);
/* Mengirimkan nilai Info(P) yang minimum */
infotype Max (address p);
/* Mengirimkan nilai Info(P) yang maximum */
infotype sum (address p);
/* Mengirimkan jumlah nilai elemen dalam list */
infotype Rerata (address p);
/* Mengirimkan nilai rata-rata Info(P) */
address BalikList (address p);
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst
*/
void pecahList(address source, address* left, address* right);
//pecah list setelah pBfr
void gabungList(address head1, address *head2);
//menggabungkan 2 list

#endif
