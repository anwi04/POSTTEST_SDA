#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

struct Hewan {
    int id;
    string nama;
    double harga;
};

Hewan daftarHewan[50];
int n = 0;

void tukar(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

bool cekID(int id){
    for(int i=0;i<n;i++){
        if(daftarHewan[i].id == id){
            return true;
        }
    }
    return false;
}

void tambah(Hewan &h) {

    if(n >= 50){
        cout << "Data penuh!" << endl;
        return;
    }

    while(true){
        cout << "ID: ";

        if(!(cin >> h.id)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input harus angka!" << endl;
            continue;
        }

        if(cekID(h.id)){
            cout << "ID sudah ada! ulangi" << endl;
            continue;
        }

        break;
    }

    cout << "Nama: ";
    cin.ignore();
    getline(cin, h.nama);

    cout << "Harga: ";
    
    while(!(cin >> h.harga)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harga harus angka!" << endl;
    }
}

void tampil(Hewan *arr) {
    cout << "=== Data Hewan ===" << endl;
    cout << fixed << setprecision(0);
    for(int i = 0; i < n; i++) {
        cout << (arr+i)->id << " | "
             << (arr+i)->nama << " | "
             << (arr+i)->harga << endl;
    }
}

string toLower(string s){
    for(int i=0;i<s.length();i++){
        s[i] = tolower(s[i]);
    }
    return s;
}

void linearSearch(Hewan *arr, string x) {
    bool ketemu = false;
    for(int i = 0; i < n; i++) {
        if(toLower((arr+i)->nama) == toLower(x)) {
            cout << "Ditemukan: " << (arr+i)->nama << endl;
            ketemu = true;
        }
    }
    if(!ketemu) cout << "Tidak ditemukan" << endl;
}

void sortID(Hewan *arr){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((arr+j)->id > (arr+j+1)->id){
                tukar(arr+j, arr+j+1);
            }
        }
    }
}

int binarySearch(Hewan *arr, int x) {
    sortID(arr);

    int kiri = 0, kanan = n - 1;

    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        cout << "Cek index " << tengah
             << " (ID: " << (arr+tengah)->id << ")" << endl;

        if((arr+tengah)->id == x) return tengah;
        else if((arr+tengah)->id < x) kiri = tengah + 1;
        else kanan = tengah - 1;
    }
    return -1;
}
// PROSES ITERASI:
// 1. Data diurutkan dulu berdasarkan ID
// 2. Tentukan index tengah
// 3. Bandingkan ID tengah dengan yang dicari
// 4. Jika lebih kecil > geser ke kanan
// 5. Jika lebih besar > geser ke kiri
// 6. Ulangi sampai ketemu atau tidak ditemukan

void bubbleSort(Hewan *arr) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(toLower((arr+j)->nama) > toLower((arr+j+1)->nama)) {
                tukar(arr+j, arr+j+1);
            }
        }
    }
    cout << "Sorting nama selesai" << endl;
}

void selectionSort(Hewan *arr) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if((arr+j)->harga < (arr+min)->harga) {
                min = j;
            }
        }
        tukar(arr+i, arr+min);
    }
    cout << "Sorting harga selesai" << endl;
}

int main() {
    int pil;

    do {
        cout << "==== PAWCARE PETSHOP ====" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampil Data" << endl;
        cout << "3. Cari Nama" << endl;
        cout << "4. Sort Nama" << endl;
        cout << "5. Sort Harga" << endl;
        cout << "6. Binary Search ID" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";

        if(!(cin >> pil)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input salah!" << endl;
            continue;
        }

        if(pil < 1 || pil > 7){
            cout << "Pilihan tidak valid!" << endl;
        }
        else if(pil == 1) {
            tambah(daftarHewan[n]);
            n++;
        }
        else if(pil == 2) {
            tampil(daftarHewan);
        }
        else if(pil == 3) {
            string x;
            cout << "Nama: ";
            cin.ignore();
            getline(cin, x);
            linearSearch(daftarHewan, x);
        }
        else if(pil == 4) {
            bubbleSort(daftarHewan);
        }
        else if(pil == 5) {
            selectionSort(daftarHewan);
        }
        else if(pil == 6) {
            int id;
            cout << "ID: "; cin >> id;
            int hasil = binarySearch(daftarHewan, id);
            if(hasil != -1)
                cout << "Ditemukan di index " << hasil << endl;
            else
                cout << "Tidak ditemukan" << endl;
        }

    } while(pil != 7);

    return 0;
}