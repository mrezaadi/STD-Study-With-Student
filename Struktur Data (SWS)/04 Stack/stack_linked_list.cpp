#include <iostream>

using namespace std;
//Gunakan double linkedlist

struct dataBarang{
    string nama;
    int harga;

    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head, *tail, *cur, *before, *after, *newNode, *delNode;

int maks = 5;

int countData(){
    if (head==NULL){
        return 0;
    } else{
        int jumlah = 0;
        cur=head;
        while (cur != NULL){
            cur= cur->next;
            jumlah++;
        }
        return jumlah;
    }
}

bool isFull(){
    if (countData() == maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if (countData() == 0){
        return true;
    } else{
        return false;
    }
}

void pushStack(string nama, int harga){
    if (countData() == maks){
        cout << "\n========== DATA PENUH ==========" << endl;
    } else{
        if (isEmpty() == true){
            //Create
            head = new dataBarang();
            head->nama = nama;
            head->harga = harga;
            head->next = NULL;
            head->prev = NULL;
            tail=head;
        } else{
            //Push
            newNode = new dataBarang();
            newNode->nama = nama;
            newNode->harga = harga;

            newNode->prev = tail;
            tail->next = newNode;   

            newNode->next = NULL;

            tail=newNode;
        }
    }
}

void popStack(){
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else{
        delNode = tail;
        
        before=tail->prev;
        before->next = NULL;
        tail=before;

        delete delNode;
    }
}

void peekStack(int posisi){
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else {
        if (posisi > maks || posisi <= 0){
            cout << "POSISI TIDAK VALID" << endl;
        } else{
            int nomor = 1;
            cur=tail;
            while (nomor != posisi){
                nomor++;
                cur = cur->prev;
            }

            cout << "Data pada posisi ke- " << posisi << " adalah" << endl;
            cout << "Nama barang \t: " << cur->nama << endl;
            cout << "Harga \t\t: Rp. " << cur->harga << "\n" << endl;
        }
    }
}

void changeStack(string nama, int harga, int posisi){
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else {
        if (posisi > maks || posisi <= 0){
            cout << "POSISI TIDAK VALID" << endl;
        } else{
            int nomor = 1;
            cur=tail;
            while (nomor != posisi){
                nomor++;
                cur = cur->prev;
            }
            cur->nama = nama;
            cur->harga = harga;
        }
    }
}

void destroyStack(){
    cur=head;
    while(cur != NULL){
        delNode =cur;
        head=head->next;
        delete delNode;
        cur=cur->next;
    }
}

void displayStack(){
    if (head == NULL){
        cout << "\n========== DATA KOSONG ==========" << endl;
    } else{
            cout << "\n========== DATA BARANG ==========" << endl;
        cur=tail;
        while (cur != NULL){
            cout << "Nama barang \t: " << cur->nama << endl;
            cout << "Harga \t\t: Rp. " << cur->harga << "\n" << endl;
            cur = cur->prev;
        }
    }
}

int main(){

    cout << "\nApakah data full? " << isFull() << endl;
    cout << "\nApakah data kosong? " << isEmpty() << endl;

    pushStack("RAM", 500000);
    pushStack("Motherboard", 1000000);
    pushStack("Processor", 25000000);
    displayStack();
    cout << "\nApakah data full? " << isFull() << endl;
    cout << "\nApakah data kosong? " << isEmpty() << endl;


    pushStack("Webcam", 210000);
    pushStack("VGA", 100000000);
    displayStack();
    cout << "\nApakah data full? " << isFull() << endl;
    cout << "\nApakah data kosong? " << isEmpty() << endl;

    pushStack("Laptop Merah Putih", 10000000);
    cout << "\n <<<<<<<<<< SETELAH POP >>>>>>>>>> " << endl;
    popStack();

    pushStack("Laptop Merah Putih", 10000000);
    displayStack();

    peekStack(3);
    changeStack("Mechanical Keyboard", 450000, 3);
    displayStack();

    cout << "\n <<<<<<<<<< SETELAH DESTROY >>>>>>>>>> " << endl;
    destroyStack();
    displayStack();
    cout << "\nApakah data full? " << isFull() << endl;
    cout << "\nApakah data kosong? " << isEmpty() << endl;
}



