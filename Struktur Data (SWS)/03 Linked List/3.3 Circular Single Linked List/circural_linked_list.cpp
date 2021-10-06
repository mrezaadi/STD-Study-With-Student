#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama, nim, jurusan;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *before, *after, *newNode, *delNode;

void createCircuralLinkedList(string nama, string nim, string jurusan){
    head = new Mahasiswa();
    head->nama = nama;
    head->nim = nim;
    head->jurusan = jurusan;

    tail = head;
    tail->next = head;
}

//First
void addFirst(string nama, string nim, string jurusan){
    if (head== NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;

        newNode->next = head;
        tail->next = newNode;

        head = newNode;
    }
}

void removeFirst(){
    if (head == NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        delNode = head;

        head = head->next;
        tail->next = head;

        delete delNode;
    }
}


//Last
void addLast(string nama, string nim, string jurusan){
    if (head == NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->jurusan = jurusan;

        newNode->next = head;
        tail->next = newNode;

        tail = newNode;
    }
}

void removeLast(){
    if (head == NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        delNode = tail;
        cur = head;

        while (cur->next != tail){
            cur = cur->next;
        }
        cur->next = head; 
    }
}

//Mid
void addMid(string nama, string nim, string jurusan, int posisi){
    if (head == NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        if (posisi == 1){
            cout << "Bukan data tengah" << endl;
        } else{
            newNode = new Mahasiswa();
            newNode->nama = nama;
            newNode->nim = nim;
            newNode->jurusan = jurusan;

            int nomor = 1;
            cur = head;
            while (nomor < posisi-1){
                nomor++;
                cur = cur->next;
            }
            after = cur->next;

            newNode->next = after;
            cur->next = newNode;            
        }
    }
}

void removeMid(int posisi){
    if (head==NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        if (posisi == 1){
            cout << "Bukan data tengah" << endl;
        } else{
            cur =head;
            int nomor = 1;
            while(nomor < posisi-1){
                nomor++;
                cur = cur->next;
            }

            delNode = cur->next;
            cur->next = delNode->next;
            delete delNode;
        }
    }
}

void printCircuralSingleLinkedList(){
    if (head == NULL){
        cout << "Circural Linked List belum dibuat!" << endl;
    } else{
        cur = head;
        while (cur->next != head){
            cout << "\nNama \t: " << cur->nama << endl;
            cout << "NIM \t: " << cur->nim << endl;
            cout << "Jurusan : " << cur->jurusan << endl;

            cur = cur->next;
        }
        cout << "\nNama \t: " << cur->nama << endl;
        cout << "NIM \t: " << cur->nim << endl;
        cout << "Jurusan : " << cur->jurusan << "\n" << endl;
    } 
}

int main(){

    //Data awal
    cout << "<<<<<<<<<< DATA AWAL <<<<<<<<<<"<< endl;
    createCircuralLinkedList("Muhammad Reza", "1301204078", "Informatika");
    printCircuralSingleLinkedList();

    //Tambah awal
    cout << "<<<<<<<<<< TAMBAH DATA AWAL <<<<<<<<<<"<< endl;
    addFirst("Albert Einstein", "1301223478", "Hubungan Internasional");
    printCircuralSingleLinkedList();

    //Tambah akhir
    cout << "<<<<<<<<<< TAMBAH DATA AKHIR <<<<<<<<<<"<< endl;
    addLast("Nikola Tesla", "1143242", "Kedokteran Hewan");
    printCircuralSingleLinkedList();

    //Tambah tengah
    cout << "<<<<<<<<<< TAMBAH DATA TENGAH <<<<<<<<<<"<< endl;
    addMid("Thomas Alfa Odinson", "1301235378", "Teknik Sipil", 2);
    printCircuralSingleLinkedList();

    //hHapus data tengah
    cout << "<<<<<<<<<< HAPUS DATA TENGAH <<<<<<<<<<"<< endl;
    removeMid(2);
    printCircuralSingleLinkedList();

    //Hapus awal
    cout << "<<<<<<<<<< HAPUS DATA AWAL <<<<<<<<<<"<< endl;
    removeFirst();
    printCircuralSingleLinkedList();

    //Hapus akhir
    cout << "<<<<<<<<<< HAPUS DATA AKHIR <<<<<<<<<<"<< endl;
    removeLast();
    printCircuralSingleLinkedList();
}