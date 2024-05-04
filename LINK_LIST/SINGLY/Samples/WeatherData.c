#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Goal:
        1. This program creates a Weather link list base on the data provided.
        2. Using the created link list make another list for a specific category 
           (Hottest, Coldest, Wettest, Windiest) of your choice
        3. Sort the specific category list that you recently created.
        4. Display them in the following manner:
                1. Weather List (Original List)
                2. Specific Category List(Hottest, Coldest, Wettest, Windiest)
                3. Sorted Specific Category List
*/

typedef struct data
{
    char day[10],city[20],status[5];            
    float temp,vol;
    int speed;
}WtherLst;                                          // Structure for WeatherList

typedef struct node
{   
    WtherLst day;
    struct node *next;
} Node, *NodePtr;                                   // Structure for Node


NodePtr makeNode(char*,char*,char*,int,float,float);                // Function for making a node
NodePtr initialize();                                               // Function for initializing default values
NodePtr copyList(NodePtr);                                          // Function to create a list for assigned topic (For ours "Coldest")
void MergeSort(NodePtr*);                                            // Function that sorts a list (Ascending Order)
void display(NodePtr);                                              // Function to display the list
void split(NodePtr,NodePtr*,NodePtr*);
NodePtr sortedMerge(NodePtr,NodePtr);


int main()
{
    NodePtr base = NULL,coldList = NULL;                            // Declare base(All data) & coldList(Data that is assigned to us)
    base = initialize();                                            // Populate the base list with default values
    display(base);                                                  
    coldList = copyList(base);                                      // Populate the coldList with the specific data
    display(coldList);
    printf("\n\nSorted Coldest List:\n");
    MergeSort(&coldList);                                             // Sort the list
    display(coldList);
    
    return 0;
}

NodePtr makeNode(char *day,char *city,char *status,int speed,float temp,float vol)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    
    strcpy(np->day.day,day);
    strcpy(np->day.city,city);
    strcpy(np->day.status,status);
    np->day.speed = speed;
    np->day.temp = temp;
    np->day.vol = vol;
    np->next = NULL;
    
    return np;                                              // Return the address of the node created
}

NodePtr initialize()
{
    NodePtr top = NULL,last = NULL,np;
    
    // Iniatilize default values

    // Hottest
    if(top == NULL) 
    {
        top = makeNode("Monday","Tarlac","high",0,38.2,0);
        last = top;
    }
    np = makeNode("Tuesday","Urdaneta","high",0,38.5,0);
    last->next = np;
    last = np;
    
    np = makeNode("Wednesday","Urdaneta","high",0,38.9,0);
    last->next = np;
    last = np;
    
    np = makeNode("Thursday","Cabanatuan","high",0,38.8,0);
    last->next = np;
    last = np;
    
    np = makeNode("Friday","Urdaneta","high",0,38.4,0);
    last->next = np;
    last = np;
    
    np = makeNode("Saturday","Urdaneta","high",0,38.8,0);
    last->next = np;
    last = np;

    // Coldest

    np = makeNode("Monday","Baguio City","low",0,19.9,0);
    last->next = np;
    last = np;
    
    np = makeNode("Tuesday","Baguio City","low",0,20.7,0);
    last->next = np;
    last = np;
    
    np = makeNode("Wednesday","Baguio City","low",0,20.5,0);
    last->next = np;
    last = np;
    
    np = makeNode("Thursday","Baguio City","low",0,20.1,0);
    last->next = np;
    last = np;
    
    np = makeNode("Friday","Baguio City","low",0,19.7,0);
    last->next = np;
    last = np;
    
    np = makeNode("Saturday","Baguio City","low",0,19.4,0);
    last->next = np;
    last = np;

    // Wettest
    
    np = makeNode("Monday","Mati","",0,0,1.2);
    last->next = np;
    last = np;
    
    np = makeNode("Tuesday","Zamboanga City","",0,0,4.4);
    last->next = np;
    last = np;
    
    np = makeNode("Wednesday","Zamboanga City","",0,0,4.8);
    last->next = np;
    last = np;
    
    np = makeNode("Thursday","Baguio City","",0,0,3.8);
    last->next = np;
    last = np;
    
    np = makeNode("Friday","Mandaue City","",0,0,5.1);
    last->next = np;
    last = np;
    
    np = makeNode("Saturday","Zamboanga City","",0,0,2.9);
    last->next = np;
    last = np;
    
    // Windiest

    np = makeNode("Monday","Tuguegarao City","",31,0,0);
    last->next = np;
    last = np;
    
    np = makeNode("Tuesday","NAIA","",30,0,0);
    last->next = np;
    last = np;
    
    np = makeNode("Wednesday","Urdaneta","",32,0,0);
    last->next = np;
    last = np;
    
    np = makeNode("Thursday","Tuguegarao City","",33,0,0);
    last->next = np;
    last = np;
    
    np = makeNode("Friday","Urdaneta","",31,0,0);
    last->next = np;
    last = np;
    
    np = makeNode("Saturday","Urdaneta","",30,0,0);
    last->next = np;
    last = np;
    
    return top;                                             // Return the list created
}

