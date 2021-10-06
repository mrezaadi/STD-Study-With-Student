#include <iostream>

using namespace std;

//Perbedaan utama dari stack array dan stack linked list
int maks = 5;
int top = 0;
string arrayBuku[5];

int count(){
    return top;
}

bool isFull(){
    if (top == maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if (top == 0){
        return true;
    } else{
        return false;
    }
}

void pushArray(string data){
    if (isFull() == true){
        cout << "\nData Penuh" << endl;
    } else{
        arrayBuku[top] = data; //Top disini menunjukkan index
        top++; //Top disini untuk menunjukkan posisi yang merupaka +1 dari index
    }
}

void popArray(){
    if (isEmpty() == true){
        cout << "\nData Kosong" << endl;
    } else{
        arrayBuku[top-1] = "";
        top--;
    }
}

void peekArray(int posisi){ //Posisi dimulai dari paling atas dan dimulai dari 1
    int index = top; //Nilai top itu lebih 1 dari index aslinya
    if (isEmpty() == true){
        cout << "\nData Kosong" << endl;;
    } else{
        for (int i=0; i < posisi; i++){
            index--; //Karena posisi top +1 dari index, maka perlu dikurangin
        }
    }

    cout << "\nData posisi ke- " << posisi << ": " << arrayBuku[index] << endl; 
}

void changeArray(string buku, int posisi){
    int index = top; //Nilai top itu lebih 1 dari index aslinya
    if (isEmpty() == true){
        cout << "\nData Kosong" << endl;;
    } else{
        for (int i=0; i < posisi; i++){
            index--; //Karena posisi top +1 dari index, maka perlu dikurangin
        }
    }
    arrayBuku[index] = buku;
}

void destroyArray(){
    while (top > 0){
        arrayBuku[top-1] = "";
        top--;
    }
}

void displayArray(){
    cout << "\n========== DATA BUKU ==========" << endl;
    for (int i = top-1; i >=0; i--){
        if (arrayBuku[i] != ""){

            cout << arrayBuku[i] << endl;
        }
    }
}

int main(){
    pushArray("Matematika");
    pushArray("Fisika");
    pushArray("Jaringan Komputer");
    displayArray();

    cout << "\nApakah data Full? " << isFull() << endl;
    cout << "Apakah data Kosong? " << isEmpty() << endl;

    cout << "\n<<<<<<<<<< SETELAH POP >>>>>>>>>>" << endl;
    popArray();
    displayArray();

    cout << "\nApakah data Full? " << isFull() << endl;
    cout << "Apakah data Kosong? " << isEmpty() << endl;

    peekArray(1);

    cout << "\n<<<<<<<<<< SETELAH CHANGE >>>>>>>>>>" << endl;
    changeArray("Mekanika Quantum", 1);
    displayArray();

    destroyArray();
    cout << "\n<<<<<<<<<< SETELAH DESTROY >>>>>>>>>>" << endl;
    displayArray();
    cout << "\nApakah data Full? " << isFull() << endl;
    cout << "Apakah data Kosong? " << isEmpty() << endl;
}