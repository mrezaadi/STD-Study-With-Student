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

Buku *head, *tail, *cur;

void createSingleLinkedList(string judul, string pengarang, int tahun){
    head = new Buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahun = tahun;
    head->next = NULL;
    tail = head;
}

void printSingleLinkedList(){
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
}
