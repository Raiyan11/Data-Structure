#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

using namespace std;

#define max 5

int stack[max], top = -1;

void push();
int pop();

void pip();
void peek();
bool isFull();
bool isEmpty();
int getSize();

int main()
{
    int choice;
    for(;;)
    {
    cout << endl << " 1. Push" << endl;
    cout << " 2. Pop" << endl;
    cout << " 3. Pip" << endl;
    cout << " 4. Peek" << endl;
    cout << " 5. GetSize" << endl;
    cout << " 6. Exit" << endl;
    cout << " Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            pip();
            break;
        case 4:
            peek();
            break;
        case 5:
            cout << endl << " Stack Size is: " << getSize() << endl;
            break;
        case 6:
            exit(1);

        default:
            cout << endl << " Invalid Choice! Please enter 1-6" << endl;
    }
    }

    getch();
}

void push()
{
    int item;
    if(isFull())
    {
        cout << endl << " Stack is full." << endl;
    }
    else
    {
        cout << endl << " Enter stack item: ";
        cin >> item;
        top++;

        stack[top] = item;
        cout << endl << stack[top] << " has pushed" << endl;
    }
}

int pop()
{
    int item;
    if(isEmpty())
    {
        cout << endl << " Stack is empty." << endl;

    }
    else
    {
        item = stack[top];
        top--;
        cout << endl << item << " has popped" << endl;
        return item;
    }
}

void pip()
{
    int i;
    if(isEmpty())
    {
        cout << " Stack is empty." << endl;
    }
    else
    {
       for(i=top;i>=0;i--)
        cout << endl << stack[i] << endl;
    }
}

bool isFull()
{
    if(top==max-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void peek()
{
    cout << endl << stack[top] << endl;
}
int getSize()
{
    return top+1;
}
