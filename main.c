#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Function to initialize canvas
void initializeCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Function to display canvas
void displayCanvas() {
    printf("\nCanvas:\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

// Function to draw rectangle
void drawRectangle(int row, int col, int height, int width) {

    for(int i = row; i < row + height && i < ROWS; i++) {

        for(int j = col; j < col + width && j < COLS; j++) {

            canvas[i][j] = '*';
        }
    }
}

// Function to draw line
void drawLine(int row1, int col1, int row2, int col2) {

    // Horizontal line
    if(row1 == row2) {

        for(int j = col1; j <= col2; j++) {
            canvas[row1][j] = '*';
        }
    }

    // Vertical line
    else if(col1 == col2) {

        for(int i = row1; i <= row2; i++) {
            canvas[i][col1] = '*';
        }
    }

    else {
        printf("Only horizontal and vertical lines allowed!\n");
    }
}

// Function to draw triangle
void drawTriangle(int row, int col, int height) {

    for(int i = 0; i < height; i++) {

        for(int j = 0; j <= i; j++) {

            canvas[row + i][col + j] = '*';
        }
    }
}

// Function to draw circle
void drawCircle(int centerRow, int centerCol, int radius) {

    for(int i = 0; i < ROWS; i++) {

        for(int j = 0; j < COLS; j++) {

            int dx = i - centerRow;
            int dy = j - centerCol;

            if(dx * dx + dy * dy <= radius * radius) {

                canvas[i][j] = '*';
            }
        }
    }
}

// Function to delete object
void deleteObject(int row, int col, int height, int width) {

    for(int i = row; i < row + height && i < ROWS; i++) {

        for(int j = col; j < col + width && j < COLS; j++) {

            canvas[i][j] = '_';
        }
    }
}

int main() {

    int choice;

    initializeCanvas();

    do {

        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Add Rectangle\n");
        printf("2. Add Line\n");
        printf("3. Add Triangle\n");
        printf("4. Add Circle\n");
        printf("5. Delete Object\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                drawRectangle(2, 5, 4, 8);
                printf("Rectangle Added!\n");
                break;

            case 2:
                drawLine(10, 5, 10, 20);
                printf("Line Added!\n");
                break;

            case 3:
                drawTriangle(12, 25, 5);
                printf("Triangle Added!\n");
                break;

            case 4:
                drawCircle(8, 30, 3);
                printf("Circle Added!\n");
                break;

            case 5:
                deleteObject(2, 5, 2, 4);
                printf("Object Deleted!\n");
                break;

            case 6:
                displayCanvas();
                break;

            case 7:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 7);

    return 0;
}