/*
    Identify what Quandrant does the point(x,y) belong

    Make a function identifyPoint which returns the following:
    Return type | Value
    0             Origin
    1             Quadrant 1
    2             Q2
    3             Q3                        
    4             Q4
    5             X-Axis
    6             Y - Axis

*/

typedef struct
{
    int x,y;
} Coordinates;

Coordinates addPoint(int,int);
int identifyPoint(Coordinates);

#include <stdio.h>

int main()
{
    int x,y;
    printf("Enter X: ");
    scanf("%d", &x);
    printf("Enter Y: ");
    scanf("%d", &y);

    Coordinates result = addPoint(x,y);
    switch (identifyPoint(result))
    {
    case 0:
        printf("(%d,%d) is in the origin",x,y);
        break;
    case 1:
        printf("(%d,%d) is in the Q1",x,y);
        break;
    case 2:
        printf("(%d,%d) is in the Q2",x,y);
        break;
    case 3:
        printf("(%d,%d) is in the Q3",x,y);
        break;
    case 4:
        printf("(%d,%d) is in the Q4",x,y);
        break;
    case 5:
        printf("(%d,%d) is in the X-Axis",x,y);
        break;
    case 6:
        printf("(%d,%d) is in the Y-Axis",x,y);
        break;
    default:
        break;
    }
    return 0;
}

Coordinates addPoint(int x,int y)
{
    Coordinates temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int identifyPoint(Coordinates p)
{
    if(p.x == 0 && p.y == 0) return 0;
    else if(p.x > 0 && p.y > 0) return 1;
    else if(p.x < 0 && p.y > 0) return 2;
    else if(p.x > 0 && p.y > 0) return 3;
    else if(p.x != 0 && p.y == 0) return 5;
    else if(p.x == 0 && p.y != 0) return 6;
    else return 4;
}
