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

Hewan daftarHewan[MAX];
int n = 0;

Hewan stack[MAX];
int top = -1;

void push(Hewan h){
    if(top >= MAX-1){
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stack[top] = h;
        cout << h.nama << " masuk riwayat" << endl;
    }
}

void pop(){
    if(top < 0){
        cout << "Stack underflow" << endl;
    } else {
        cout << "Hapus riwayat: " << stack[top].nama << endl;
        top--;
    }
}

void peekStack(){
    if(top < 0){
        cout << "Stack kosong" << endl;
    } else {
        cout << "Tindakan terakhir: " << stack[top].nama << endl;
    }
}

void tampilStack(){
    if(top < 0){
        cout << "Riwayat kosong" << endl;
        return;
    }
    for(int i=top;i>=0;i--){
        cout << (stack+i)->id << " | " << (stack+i)->nama << endl;
    }
}

Hewan queue[MAX];
int front = -1, rear = -1;

bool isFull(){
    return rear == MAX-1;
}

void enqueue(Hewan h){
    if(isFull()){
        cout << "Queue overflow" << endl;
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = h;
    cout << h.nama << " masuk antrian" << endl;
}

Hewan dequeue(){
    Hewan kosong;
    kosong.id = -1;

    if(front == -1 || front > rear){
        cout << "Queue underflow" << endl;
        return kosong;
    }

    Hewan h = queue[front];
    cout << "Dipanggil: " << h.nama << " (ID: " << h.id << ")" << endl;

    front++;

    if(front > rear){
        front = rear = -1;
    }

    return h;
}

void peekQueue(){
    if(front == -1 || front > rear){
        cout << "Queue kosong\n";
    } else {
        cout << "Pasien terdepan: " << queue[front].nama << endl;
    }
}

void tampilQueue(){
    if(front == -1 || front > rear){
        cout << "Antrian kosong\n";
        return;
    }
    for(int i=front;i<=rear;i++){
        cout << (queue+i)->id << " | " << (queue+i)->nama << endl;
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
        else if(pil==6){
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
                    cout << "ID tidak ditemukan!\n";
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