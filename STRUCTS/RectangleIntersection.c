/*
    Define a structure "Rectangle" with attributes such as top-left coordinates and width/height. Write a 
    function that takes two structures "Rectangle" as parameters provided by the user and returns a new 
    rectangle that represents their intersection (if any).
*/

#include <stdio.h>

typedef struct {
    int x, y, w, h;
} Rectangle;

Rectangle intersect(Rectangle a, Rectangle b) {
    Rectangle result;
    
    // Maximum Top-Left
    result.x = a.x > b.x ? a.x : b.x;
    result.y = a.y > b.y ? a.y : b.y;
    
    // Maximum Bottom-Right
    int endX = (a.x + a.w) < (b.x + b.w) ? (a.x + a.w) : (b.x + b.w);
    int endY = (a.y + a.h) < (b.y + b.h) ? (a.y + a.h) : (b.y + b.h);
    
    // Intersection
    result.w = endX - result.x > 0 ? endX - result.x : 0;
    result.h = endY - result.y > 0 ? endY - result.y : 0;

    return result;
}

int main() {
    Rectangle rectA, rectB, intersection;

    printf("Enter the coordinates (x,y) and dimensions (w,h) of rectangle A: ");
    scanf("%d %d %d %d", &rectA.x, &rectA.y, &rectA.w, &rectA.h);

    printf("Enter the coordinates (x,y) and dimensions (w,h) of rectangle B: ");
    scanf("%d %d %d %d", &rectB.x, &rectB.y, &rectB.w, &rectB.h);

    intersection = intersect(rectA, rectB);

    if (intersection.w != 0 && intersection.h != 0)
        printf("Result: (%d,%d,%d,%d)\n", intersection.x,
               intersection.y,
               intersection.w,
               intersection.h);
    else
        printf("The rectangles do not intersect.\n");

    return 0;
}
