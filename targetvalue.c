#include <stdio.h>
#include <stdlib.h>

#define SIZE 100  // Hash table size (should be >= array size)

int hashTable[SIZE];

// Initialize hash table
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = 0;  // 0 means not present
    }
}

// Hash function
int hash(int key) {
    if (key < 0) key = -key;  // handle negatives
    return key % SIZE;
}

// Insert into hash table
void insert(int key) {
    int index = hash(key);
    // Simple linear probing for collisions
    while (hashTable[index] != 0) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Search in hash table
int search(int key) {
    int index = hash(key);
    int start = index;
    while (hashTable[index] != 0) {
        if (hashTable[index] == key) return 1;
        index = (index + 1) % SIZE;
        if (index == start) break; // full loop
    }
    return 0;
}

// Function to check if two numbers sum to T
int twoSum(int arr[], int n, int T) {
    initTable();
    for (int i = 0; i < n; i++) {
        int complement = T - arr[i];
        if (search(complement)) {
            printf("Pair found: (%d, %d)\n", arr[i], complement);
            return 1;
        }
        insert(arr[i]);
    }
    return 0;
}

int main() {
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int T = 9;

    if (!twoSum(arr, n, T)) {
        printf("No pair found with sum %d\n", T);
    }

    return 0;
}


