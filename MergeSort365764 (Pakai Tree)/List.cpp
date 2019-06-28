/* File : linked57.cpp                                               */
/* Deskripsi : ADT linked list dengan representasi fisik pointer     */
/* Representasi address dengan pointer                               */
/* InfoType adalah integer                                           */

/* Dibuat oleh  : Muhammad Zaki Devara / 181511057                   */
/* Last Updated : 18 Maret 2019                                      */

#include "List.h"

bool isEmpty(address p){
// Tujuan : memeriksa apakah linked masih kosong
// Linked list kosong , jika Head == Nil

    if(p == Nil){ // jika p == null maka return true
        return true;
    }else{
        return false;
    }
}

address Create_Node (){
// Tujuan : memesan memory dengan alokasi dinamis
// Jika berhasil mengirimkan address, dan jika gagal mengirimkan Nil
// Parameter : P (parameter Output)
    address p;
    p = (address) malloc(sizeof(ElmtList));
}

void Isi_Node (address *p , infotype nilai){
// Tujuan : Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan
// Periksa keberadaan P, Nilai diisi jika P tidak Nil
// *p.next diisi Nil
// Parameter : P (parameter Input-Output); Nilai (parameter Input)
    if(!isEmpty(*p)){
        info(*p) = nilai;
        next(*p) = Nil;
    }
}



void Tampil_List (address p){
// Tujuan : Menampilkan seluruh isi Linked List
// Parameter : p (parameter input)

    while(!isEmpty(p)){
        printf("%d ", info(p));
        p = next(p);
    }
}

void Ins_Awal (address *p, address PNew){
// Tujuan : Insert 1 node baru (PNew) di awal Linked List
// Parameter : P (input-output)
// PNew (input)

    next(PNew) = *p;
    *p = PNew;


}

void Ins_Akhir (address *p, address PNew){
/* Tujuan : menambahkan elemen list (PNew) di akhir LinkedList */
/* IS : p mungkin Kosong */
/* FS : menyambungkan elemen baru (PNew) di akhir Linked List */

    if(*p == NULL){
        Ins_Awal(p, PNew);
    }else{
        address cur = *p;
        while(!isEmpty(next(cur))){
            cur = next(cur);
        }
        next(cur) = PNew;
    }
}

address Search (address p, infotype nilai){
/* Mencari apakah ada elemen list dengan Info(P) = nilai */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
    bool ketemu = false;
    address x = Nil ;

    while(!ketemu && !isEmpty(p)){
        if(info(p) == nilai){
            x = p;
            ketemu=true;
        }
        p = next(p);
    }
    return x;
}

address SearchBfr (address p, infotype nilai){
    address x = Nil ;
    if(p->info == nilai) return NULL;

    while(!isEmpty(p)){
        if(info(p->next) == nilai){
            x = p;
            return x;
        }
        p = next(p);
    }
    return x;
}

void InsertAfter (address * pBef, address PNew){
/* Tujuan : Menyambungkan 1 Node baru(PNew) stlah node tertentu(PBef) */
/* IS : pBef sudah dialokasi */
/* FS : Insert PNew sebagai elemen sesudah PBef */
/* Asumsi : pBef adalah posisi insert */

    next(PNew) = next(*pBef);
    next(*pBef) = PNew;

}

address Del_Awal (address* p){
/* IS : P TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* dan alamat elemen pertama di dealokasi */

    address q;
    q = *p;
    *p = next(*p);
    next(q) = Nil;
    return q;
}

void Del_Akhir (address * p, infotype * X){
/* IS : P TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* dan alamat elemen terakhir di dealokasi */

    address PDel, PBfr;
    PBfr = *p;
    while(next(next(PBfr)) != Nil){
        PBfr = next(PBfr);
    }
    PDel = next(PBfr);
    *X = info(PDel);
    next(PBfr) = Nil;
    DeAlokasi(&PDel);
}

void Del_After (address pBef){
/* IS : pBef TIDAK Kosong (hasil search posisi node sebelum yang didel)*/
/* FS : menghapus Node setelah pBef */
/* nilai info node yang dihapus disimpan pada X */
/* dan alamat elemen setelah pBef di dealokasi */

    address PDel,PNext;
    PDel = next(pBef);
    PNext = next(PDel);
    next(pBef) = PNext;
    next(PDel) = Nil;
    DeAlokasi(&PDel);

}

void DeAlokasi (address * p){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

    next(*p) = Nil;
    free(*p);
}

int NbElmt (address p){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
    int n;
    n = 0;

    if(isEmpty(p)){
        return n;
    }else{
        n++;
    }

    while(!isEmpty(next(p))){
        n++;
        p = next(p);
    }
    return n;
}

// Recursif Mode
infotype Min (address p){
/* Mengirimkan nilai Info(P) yang minimum */
    infotype nilaiMin;

    if(!isEmpty(next(p))){
        nilaiMin = Min(next(p));
        if(info(p) > nilaiMin){
            return nilaiMin;
        }else{
            return info(p);
        }
    }else{
        return info(p);
    }
}

infotype Max (address p){
/* Mengirimkan nilai Info(P) yang maximum */
    infotype nilaiMax;

    if(!isEmpty(next(p))){
        nilaiMax = Max(next(p));
        if(info(p) < nilaiMax){
            return nilaiMax;
        }else{
            return info(p);
        }
    }else{
        return info(p);
    }
}

infotype sum (address p){
/* Mengirimkan jumlah nilai elemen dalam list */
    infotype total;
    if(next(p) != Nil){
        total = sum(next(p)) + info(p);
        return total;
    }else{
        return info(p);
    }
}

infotype Rerata (address p){
/* Mengirimkan nilai rata-rata Info(P) */
    if(sum(p) % NbElmt(p) > NbElmt(p)/2){
        return (sum(p)/NbElmt(p))+1;
    }else{
        return sum(p)/NbElmt(p);
    }

}

address BalikList (address p){
/* IS : p sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst*/
    address pAwal;
    if(next(p) != Nil){
        pAwal = BalikList(next(p));
        next(next(p)) = p;
        next(p) = Nil;
        return pAwal;
    }else{
        return p;
    }
}

void pecahList(address source, address* left, address* right){
//pecah list setelah pBfr
    int n = NbElmt(source);
    *left = source;
    address temp = source;
    for(int i = 1; i < n/2; i++) temp = temp->next;

    *right = temp->next;
    temp->next = Nil;
}

void gabungList(address head1, address *head2){
//menggabungkan 2 list
    address pAkhir;
    pAkhir = head1;
    while(next(pAkhir) != Nil){
        pAkhir = next(pAkhir);
    }
    next(pAkhir) = *head2;
    *head2 = Nil;
}



