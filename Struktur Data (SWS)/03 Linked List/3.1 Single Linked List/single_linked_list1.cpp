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

int main(){
    //Inisialisasi Single Linked List
    Buku *node1,*node2,*node3;
    //Cara prosedural
    node1 = (Buku*) malloc(sizeof(Buku));
    //Cara OOP
    node1 = new Buku();
    node2 = new Buku();
    node3 = new Buku();
    //Pengisian node
    node1 ->judul = "Matematika";
    node1 ->pengarang = "Albert Tesla";
    node1 ->tahun = 1945;
    node1 ->next = node2;

    node2 ->judul = "Fisika";
    node2 ->pengarang = "Nikola Einstein";
    node2 ->tahun = 1944;
    node2 ->next = node3;

    node3 ->judul = "Quantum";
    node3 ->pengarang = "Thomas Beta";
    node3 ->tahun = 1942;
    node3 ->next = NULL;

    //Print single linked list
    Buku *cur;
    cur = node1;
    while(cur != NULL){
        cout << "\nJudul Buku: " << cur->judul << endl;
        cout << "Pengarang Buku: " << cur->pengarang << endl;
        cout << "Tahun Terbit: " << cur->tahun << endl;

        cur = cur->next;
    }
}