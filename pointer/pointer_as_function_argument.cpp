#include <bits/stdc++.h>
using namespace std;

int sumofelement(int *A) {
    int sum = 0;
    int size = sizeof(A) / sizeof(A[0]); 
    // Incorrect size calculation
    cout<<"size of a = "<<sizeof(A)<<"   size of a[0]    :"<<sizeof(A[0])<<endl;
    for (int i = 0; i < size; i++) {
        sum += A[i];
    }
    return sum;
}

int main() {
    int A[] = {1, 2, 3, 4, 5};
    int total = sumofelement(A); 
    cout << total << endl;
    return 0;
}
