#include <iostream>

using namespace std;

struct DataUser{
    string nama, username, email, password;

    DataUser *next;
    DataUser *prev;

};

DataUser *head, *tail, *cur, *before, *after, *newNode, *delNode;

void createDoubleLinkedList(string nama, string username, string email, string password){
    head = new DataUser();
    head->nama = nama;
    head->username = username;
    head->email = email;
    head->password = password;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

int countDoubleLinkedList(){
    int sum = 0;
    cur = head;
    while (cur != NULL){
        sum++;
        cur = cur->next;
    }
    return sum;
}

//First
void addFirst(string nama, string username, string email, string password){
    if (head==NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        newNode = new DataUser();
        newNode->nama = nama;
        newNode->username = username;
        newNode->email = email;
        newNode->password = password;

        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}

void removeFirst(){
    if (head == NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        delNode = head;
        head = head->next;
        head->prev = NULL;
        delete delNode;
    }
}

void changeFirst(string nama, string username, string email, string password){
    if (head == NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        head->nama = nama;
        head->username = username;
        head->email = email;
        head->password = password;
    }
}


//Last
void addLast(string nama, string username, string email, string password){
    if (head==NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        newNode = new DataUser();
        newNode->nama = nama;
        newNode->username = username;
        newNode->email = email;
        newNode->password = password;

        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void removeLast(){
    if (head == NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else {
        delNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete delNode;
    }
}

void changeLast(string nama, string username, string email, string password){
    if (head == NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        tail->nama = nama;
        tail->username = username;
        tail->email = email;
        tail->password = password;
    }
}

//Mid
void addMid(string nama, string username, string email, string password, int posisi){
    if (posisi < 1 || posisi > countDoubleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countDoubleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        if (head==NULL){
            cout << "Double Link List belum dibuat!" << endl;
        } else{
            newNode = new DataUser();
            newNode->nama = nama;
            newNode->username = username;
            newNode->email = email;
            newNode->password = password;

            cur = head;
            int nomor = 1;
            while (nomor < posisi-1){
                cur = cur-> next;
                nomor++;
            }
            after = cur->next;

            newNode->next = after;
            newNode->prev = cur;
            
            after->prev = newNode;
            cur->next = newNode; 
        }
    }
}

void removeMid(int posisi){
    if (posisi < 1 || posisi > countDoubleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countDoubleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        if (head==NULL){
            cout << "Double Link List belum dibuat!" << endl;
        } else{
            cur = head;
            int nomor = 1;
            while (nomor < posisi-1){
                cur = cur-> next;
                nomor++;
            }
            delNode = cur->next;

            after = delNode->next;
            before = cur;

            cur->next = after;
            after->prev = before;

            delete delNode; 
        }
    }
}

void changeMid(string nama, string username, string email, string password, int posisi){
    if (posisi < 1 || posisi > countDoubleLinkedList()){
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countDoubleLinkedList()){
        cout << "Posisi bukan posisi tengah" << endl;
    } else{
        if (head==NULL){
            cout << "Double Link List belum dibuat!" << endl;
        } else{
            cur = head;
            int nomor = 1;
            while (nomor <= posisi-1){
                cur=cur->next;
                nomor++;
            }
            cur->nama = nama;
            cur->username = username;
            cur->email = email;
            cur->password = password;
        }
    }
}

//Print
void printDoubleLinkedList(){
    if (head==NULL){
        cout << "Double Link List belum dibuat!" << endl;
    } else{
        cur = head;
        while(cur != NULL){
            cout << "\nNama \t\t: " <<cur->nama << endl;
            cout << "Username \t: " << cur->username << endl;
            cout << "Email \t\t: " << cur->email<< endl;
            cout << "Password \t: " << cur->password << "\n" << endl;

            cur = cur->next;
        }
    }
}

int main(){
    //Cara menggunakan fungsi dan prosedur
    cout << "<<<<<<<<<< DATA AWAL <<<<<<<<<<" << endl;
    createDoubleLinkedList("Reza","mrezaadii", "rezaadi@gmail.com", "481928");
    printDoubleLinkedList();

    //Tambah data awal
    cout << "<<<<<<<<<< TAMBAH DATA AWAL <<<<<<<<<<" << endl;
    addFirst("Teo", "teo19", "teo19@gmail.com","0231");
    printDoubleLinkedList();

    //Tambah data akhir
    cout << "<<<<<<<<<< TAMBAH DATA AKHIR <<<<<<<<<<" << endl;
    addLast("Malen", "malenn9", "malen9@gmail.com","malen2481");
    printDoubleLinkedList();

    //Ubah data awal
    cout << "<<<<<<<<<< UBAH DATA AWAL <<<<<<<<<<" << endl;
    changeFirst("Mason", "masonut23", "masonut@gmail.com","mamot2481");
    printDoubleLinkedList();

    //Ubah data akhir
    cout << "<<<<<<<<<< UBAH DATA AKHIR <<<<<<<<<<" << endl;
    changeLast("Mount", "maountaint45", "mmountain@gmail.com","mount2481");
    printDoubleLinkedList();

    //Tambah data tengah
    cout << "<<<<<<<<<< TAMBAH DATA TENGAH <<<<<<<<<<" << endl;
    addMid("Eloco", "eloco99", "eloco99@gmail.com","023199", 2);
    printDoubleLinkedList();

    //Ubah data tengah
    cout << "<<<<<<<<<< UBAH DATA TENGAH <<<<<<<<<<" << endl;
    changeMid("Gonzales", "gonzales99", "gonzales99@gmail.com","gozo248199", 2);
    printDoubleLinkedList();

    //Remove data tengah
    cout << "<<<<<<<<<< HAPUS DATA TENGAH <<<<<<<<<<" << endl;
    removeMid(2);
    printDoubleLinkedList();

    //Remove data awal
    cout << "<<<<<<<<<< HAPUS DATA AWAL <<<<<<<<<<" << endl;
    removeFirst();
    printDoubleLinkedList();

    //Remove data akhir
    cout << "<<<<<<<<<< HAPUS DATA AKHIR <<<<<<<<<<" << endl;
    removeLast();
    printDoubleLinkedList();
} 