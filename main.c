#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

// Function to initialize canvas with _
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

int main() {

    initializeCanvas(); // Fill canvas with _

    // Draw rectangle
    drawRectangle(2, 5, 4, 8);

    // Display canvas
    displayCanvas();

    return 0;
}