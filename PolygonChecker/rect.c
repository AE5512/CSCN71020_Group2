#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rect.h"

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
