#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

// Function to check if the three sides can form a valid triangle
int isValidTriangle(int a, int b, int c) {
    // Check the triangle inequality theorem
    if (a + b > c && a + c > b && b + c > a) {
        return 1;  // Valid triangle
    }
    else {
        return 0;  // Invalid triangle
    }
}

int main() {

    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice)
        {
        case 1:
            printf_s("Triangle selected.\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);

            // Check if the entered sides form a valid triangle
            if (isValidTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2])) {
                printf_s("The sides %d, %d, and %d form a valid triangle.\n", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
                // Now analyze the type of triangle
                char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
                printf_s("%s\n", result);
            }
            else {
                printf_s("The sides %d, %d, and %d do not form a valid triangle.\n", triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            }
            break;

        case 0:
            continueProgram = false;
            break;

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number: ");
    scanf_s("%1o", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: ");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%d", &triangleSides[i]);
    }
    return triangleSides;
}
