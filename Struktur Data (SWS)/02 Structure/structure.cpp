#include <iostream>

using namespace std;

struct Mahasiswa{
    string nama, nim, jurusan;
    int umur;
    string hobi[3];  
};

int main(){
    Mahasiswa mhs1, mhs2;

    //Cara 1
    mhs1.nama = "Muhammad Reza Adi Nugraha";
    mhs1.nim = "1301204078";
    mhs1.jurusan = "Informatika";    
    mhs1.umur = 20;
    mhs1.hobi[0] = "Bernafas";
    mhs1.hobi[1] = "Minum Air";

    cout << "Nama Mahasiswa \t\t: " << mhs1.nama << endl;
    cout << "Nim Mahasiswa \t\t: " << mhs1.nim << endl;
    cout << "Jurusan Mahasiswa \t: " << mhs1.jurusan << endl;
    cout << "Umur Mahasiswa \t\t: " << mhs1.umur << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs1.hobi[0] << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs1.hobi[1] << endl;


    //Cara 2
    mhs2 = {"Muhammad Rizqy Dwi Putra", "13023012", "Manajemen", 24,{"Tidur", "Olahraga"}}; //Memasukkan datanya harus terurut
    cout << "\nNama Mahasiswa \t\t: " << mhs2.nama << endl;
    cout << "Nim Mahasiswa \t\t: " << mhs2.nim << endl;
    cout << "Jurusan Mahasiswa \t: " << mhs2.jurusan << endl;
    cout << "Umur Mahasiswa \t\t: " << mhs2.umur << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs2.hobi[0] << endl;
    cout << "Hobi Mahasiswa \t\t: " << mhs2.hobi[1] << endl;

    return 0;
}
