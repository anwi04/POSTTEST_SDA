#include <iostream>
using namespace std;

// Fungsi untuk membalik array menggunakan pointer
void reverseArray(int* arr, int n){
    int *awal = arr;
    int *akhir = arr + n - 1;

    while(awal < akhir){
        int tukar = *awal;
        *awal = *akhir;
        *akhir = tukar;

        awal++;
        akhir--;
    }
}

int main() {

    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik:\n";
    int *temp = data;
    while(temp < data + n){
        cout << "Nilai: " << *temp 
             << ", Alamat: " << temp << endl;
        temp++;
    }

    // Memanggil fungsi
    reverseArray(data, n);

    cout << "\nArray sesudah dibalik:\n";
    temp = data;
    while(temp < data + n){
        cout << "Nilai: " << *temp 
             << ", Alamat: " << temp << endl;
        temp++;
    }

    return 0;
}