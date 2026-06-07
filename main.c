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

int main() {

    initializeCanvas(); // Fill canvas with _

    // Draw rectangle
    drawRectangle(2, 5, 4, 8);

    // Draw line
    drawLine(10, 5, 10, 20);

    // Display canvas
    displayCanvas();

    return 0;
}