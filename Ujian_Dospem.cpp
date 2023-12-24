#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

struct KARYAWAN{
    string NamaKaryawan;
    int NomerKaryawan;
    string AlamatKaryawan;
    int LamaBekerja;
};

double MenghitungTunjangan(int gaji, int LAMabeKerjA){
    double tunjangan = 0;
    if (LAMabeKerjA < 5){
        tunjangan = 0.05 * gaji;
    }
    else if(LAMabeKerjA > 5 && LAMabeKerjA < 10){
        tunjangan = 0.1 * gaji;
    }
    else if(LAMabeKerjA > 10){
        tunjangan = 0.15 * gaji;
    }
    return tunjangan;
}

int main(){
    KARYAWAN karyawan [1000];
    int jumlahkaryawan = 0;

    int nomerkaryawan;
    string alamatkaryawan;
    int LAMabeKerjA;
    int gaji;
    double tunjangan;
    string nama;
    cout << fixed << setprecision(2);
    cout << "[+] Inputkan jumlah karyawan yang di tambahkan : "; cin >> jumlahkaryawan;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i = 0; i < jumlahkaryawan; i++){
        cout << "Karyawan ke " << i + 1 << endl;
        cout << "[!] Masukkan Nama Karyawan : " ;getline(cin, nama);
        cout << "[!] Masukkan Nomor Karyawan : "; cin >> nomerkaryawan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[!] Masukkan Alamat Karyawan : "; getline(cin, alamatkaryawan);
        cout << "[!] Berapa lama Bekerja : "; cin >> LAMabeKerjA;

        karyawan[i].NamaKaryawan = nama;
        karyawan[i].NomerKaryawan = nomerkaryawan;
        karyawan[i].AlamatKaryawan = alamatkaryawan;
        karyawan[i].LamaBekerja = LAMabeKerjA;
        int gajiperbulan;
        cout << "Masukkan Input Gaji Karyawan Perbulan nya Rp. " ; cin >> gajiperbulan;
        gaji = gajiperbulan * karyawan[i].LamaBekerja;
        tunjangan = MenghitungTunjangan(gaji, karyawan[i].LamaBekerja);
        cout << "[+] Gaji Karyawan Rp. \n" << gaji << endl;
        cout << "[+] Tunjangan Karyawan Rp. " << tunjangan << endl;
        cout << "[+] Total Penghasilan : Rp. " << gaji + tunjangan << endl;
        int totalpendapatan = gaji + tunjangan ;
        if(totalpendapatan > 8000000){
            cout << "[!] Karena Melebihi 8 Juta Maka Dikenakan Pajak Penghasilan Sebesar '5%' Dari Total Pendapatan Awal !\n";
            int potongan;
            potongan = 0.05 * totalpendapatan;
            totalpendapatan -= potongan;
            cout << "[!] Dikenai Pajak Penghasilan Sebesar Rp. " << potongan << endl;
            cout << "[+] Total Penghasilan Menjadi Rp. " << totalpendapatan << endl;
        } cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}