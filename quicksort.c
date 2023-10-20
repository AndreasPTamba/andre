#include <stdio.h>

// Fungsi untuk mempartisi array dan mengembalikan indeks pivot
// Waktu kompleksitas: O(n)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
    int i = low - 1; // Inisialisasi indeks elemen yang lebih kecil
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; // Tambahkan indeks elemen yang lebih kecil
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            // Tukar arr[i] dan arr[j]
            // Operasi ini memakan waktu konstan, O(1)
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    // Tukar arr[i + 1] dan arr[high]
    // Operasi ini memakan waktu konstan, O(1)
    return i + 1; // Kembalikan indeks pivot
    // Operasi ini memakan waktu konstan, O(1)
}

// Fungsi untuk mengimplementasikan algoritma quicksort
// Waktu kompleksitas: O(n log n) pada kasus rata-rata, O(n^2) pada kasus terburuk
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Dapatkan indeks pivot
        quicksort(arr, low, pi - 1); // Urutkan subarray kiri
        quicksort(arr, pi + 1, high); // Urutkan subarray kanan
        // Operasi ini rekursif dan kompleksitas waktu mereka tergantung pada ukuran subarray
    }
}

// Kode driver untuk menguji algoritma quicksort
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Inisialisasi array yang akan diurutkan
    int n = sizeof(arr) / sizeof(arr[0]); // Dapatkan ukuran array

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Cetak array yang belum diurutkan
        // Operasi ini memakan waktu konstan, O(1)
    }
    printf("\n");

    quicksort(arr, 0, n - 1); // Urutkan array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Cetak array yang telah diurutkan
        // Operasi ini memakan waktu konstan, O(1)
    }
    return 0; // Keluar dari program
    // Operasi ini memakan waktu konstan, O(1)
}
