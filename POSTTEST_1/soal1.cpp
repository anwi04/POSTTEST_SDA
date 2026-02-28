#include <iostream>
using namespace std;

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int min = A[0];
    int max = A[0];
    int idxmin = 0;
    int idxmax = 0;

    for(int i = 1; i < n; i++){
        if(A[i] < min){
            min = A[i];
            idxmin = i;
        }
        if(A[i] > max){
            max = A[i];
            idxmax = i;
        }
    }

    cout << "Nilai Minimum : " << min << endl;
    cout << "Indeks Minimum : " << idxmin << endl;

    cout << "Nilai Maksimum : " << max << endl;
    cout << "indeks Minimum : " << idxmax <<endl;
    
    return 0;
}
