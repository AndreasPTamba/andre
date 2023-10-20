#include <iostream> 
#include <algorithm>

using namespace std;

int beadSort(int a[], int len, int result[]) 
{ 
    // Find the maximum element 
    int max = a[0]; 
    for (int i = 1; i < len; i++) { 
        if (a[i] > max) { 
            max = a[i]; 
        } 
    } 

    // allocating memory 
    int **beads = new int*[len];
    for (int i = 0; i < len; i++) {
        beads[i] = new int[max];
        for (int j = 0; j < max; j++) {
            beads[i][j] = 0;
        }
    }

    // mark the beads 
    for (int i = 0; i < len; i++) { 
        for (int j = 0; j < a[i]; j++) { 
            beads[i][j] = 1; 
        } 
    } 

    // move down the beads 
    for (int j = 0; j < max; j++) { 
        int sum = 0; 
        for (int i = 0; i < len; i++) { 
            sum += beads[i][j]; 
            beads[i][j] = 0; 
        } 
        for (int i = len-1; i >= len-sum; i--) { 
            beads[i][j] = 1; 
        } 
    } 

    // to get sorted array 
    for (int i = 0; i < len; i++) { 
        int sum = 0; 
        for (int j = 0; j < max; j++) { 
            sum += beads[i][j]; 
        } 
        result[i] = sum; 
    } 

    // free memory
    for (int i = 0; i < len; i++) {
        delete[] beads[i];
    }
    delete[] beads;

    return 0; 
} 

int main(){
    int a[] = {8, 7, 4, 1, 20};
    int result[5];
    beadSort(a, 5, result);
    cout << "The sorted array is : ";
    for (int i = 0; i < 5; i++) 
        cout << result[i] << " "; 
    return 0;
}