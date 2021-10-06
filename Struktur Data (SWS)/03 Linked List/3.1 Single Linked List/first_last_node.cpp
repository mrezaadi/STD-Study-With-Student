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

Buku *head, *tail, *cur, *newNode, *delNode;

int countSingleLinkedList(){
    int sum = 0;
    cur = head;
    while(cur != NULL){
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

//Menggunakan proses tranfersing , cirinya menggunakan current
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

//Menggunakan proses tranfersing
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
    createSingleLinkedList("Matematika", "Nikola Einstein", 1945);
    printSingleLinkedList();

    cout << "<<<<<<<<<< SETELAH DILAKUKAN PENAMBAHAN AWAL >>>>>>>>>>" << endl;
    //Tambah data diawal
    addFirst("Fisika", "Albert Tesla", 2021);
    printSingleLinkedList();

    cout << "<<<<<<<<<< SETELAH DILAKUKAN PENAMBAHAN AKHIR >>>>>>>>>>" << endl;
    //Tambah data diakhir
    addLast("Quantum", "Muhammad Reza", 1998);
    printSingleLinkedList();

    cout << "<<<<<<<<<< SETELAH DILAKUKAN PENGHAPUSAN AWAL >>>>>>>>>>" << endl;
    //Hapus data awal
    removeFirst();
    printSingleLinkedList();

    cout << "<<<<<<<<<< SETELAH DILAKUKAN PENGHAPUSAN AKHIR >>>>>>>>>>" << endl;
    //Hapus data awal
    removeLast();
    printSingleLinkedList();

}