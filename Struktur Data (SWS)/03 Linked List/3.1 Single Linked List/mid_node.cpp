#include <iostream>

using namespace std;

//Delkarasi Single Linked List
struct Buku{
    //Komponen/Member
    string judul, pengarang;
    int tahun;

    //Pointer
    Buku *next;
};

Buku *head, *tail, *cur, *before, *newNode, *delNode;

int countSingleLinkedList(){
    int sum = 0;
    cur = head;
    while (cur!= NULL){
        sum++;
        cur = cur->next;
    }
    return sum;
}

void createSingleLinkedList(string judul, string pengarang, int tahun){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahun = tahun;
    head->next = NULL;
    tail = head;
}

void addFirst(string judul, string pengarang, int tahun){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahun = tahun;

    newNode->next = head;
    head = newNode;
}

void removeFirst(){
    delNode = head;
    head = head->next;
    delete delNode;
}

void changeFirst(string judul, string pengarang, int tahun){
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahun = tahun;
}

void addLast(string judul, string pengarang, int tahun){
    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahun = tahun;
    
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void removeLast(){
    delNode = tail;
    cur = head;

    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete delNode;
}

void changeLast(string judul, string pengarang, int tahun){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahun = tahun;
}

//Berdasarkan posisi
void addMid(string judul, string pengarang, int tahun, int posisi){
    if (posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countSingleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahun = tahun;
    
        cur = head;
        int nomor = 1;
        while (nomor < posisi-1){
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void removeMid(int posisi){
    if (posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countSingleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        cur = head;
        int nomor = 1;
        while (nomor <= posisi){
            if (nomor == posisi - 1){
                before = cur;
                cur = cur->next;
                nomor++;
            } else if (nomor == posisi){
                delNode = cur;
                cur = cur->next;
                nomor++;
            } else{
                cur = cur->next;
                nomor++;
            }
        }

    before->next = cur;
    delete delNode;
    }
}

void changeMid(string judul, string pengarang, int tahun, int posisi){
    if (posisi < 1 || posisi > countSingleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countSingleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        cur = head;
        int nomor = 1;
        while (nomor <= posisi-1){
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahun = tahun;
    }
}
 

//Menggunakan proses transversing
void printSingleLinkedList(){
    cout << "Jumla data: " << countSingleLinkedList() << endl;
    cur = head;
    while(cur != NULL){
        cout << "\nJudul Buku: " << cur->judul << endl;
        cout << "Pengarang Buku: " << cur->pengarang << endl;
        cout << "Tahun Terbit: " << cur->tahun << endl;
        cur = cur->next;
    }
}

int main(){
    //Cara menggunakan fungsi dan prosedur
    cout << "<<<<<<<<<< DATA AWAL >>>>>>>>>>" << endl;
    createSingleLinkedList("Matematika", "Nikola Einstein", 1945);
    //Tambah data diawal
    addFirst("Fisika", "Albert Tesla", 2021);
    //Tambah data diakhir
    addLast("Quantum", "Muhammad Reza", 1998);
    printSingleLinkedList();

    cout << "<<<<<<<<<< DATA BARU DITAMBAH >>>>>>>>>>" << endl;
    //Tambah data berdasarkan urutannya
    addMid("Statistika", "Thomas Beta", 1920, 2);
    printSingleLinkedList();

    cout << "<<<<<<<<<< DATA BARU DIHAPUS >>>>>>>>>>" << endl;
    //Hapus data berdasarkan urutannya
    removeMid(2);
    printSingleLinkedList();

    cout << "<<<<<<<<<< DATA SUDAH DIUBAH >>>>>>>>>>" << endl;
    //Ubah data berdasarkan urutannya
    changeMid("Mekanika", "Thomas Gama", 1920, 2);
    printSingleLinkedList();
}