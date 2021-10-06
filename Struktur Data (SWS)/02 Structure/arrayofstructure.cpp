#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama, nim, jurusan;
    int umur;
    string hobi[3];  
};

int main(){
    //Cara 1
    Mahasiswa mhs[2];

    mhs[0].nama = "Muhammad Reza Adi Nugraha";
    mhs[0].nim = "1301204078";
    mhs[0].jurusan = "Informatika";    
    mhs[0].umur = 20;
    mhs[0].hobi[0] = "Bernafas";
    mhs[0].hobi[1] = "Minum Air";

    cout << "Nama Mahasiswa \t\t: " << mhs[0].nama << endl;
    cout << "Nim Mahasiswa \t\t: " << mhs[0].nim << endl;
    cout << "Jurusan Mahasiswa \t: " << mhs[0].jurusan << endl;
    cout << "Umur Mahasiswa \t\t: " << mhs[0].umur << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs[0].hobi[0] << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs[0].hobi[1] << endl;


    //Cara 2
    mhs[1] = {"Muhammad Rizqy Dwi Putra", "13023012", "Manajemen", 24,{"Tidur", "Olahraga"}}; //Memasukkan datanya harus terurut
    cout << "\nNama Mahasiswa \t\t: " << mhs[1].nama << endl;
    cout << "Nim Mahasiswa \t\t: " << mhs[1].nim << endl;
    cout << "Jurusan Mahasiswa \t: " << mhs[1].jurusan << endl;
    cout << "Umur Mahasiswa \t\t: " << mhs[1].umur << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs[1].hobi[0] << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs[1].hobi[1] << endl;

    return 0;
}