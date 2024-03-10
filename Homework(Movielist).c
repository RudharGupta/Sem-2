#include <stdio.h>
#include <stdlib.h>

char list[1000];
int size;

void createlist() {
    printf("Enter No. of movies\n");
    scanf("%d", &size);
    if (size > 1000) {
        printf("This is not allowed \n");
        size = 0;
    } else {
        printf("Enter Movies \n");
        // Skip newline character left in input buffer
        getchar();
        for (int i = 0; i < size; i++) {
            scanf("%c", &list[i]);
        }
    }
}

void insertmovie() {
    if (size == 1000) {
        printf("List is full\n");
    }
    char element;
    int position;
    printf("Enter Movie to insert: ");
    // Skip newline character left in input buffer
    getchar();
    scanf("%c", &element);
    printf("Enter the position to insert Movie: ");
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Invalid Position\n");
    }
    for (int i = size; i >= position; i--) {
        list[i + 1] = list[i];
    }
    list[position] = element;
    size++;
}

void deletemovie() {
    if (size == 0) {
        printf("list is empty\n");
    }
    int position;
    printf("Enter Movie to delete: ");
    // Skip newline character left in input buffer
    scanf("%d", &position);
    if (position < 0 || position >= size) {
        printf("Invalid position\n");
    }
    for (int i = position; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
    printf("Movie Deleted Successfully\n");
}

void searchmovie() {
    if (size == 0) {
        printf("Movies list is empty\n");
        return;
    }
    char element;
    int found = 0;
    printf("Enter Element to search: ");
    // Skip newline character left in input buffer
    getchar();
    scanf("%c", &element);
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            printf("Movie Found in the list\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Movie is not in the list\n");
    }
}

void displaylist() {
    if (size == 0) {
        printf("List is empty\n");
    } else {
        printf("Movies in the given list are:\n");
        for (int i = 0; i < size; i++) {
            printf("%c\t", list[i]);
        }
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1. Create Movie list\n");
        printf("2. Insert movie\n");
        printf("3. Display Movie List\n");
        printf("4. Delete Movie from list\n");
        printf("5. Search Movie in the List\n");
        printf("6. Exit Movie list\n");

        int choice;
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createlist();
                break;
            case 2:
                insertmovie();
                break;
            case 3:
                displaylist();
                break;
            case 4:
                deletemovie();
                break;
            case 5:
                searchmovie();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
