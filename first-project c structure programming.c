#include <stdio.h>
int array[100];
int n = 0;
void insert() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    if (n < 100) {
        array[n++] = val;
    }
    else {
        printf("Array is full!\n");
    }
}
void update() {
    int index, val;
    printf("Enter index to update (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        printf("Enter new value: ");
        scanf("%d", &val);
        array[index] = val;
    }
    else {
        printf("Invalid index!\n");
    }
}
void delete() {
    int index;
    printf("Enter index to delete (0 to %d): ", n - 1);
    scanf("%d", &index);
    if (index >= 0 && index < n) {
        for (int i = index; i < n - 1; i++) {
            array[i] = array[i + 1];
        }
        n--;
    }
    else {
        printf("Invalid index!\n");
    }
}
void display() {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
}
printf("\n");
}
void sort() {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}
void search() {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (array[i] == val) {
            printf("Value found at index: %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value not found!\n");
    }
}
int main() {
    int choice;
    do {
        printf("\n--- Array Operation Menu ---\n");
        printf("1. Insert\n2. Update\n3. Delete\n4. Display\n5. Sort\n6. Search\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert();break;
            case 2: update(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: sort(); break;
            case 6: search(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}
