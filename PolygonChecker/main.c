#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "rect.h"


// Function prototypes for both operations
void printWelcome();
char* printShapeMenu(char* input);
int* getTriangleSides(int* triangleSides);
int isValidTriangle(int a, int b, int c);
void checkTriangle();

int main() {

    while (true) {
        printWelcome();
        char shapeChoice[64] = {0};
        printShapeMenu(shapeChoice);

        switch (shapeChoice[0]) {
        case '1':
            checkTriangle();  // Check if the sides form a valid triangle
            break;

        case '2':
            checkRectangle();  // Check if the points form a rectangle
            break;

        case '0': // exit the program when 0 is input
            exit(0);

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

// Function to print the welcome message
void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

// Function to print the menu for shape selection
char* printShapeMenu(char* input) {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    printf_s("Enter number: ");
    scanf_s("%64s", input, 64);

    return input;
}

// Function to get the three sides of a triangle
int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%d", &triangleSides[i]);
    }
    return triangleSides;
}

// Function to check if the sides form a valid triangle
int isValidTriangle(int a, int b, int c) {
    if (a + b > c && a + c > b && b + c > a) {
        return 1;  // Valid triangle
    }
    return 0;  // Invalid triangle
}

// Function to check if the sides form a valid triangle
void checkTriangle() {
    int triangleSides[3] = { 0, 0, 0 };
    int* triangleSidesPtr = getTriangleSides(triangleSides);

    if (isValidTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
        printf_s("The sides %d, %d, and %d form a valid triangle.\n", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

        // Now analyzing the type of triangle (simplified here as an example)
        if (
            triangleSidesPtr[0] == triangleSidesPtr[1] && 
            triangleSidesPtr[1] == triangleSidesPtr[2]
        ) {
            printf_s("This is an Equilateral triangle.\n");
        }
        else if (
            triangleSidesPtr[0] == triangleSidesPtr[1] || 
            triangleSidesPtr[1] == triangleSidesPtr[2] || 
            triangleSidesPtr[2] == triangleSidesPtr[0]
        ) {
            printf_s("This is an Isosceles triangle.\n");
        }
        else {
            printf_s("This is a Scalene triangle.\n");
        }
    }
    else {
        printf_s("The sides %d, %d, and %d do not form a valid triangle.\n", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
    }
}