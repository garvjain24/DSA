#include <stdio.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    return 7 - (key % 7);
}

void Insert(int key) {
    int index = hashFunction1(key);
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int index2 = hashFunction2(key);
        int i = 1;
        int newIndex = (index + i * index2) % TABLE_SIZE;
        while (hashTable[newIndex] != -1) {
            i++;
            newIndex = (index + i * index2) % TABLE_SIZE;
        }
        hashTable[newIndex] = key;
    }
}

void display() {
    printf("Hash Table: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int search(int key) {
    int index = hashFunction1(key);
    if (hashTable[index] == key) {
        return index;
    } else {
        int index2 = hashFunction2(key);
        int i = 1;
        int newIndex = (index + i * index2) % TABLE_SIZE;
        while (hashTable[newIndex] != key && hashTable[newIndex] != -1) {
            i++;
            newIndex = (index + i * index2) % TABLE_SIZE;
        }
        if (hashTable[newIndex] == key) {
            return newIndex;
        } else {
            return -1; // Key not found
        }
    }
}

int main() {
    initHashTable();

    Insert(5);
    Insert(15);
    Insert(25);
    Insert(7);
    Insert(18);

    display();

    int searchKey = 7;
    int found = search(searchKey);

    if (found != -1) {
        printf("Key %d found at index %d\n", searchKey, found);
    } else {
        printf("Key %d not found in the hash table\n", searchKey);
    }

    return 0;
}
