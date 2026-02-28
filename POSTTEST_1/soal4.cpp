#include <iostream>
using namespace std;

void tukar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int x, y;

    cout << "Masukkan nilai pertama: ";
    cin >> x;

    cout << "Masukkan nilai kedua: ";
    cin >> y;

    cout << "\nSebelum ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukar(&x, &y);

    cout << "\nSesudah ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}