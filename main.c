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

// Rectangle
void drawRectangle(int row, int col, int height, int width) {

    for(int i = row; i < row + height && i < ROWS; i++) {

        for(int j = col; j < col + width && j < COLS; j++) {

            canvas[i][j] = '*';
        }
    }
}

// Line
void drawLine(int row1, int col1, int row2, int col2) {

    if(row1 == row2) {

        for(int j = col1; j <= col2; j++) {
            canvas[row1][j] = '*';
        }
    }

    else if(col1 == col2) {

        for(int i = row1; i <= row2; i++) {
            canvas[i][col1] = '*';
        }
    }
}

// Triangle
void drawTriangle(int row, int col, int height) {

    for(int i = 0; i < height; i++) {

        for(int j = 0; j <= i; j++) {

            canvas[row + i][col + j] = '*';
        }
    }
}

// Circle
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

int main() {

    initializeCanvas();

    // Rectangle
    drawRectangle(2, 5, 4, 8);

    // Line
    drawLine(10, 5, 10, 20);

    // Triangle
    drawTriangle(12, 25, 5);

    // Circle
    drawCircle(8, 30, 3);

    displayCanvas();

    return 0;
}