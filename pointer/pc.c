#include <stdio.h>

int sumofelement(int A[]) {
    int i, sum = 0;
    int size=(sizeof(A) / sizeof(A[0])); 
    for (int i = 0; i < size; i++)
    {
        sum += A[i];
    }
    return sum;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    // int size = sizeof(A) / sizeof(A[0]); 
    int total = sumofelement(A);  
    printf("%d\n", total);

    return 0;
}
