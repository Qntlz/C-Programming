/*
    You are given three towers (source, destination, and helper) and a number of disks. 
    Initially, all the disks are in the source tower in decreasing order of size, and 
    the other two towers are empty. The goal is to move all the disks to the destination tower, 
    following these rules:

    1. Only one disk can be moved at a time.
    2. A larger disk cannot be placed on top of a smaller disk. 
    
    Write a recursive function to solve the Tower of Hanoi problem.
*/

#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char helper) {
    if (n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, helper, destination);
    printf("Move disk %d from tower %c to tower %c\n", n, source, destination);
    tower_of_hanoi(n - 1, helper, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}