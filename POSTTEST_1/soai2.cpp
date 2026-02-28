#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];

    // Input data 5 mahasiswa
    for(int i = 0; i < 5; i++) {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    // Mencari IPK tertinggi
    int maxIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[maxIndex].ipk) {
            maxIndex = i;
        }
    }

    // Menampilkan mahasiswa dengan IPK tertinggi
   cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[maxIndex].nama << endl;
    cout << "NIM  : " << mhs[maxIndex].nim << endl;
    cout << "IPK  : " << mhs[maxIndex].ipk << endl;
    return 0;
}