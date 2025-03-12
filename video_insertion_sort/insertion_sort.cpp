#include <iostream>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        
        // Move elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    // Test case 1: Positive numbers
    int test1[] = {5, 2, 4, 6, 1, 3};
    int test1Size = sizeof(test1) / sizeof(test1[0]);
    
    std::cout << "Test Case 1 - Original array: ";
    printArray(test1, test1Size);
    
    insertionSort(test1, test1Size);
    
    std::cout << "Test Case 1 - Sorted array: ";
    printArray(test1, test1Size);
    std::cout << std::endl;

    // Test case 2: Negative numbers
    int test2[] = {-3, -1, -5, -2, -4};
    int test2Size = sizeof(test2) / sizeof(test2[0]);
    
    std::cout << "Test Case 2 - Original array: ";
    printArray(test2, test2Size);
    
    insertionSort(test2, test2Size);
    
    std::cout << "Test Case 2 - Sorted array: ";
    printArray(test2, test2Size);
    
    return 0;
}
