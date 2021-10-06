#include <iostream>

using namespace std;

int front = 0, back = 0;
const int maks = 5;

string antrian[maks];

bool isEmpty(){
    if (back==0){
        return true;
    } else{
        return false;
    }
}

bool isFull(){
    if (back == maks){
        return true;
    } else{
        return false;
    }
}

int countArray(){
    return back;
}


//Penambahan data
void enqueueArray(string data){
    if (isFull() == true){
        cout << "========= DATA PENUH ==========" << endl;
    } else{
        if (isEmpty() == true){
            antrian[front] = data;
            front++;
            back++;
        } else{
            antrian[back] = data;
            back++;
        }
    }
}

//Pengurangan data
void dequeueArray(){
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else{
        for (int i = 0; i < maks-1; i++){
            antrian[i] = antrian[i+1];
        }
        back--;
        if (back == 0){
            front = 0;
        }
    }
}

void destroyArray(){
    for (int i = back-1; i > 0;i--){
        antrian[i] = "";
    }
    front = 0;
    back = 0;
}

void displayArray(){
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else{
        cout<< "========== DATA ANTRIAN ==========" << endl;
        for (int i = 0; i < maks; i++){
            if (antrian[i] != ""){
                cout << "Antrian ke " << i+1 << ": " << antrian[i] << endl;
            } else{
                cout << "Antrian ke " << i+1 << ": " << "(Kosong)" << endl;
            }
        }
    }
    cout << "Jumlah Data : " << countArray() << endl;
}


int main(){
    enqueueArray("Reza");
    enqueueArray("Rizqy");
    enqueueArray("Shanum");
    enqueueArray("Azzahra");
    displayArray();

    cout << "\n" << endl;
    dequeueArray();
    displayArray();

    cout << "\n" << endl;
    dequeueArray();
    displayArray();

    cout << "\n" << endl;
    dequeueArray();
    displayArray();

    cout << "\n" << endl;
    dequeueArray();
    displayArray();

    enqueueArray("Reza");
    enqueueArray("Rizqy");
    enqueueArray("Shanum");
    enqueueArray("Azzahra");
    displayArray();

    cout << "========== DESTROY ==========" << endl;
    destroyArray();
    displayArray();
}