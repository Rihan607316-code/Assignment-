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