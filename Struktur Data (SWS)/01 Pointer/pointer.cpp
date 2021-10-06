#include <iostream>

using namespace std;
int main(){
    //Deklarasi variabel pointer
    string nama = "Muhammad Reza Adi Nugraha";
    string *ptrnama = &nama;

    cout << "Isi variabel nama: " << nama << endl;
    cout << "Ada pada alamat : " << &nama << endl;

    cout << "\nAlamat ptrnama: " << ptrnama << endl;
    cout << "Isi ptrnama: " << *ptrnama << endl;

    *ptrnama = "Komputer";
    //Isi dari variabel nama ikut berubah, karena pointer ptrnama merujuk pada alamat variabel nama
    //Jadi saat merubah nilai pada ptrnama, nilai variabel nama ikut berubah karena alamatnya sama
    cout << "\nIsi variabel nama: " << nama << endl;
    cout << "Isi ptrnama: " << *ptrnama << endl;

    int nilai = 10;
    int *ptrnilai = &nilai;
    cout << "\nIsi variabel nilai: " << nilai << endl;
    cout << "Ada pada alamat : " << &nilai << endl;

    cout << "\nAlamat ptrnilai: " << ptrnilai << endl;
    cout << "Isi ptrnilai : " << *ptrnilai << endl;

    (*ptrnilai)++; //Kalau menggunakan increment harus didalam kurung
    cout << "\nIsi variabel nilai: " << nilai << endl;
    cout << "Ada pada alamat : " << ptrnilai << endl;

    cout << "Isi ptrnilai: " << *ptrnilai << endl;
    cout << "Ada pada alamat : " << ptrnilai << endl;



    int a = 5;

    int *ptr1; //Pointer menunjukkan alamat
    ptr1 = &a;

    int *ptr2;
    ptr2 = &a;

    cout << "\nIsi variabel ptr1 : " << *ptr1 << endl;
    cout << "Ada pada alamat : " << ptr1 << endl;

    cout << "\nIsi variabel ptr2 : " << *ptr2 << endl;
    cout << "Ada pada alamat : " << ptr2 << endl;



    return 0;
}