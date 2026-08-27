#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int keys[SIZE];
int freq[SIZE];

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        keys[i] = -1;
        freq[i] = 0;
    }
}

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (keys[(index + i) % SIZE] != -1 && keys[(index + i) % SIZE] != key) {
        i++;
        if (i == SIZE) return;
    }
    int pos = (index + i) % SIZE;
    if (keys[pos] == -1) keys[pos] = key;
    freq[pos]++;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (keys[i] != -1) {
            printf("%d --> %d times\n", keys[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {5, 7, 5, 7, 8, 9, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    initTable();
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    display();
    return 0;
}
