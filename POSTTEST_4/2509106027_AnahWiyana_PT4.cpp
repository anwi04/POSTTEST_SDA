#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cctype>
#define MAX 50
using namespace std;

struct Hewan {
    int id;
    string nama;
    double harga;
};

struct Node {
    Hewan data;
    Node* next;
};

Hewan daftarHewan[MAX];
int n = 0;

Node* top = NULL;  
Node* front = NULL;    
Node* rear = NULL;    

void push(Hewan h){
    Node* baru = new Node;
    baru->data = h;
    baru->next = top;
    top = baru;

    cout << h.nama << " masuk riwayat" << endl;
}

void pop(){
    if(top == NULL){
        cout << "Stack kosong!" << endl;
        return;
    }

    Node* hapus = top;
    cout << "Hapus: " << hapus->data.nama << endl;

    top = top->next;
    delete hapus;
}

void peekStack(){
    if(top == NULL){
        cout << "Stack kosong" << endl;
    } else {
        cout << "Terakhir: " << top->data.nama << endl;
    }
}

void tampilStack(){
    if(top == NULL){
        cout << "Riwayat kosong" << endl;
        return;
    }

    Node* temp = top;
    while(temp != NULL){
        cout << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

void enqueue(Hewan h){
    Node* baru = new Node;
    baru->data = h;
    baru->next = NULL;

    if(front == NULL){
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << h.nama << " masuk antrian" << endl;
}

Hewan dequeue(){
    Hewan kosong;
    kosong.id = -1;

    if(front == NULL){
        cout << "Queue kosong!" << endl;
        return kosong;
    }

    Node* hapus = front;
    Hewan h = hapus->data;

    cout << "Dipanggil: " << h.nama << endl;

    front = front->next;
    delete hapus;

    if(front == NULL){
        rear = NULL;
    }

    return h;
}

void peekQueue(){
    if(front == NULL){
        cout << "Queue kosong" << endl;
    } else {
        cout << "Terdepan: " << front->data.nama << endl;
    }
}

void tampilQueue(){
    if(front == NULL){
        cout << "Antrian kosong" << endl;
        return;
    }

    Node* temp = front;
    while(temp != NULL){
        cout << temp->data.id << " | " << temp->data.nama << endl;
        temp = temp->next;
    }
}

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

    if(n >= MAX){
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
        cout << "1. Tambah Data Hewan" << endl;
        cout << "2. Tampilkan Data Hewan" << endl;
        cout << "3. Cari Hewan" << endl;
        cout << "4. Urutkan Nama Hewan" << endl;
        cout << "5. Urutkan Harga Hewan" << endl;
        cout << "6. Masukkan Hewan ke Antrian" << endl;
        cout << "7. Panggil Hewan untuk Pemeriksaan" << endl;
        cout << "8. Lihat Daftar Antrian" << endl;
        cout << "9. Lihat Riwayat Pemeriksaan" << endl;
        cout << "10. Hapus Riwayat Terakhir" << endl;
        cout << "11. Lihat Data Terdepan & Terakhir" << endl;
        cout << "12. Keluar" << endl;
        cout << "Pilih: ";


        if(!(cin >> pil)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input salah!" << endl;
            continue;
        }

        if(pil < 1 || pil > 12){
            cout << "Pilihan tidak valid!" << endl;
        }
        else if(pil == 1) {
            Hewan h;
            tambah(h);
            daftarHewan[n++] = h;
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
        else if(pil == 6){
            int id;
            bool ketemu = false;
            cout << "ID: ";
            cin >> id;
            for(int i=0;i<n;i++){
                if(daftarHewan[i].id == id){
                    enqueue(daftarHewan[i]);
                    ketemu = true;
                    break;
                }
            }
            if(!ketemu){
                cout << "ID tidak ditemukan!" << endl;
            }
        }
            else if(pil==7){
                Hewan h = dequeue();
                if(h.id != -1){
                    push(h);
                }
            }
            else if(pil==8){
                tampilQueue();
            }
            else if(pil==9){
                tampilStack();
            }
            else if(pil==10){
                pop();
            }
            else if(pil==11){
                peekQueue();
                peekStack();
            }
        
        } while(pil != 12);
        
     return 0;

}