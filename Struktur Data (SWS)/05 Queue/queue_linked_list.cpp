#include <iostream>

using namespace std;

struct antrian{
    string nama;
    string kelas;
    int usia;

    antrian *next;
};


int maks = 5;
antrian *head, *tail, *cur, *before, *newNode, *delNode;

int count(){
    if (head == NULL){
        return 0;
    } else{
        int sum = 0;
        cur=head;
        while(cur != NULL){
            cur = cur->next;
            sum++;
        }
        return sum;
    }
}

bool isFull(){
    if (count() == maks){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if (count() == 0){
        return true;
    } else{
        return false;
    }
}

void enqueue(string nama, string kelas, int usia){
    if (isFull() == true){ 
        cout <<"\n========= DATA PENUH =========="<< endl;    
    } else{
        if (isEmpty() == true){
            head = new antrian();
            head->nama = nama;
            head->kelas = kelas;
            head->usia = usia;
            head->next = NULL;

            tail = head;
        } else{
            cur=head;
            while(cur != NULL){
                cur = cur->next;
            }

            cur = new antrian();
            cur->nama = nama;
            cur->kelas = kelas;
            cur->usia = usia;

            tail->next = cur;
            cur->next = NULL;

            tail = cur;
        }
    }
}

void dequeue(){
    if(isEmpty() == true){
        cout << "\n========== DATA KOSONG ==========" << endl;
    } else{
        delNode = head;
        head = head->next;
        delNode->next = NULL;

        delete delNode;
    }
}

void destroy(){
    cur=head;
    while (cur != NULL){
        delNode = cur;
        cur = cur->next;
        delNode->next = NULL;
        delete delNode;
    }
    head = NULL;
    tail = NULL;
}

void display(){
    cout << "\n========== DATA ANTRIAN ==========" << endl;
    
    if (isEmpty() == true){
        cout << "========== DATA KOSONG ==========" << endl;
    } else{
        cout << "Jumlah data : " << count() << endl;
        cur=head;
        for (int i = 1; i <= maks ; i++){
            if (cur != NULL){
                cout << "Antrian ke " << i << ": " << cur->nama << "\t||" << cur->kelas << "\t||" << cur->usia  << endl;
                cur = cur->next;
            } else{
                cout << "Antrian ke " << i << ": " << "(Kosong)" << endl;
            }
        }
    }
}

int main(){
    enqueue("Reza", "IF-44-05", 19); 
    enqueue("Lewis", "IT-22-01", 34); 
    enqueue("Vettel", "FK-34-05", 41); 
    display();

    enqueue("Lando", "IT-22-01", 34); 
    enqueue("Sainz", "FK-34-05", 41);

    enqueue("Kimi", "FK-34-05", 41);
    display();

    cout << "\n========== SETELAH DEQUEUE ==========" << endl;
    dequeue();
    display();

    cout << "\n========== SETELAH DESTROY ==========" << endl;
    destroy();
    display();
    
}