void display(NodePtr top)
{
    bool onceHottest = false;
    bool onceColdest = false;
    bool onceWettest = false;
    bool onceWindiest = false;

    while (top != NULL)
    {
        if (strcmp(top->day.status, "high") == 0)           // For labelling purposes
        {
            if (!onceHottest)
            {
                printf("\n Hottest:\n\n");
                onceHottest = true;
            }
            printf("\t%s\n\t%s %s %.1f C\n\n", top->day.day, top->day.city, top->day.status, top->day.temp);
        }

        if (strcmp(top->day.status, "low") == 0)         // For labelling purposes
        {
            if (!onceColdest)
            {
                printf("\n Coldest:\n\n");
                onceColdest = true;
            }
            printf("\t%s\n\t%s %s %.1f C\n\n", top->day.day, top->day.city, top->day.status, top->day.temp);
        }

        if (top->day.vol != 0)                           // For labelling purposes
        {
            if (!onceWettest)
            {
                printf("\n Wettest:\n\n");
                onceWettest = true;
            }
            printf("\t%s\n\t%s %.1f mm\n\n", top->day.day, top->day.city, top->day.vol);
        }

        if (top->day.speed != 0)                     // For labelling purposes
        {
            if (!onceWindiest)
            {
                printf("\n Windiest:\n\n");
                onceWindiest = true;
            }
            printf("\t%s\n\t%s %d km/h\n\n", top->day.day, top->day.city, top->day.speed);
        }

        top = top->next;
    }
}

NodePtr copyList(NodePtr top)
{
    NodePtr coldList = NULL,last = NULL;
    
    while(top != NULL)
    {
        if(strcmp(top->day.status,"low") == 0)                          // Create a another list for data who have a status of "low"
        {
            NodePtr newNode = (NodePtr) malloc(sizeof(Node));
            strcpy(newNode->day.day,top->day.day);
            strcpy(newNode->day.city,top->day.city);
            strcpy(newNode->day.status,top->day.status);
            newNode->day.speed = top->day.speed;
            newNode->day.temp = top->day.temp;
            newNode->day.vol = top->day.vol;
            newNode->next = NULL;
            if(coldList == NULL) coldList = newNode;
            else last->next = newNode;
            last = newNode;
        }
        top = top->next;
    }
    
    return coldList;                                                    // Return the new list
}

void MergeSort(NodePtr *top)
{
    NodePtr a = NULL, b = NULL, curr = *top;

    //Base Case
    if((curr == NULL) || (curr->next == NULL)) return;

    //Split
    split(curr,&a,&b);

    // Recursion
    MergeSort(&a);
    MergeSort(&b);

    //Merge
    *top = sortedMerge(a,b);
} 

void split(NodePtr curr,NodePtr *front,NodePtr *back)
{
    NodePtr slow = curr, fast = curr->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    *front = curr;
    *back = slow->next;
    slow->next = NULL;
}

NodePtr sortedMerge(NodePtr a,NodePtr b)
{
    NodePtr result = NULL;

    //Base Case
    if(a == NULL) return b;
    else if(b == NULL) return a;

    if(a->day.temp <= b->day.temp)
    {
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}