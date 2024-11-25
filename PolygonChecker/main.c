#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function prototypes for both operations
void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
int isValidTriangle(int a, int b, int c);
double distanceSquared(int x1, int y1, int x2, int y2);
int isRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void checkTriangle();
void checkRectangle();

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            checkTriangle();  // Check if the sides form a valid triangle
            break;

        case 2:
            checkRectangle();  // Check if the points form a rectangle
            break;

        case 0:
            continueProgram = false;  // Exit the program
            break;

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
int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;
    printf_s("Enter number: ");
    scanf_s("%d", &shapeChoice);

    return shapeChoice;
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

// Function to calculate the square of the distance between two points
double distanceSquared(int x1, int y1, int x2, int y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

// Function to check if four points form a rectangle
int isRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double side1 = distanceSquared(x1, y1, x2, y2); // Side 1
    double side2 = distanceSquared(x2, y2, x3, y3); // Side 2
    double side3 = distanceSquared(x3, y3, x4, y4); // Side 3
    double side4 = distanceSquared(x4, y4, x1, y1); // Side 4
    double diagonal1 = distanceSquared(x1, y1, x3, y3); // Diagonal 1
    double diagonal2 = distanceSquared(x2, y2, x4, y4); // Diagonal 2

    return (side1 == side3 && side2 == side4 && diagonal1 == diagonal2);
}

// Function to check if the sides form a valid triangle
void checkTriangle() {
    int triangleSides[3] = { 0, 0, 0 };
    int* triangleSidesPtr = getTriangleSides(triangleSides);

    if (isValidTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
        printf_s("The sides %d, %d, and %d form a valid triangle.\n", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

        // Now analyzing the type of triangle (simplified here as an example)
        if (triangleSidesPtr[0] == triangleSidesPtr[1] && triangleSidesPtr[1] == triangleSidesPtr[2]) {
            printf_s("This is an Equilateral triangle.\n");
        }
        else if (triangleSidesPtr[0] == triangleSidesPtr[1] || triangleSidesPtr[1] == triangleSidesPtr[2] || triangleSidesPtr[0] == triangleSidesPtr[2]) {
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

// Function to check if the four points form a rectangle
void checkRectangle() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    printf("Enter the coordinates of the four points:\n");
    printf("Point 1 (x1, y1): ");
    scanf_s("%d %d", &x1, &y1);
    printf("Point 2 (x2, y2): ");
    scanf_s("%d %d", &x2, &y2);
    printf("Point 3 (x3, y3): ");
    scanf_s("%d %d", &x3, &y3);
    printf("Point 4 (x4, y4): ");
    scanf_s("%d %d", &x4, &y4);

    if (isRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
        printf("The points form a rectangle.\n");

        // Calculating the perimeter and area
        double side1 = sqrt(distanceSquared(x1, y1, x2, y2));
        double side2 = sqrt(distanceSquared(x2, y2, x3, y3));
        double perimeter = 2 * (side1 + side2);
        double area = side1 * side2;

        printf("Perimeter: %.2f\n", perimeter);
        printf("Area: %.2f\n", area);
    }
    else {
        printf("The points do not form a rectangle.\n");
    }
}
