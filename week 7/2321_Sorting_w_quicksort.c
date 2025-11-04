#include <stdio.h>

// 
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // the last element as pivot
    int i = left - 1;       // place for swapping 

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            // I might have another function for swapping later
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // placing the pivot in the correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1; // return the pivot index 
}

// Recursive quicksort
void quicksort(int arr[], int left, int right) {
    
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex - 1);  // sort left side
        quicksort(arr, pivotIndex + 1, right); // sort right side
    }
}

int main() {
    
    int n, arr[1000];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}
