#include <iostream>

using namespace std;

struct Kampus{
    string nama, negara;
    int tahun;   
};

struct Mahasiswa{
    string nama, nim, jurusan;
    int umur;
    Kampus kmps;
    struct AlamatMhs{
        string provinsi, kota;

    } alamat;
    string hobi[3];  
};

//Urutan deklarasi fungsi/procedure berpengaruh
//Pastikan semua yang dibutuhkan dalam fungsi sudah dideklarasi diatasnyas

void cetakDataMahasiswa(Mahasiswa data){
    cout << "\nNama Mahasiswa \t\t: " << data.nama << endl;
    cout << "Nim Mahasiswa \t\t: " << data.nim << endl;
    cout << "Jurusan Mahasiswa \t: " << data.jurusan << endl;
    cout << "Umur Mahasiswa \t\t: " << data.umur << endl;
    cout << "Nama Kampus \t\t: " << data.kmps.nama << endl;
    cout << "Negara Kampus \t\t: " << data.kmps.negara << endl;
    cout << "Tahun Kampus \t\t: " << data.kmps.tahun << endl;
    cout << "Provinsi Mahasiswa \t: " << data.alamat.provinsi << endl;
    cout << "Kota Mahasiswa \t\t: " << data.alamat.kota << endl;
    cout << "Hobi Mahasiswa \t\t: " << data.hobi[0] << endl;
    cout << "Hobi Mahasiswa \t\t: " << data.hobi[1] << endl;
    cout << "Hobi Mahasiswa \t\t: " << data.hobi[2] << endl;
}

int main(){

    Mahasiswa mhs[3];

    //Biasanya jika struct dipisah mempunyai fungsinya sendiri
    //Untuk mempercepat kita buat variabel kampusTelkom
    Kampus kampusTelkom = {"Telkom University", "Indonesia", 1945}; 
    //Tidak bisa langsung mengakses structure yang ada di dalam structure


    mhs[0].nama = "Muhammad Reza Adi Nugraha";
    mhs[0].nim = "1301204078";
    mhs[0].jurusan = "Informatika";    
    mhs[0].umur = 20;
    mhs[0].kmps = kampusTelkom;
    mhs[0].alamat.provinsi = "Jawa Barat";
    mhs[0].alamat.kota = "Cirebon";
    mhs[0].hobi[0] = "Bernafas";
    mhs[0].hobi[1] = "Minum Air";

    cetakDataMahasiswa(mhs[0]);


    mhs[1] = {"Muhammad Rizqy Dwi Putra", "13023012", "Manajemen", 24,
    {"Universitas Indonesia", "Indonesia", 1910},
    {"Jawa Barat", "Bandung"},{"Tidur", "Olahraga"}};

    cetakDataMahasiswa(mhs[1]);


    mhs[2].nama = "Muhammad Fajar Pakar Junjunana";
    mhs[2].nim = "1301204091";
    mhs[2].jurusan = "Informatika";    
    mhs[2].umur = 27;
    mhs[2].kmps = kampusTelkom;
    mhs[2].alamat.provinsi = "Jawa Barat";
    mhs[2].alamat.kota = "Cirebon";
    mhs[2].hobi[0] = "Mewarnai";
    mhs[2].hobi[1] = "Minum Kopi";

    cetakDataMahasiswa(mhs[2]);

}