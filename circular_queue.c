DSA Assignment
Name: Rihan khan
Student ID: BC2025503

Q2. Circular Queue Using Array

1. Definition of Circular Queue
A Circular Queue is a linear data structure that follows the FIFO (First In, First Out) principle. It is implemented using an array in which the last position is connected to the first position, forming a circular structure.
In a circular queue, when the REAR reaches the last index, it can move back to the first index if space is available.
Main Operations

ENQUEUE(x): Adds an element x at the rear of the queue.
DEQUEUE(): Removes an element from the front of the queue.
FRONT(): Returns the element present at the front without removing it.
DISPLAY(): Displays all elements currently present in the queue.

2. Full and Empty Conditions

Queue Empty
The queue is empty when there is no element available for deletion.
Condition:
FRONT = -1
Queue Full
The queue is full when the next position of REAR is equal to FRONT.
Condition:
(REAR + 1) % SIZE == FRONT
This condition helps the circular queue correctly distinguish between full and empty states.

3. How Circular Queue Works
A circular queue uses two pointers:
FRONT: Points to the first element.
REAR: Points to the last element.
When REAR reaches the last position of the array, it can return to position 0. Similarly, FRONT also moves circularly.
Learn more

5. Why Circular Queue Provides Better Memory Utilization?
In a linear queue, when elements are deleted from the front, the empty positions at the beginning may remain unused.
For example:
Before deletion:
[10] [20] [30] [40] [50]
After deleting 10 and 20:
[ ] [ ] [30] [40] [50]
Although two positions are empty, REAR has reached the last position. Therefore, a linear queue may show Overflow when trying to insert another element.
A circular queue solves this problem by allowing REAR to move back to the beginning and use the empty positions.
Therefore, a circular queue provides better utilization of available memory.

6. Time Complexity
Operation
Time Complexity
ENQUEUE
O(1)
DEQUEUE
O(1)
FRONT
O(1)
DISPLAY
O(n)

Explanation

ENQUEUE: Inserts an element at REAR, so it takes O(1) time.
DEQUEUE: Removes an element from FRONT, so it takes O(1) time.
FRONT: Directly accesses the front element, so it takes O(1) time.
DISPLAY: Visits all queue elements, so it takes O(n) time.

7. Space Complexity
The circular queue is implemented using an array of fixed size.
Therefore, the space complexity is O(n), where n is the size/capacity of the queue.
For example, an array of size 5 can store a maximum of 5 elements.

8. Problem in Linear Queue When REAR Reaches Last Index
When REAR reaches the last index of a linear queue, insertion may not be possible even if there are empty positions at the beginning.
This problem is called False Overflow.
For example:

[ ] [ ] [30] [40] [50]
The first two positions are empty, but because REAR is already at the last position, a new element cannot normally be inserted without shifting elements.
Circular Queue Solution

A circular queue allows REAR to wrap around and use those empty positions.
Thus, it avoids unnecessary wastage of memory.

                   //code//
    
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// ENQUEUE operation
void ENQUEUE(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
    printf("%d inserted into queue.\n", x);
}

// DEQUEUE operation
void DEQUEUE()
{
    if (front == -1)
    {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// FRONT operation
void FRONT()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element = %d\n", queue[front]);
    }
}

// DISPLAY operation
void DISPLAY()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice, x;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. FRONT\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                ENQUEUE(x);
                break;

            case 2:
                DEQUEUE();
                break;

            case 3:
                FRONT();
                break;

            case 4:
                DISPLAY();
                break;

            case 5:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
