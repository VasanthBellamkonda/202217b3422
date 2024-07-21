#include <stdio.h>
//#include <conio.h> // Remove unnecessary header
#include <stdlib.h> // For exit()

#define MAX_SIZE 20

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

int b[MAX_SIZE]; // Array to hold elements
int n; // Number of elements in the array

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0); // Exit the program
            default:
                printf("\nEnter the correct choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &g); // Note the space before %c to consume the newline
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("\nExceeded maximum size (%d). Setting to maximum size.\n", MAX_SIZE);
        n = MAX_SIZE;
    }

    printf("\nEnter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;

    if (n == 0) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid position.\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("\nElement at position %d deleted successfully.\n", pos);
}

void search() {
    int e;
    printf("\nEnter the element to search: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            return; // Exit function if found
        }
    }

    printf("Element %d not found in the list.\n", e);
}

void insert() {
    int pos, p;

    if (n == MAX_SIZE) {
        printf("\nList is full. Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid position.\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &p);

    for (int i = n - 1; i >= pos; i--) {
        b[i + 1] = b[i];
    }
    b[pos] = p;
    n++;

    printf("\nElement %d inserted at position %d.\n", p, pos);
}

void display() {
    if (n == 0) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nThe elements in the list are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
