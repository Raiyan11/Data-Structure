#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;


struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);
void search_by_data();
void node_count();
int totalsum();
void displayDlListRev();


int main()
{
    int n, data, choice=1, totalNode;

    head = NULL;
    last = NULL;

    while(choice != 0)
    {
        cout << " ============================================" << endl;
        cout << " DOUBLY LINKED LIST MAIN MANU" << endl;
        cout << " ============================================" << endl;
        cout << " 1. Create List" << endl;
        cout << " 2. Insert First" << endl;
        cout << " 3. Insert Last" << endl;
        cout << " 4. Insert N" << endl;
        cout << " 5. Delete First" << endl;
        cout << " 6. Delete Last" <<endl;
        cout << " 7. Delete N" << endl;
        cout << " 8  Search by data" << endl;
        cout << " 9. Count The Number Of Nodes" << endl;
        cout << " 10. SUM " << endl;
        cout << " 11. Reverse Display List" << endl;
        cout << " 12. Display List" << endl;
        cout << " 0. Exit" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " Enter your choice : ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << " Enter the total number of nodes in list: ";
                cin >> n;

                createList(n);
                break;
            case 2:
                cout << " Enter data of first node : ";
                cin >> data;

                insertAtBeginning(data);
                break;
            case 3:
                cout << " Enter data of last node : ";
                cin >> data;

                insertAtEnd(data);
                break;
            case 4:
                cout << " Enter the position where you want to insert new node: ";
                cin >> n;
                cout << " Enter data of " << n << " node : ";
                cin >> data;

                insertAtN(data, n);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << " Enter the node position which you want to delete: ";
                cin >> n;
                deleteFromN(n);
                break;
            case 8:
                search_by_data();
                break;
            case 9:
                node_count();
                break;
            case 10:
                    totalNode = totalsum();
                    cout << endl << " The sum is : " << totalNode << endl;
                    break;
            case 11:
                displayDlListRev();
                break;
            case 12:
                displayList();
                break;
            case 0:
                cout << " Have a good day! " << endl ;
                break;
            default:
                cout << " Error! Invalid choice. Please choose between 0-11";
        }

        cout << endl << endl << endl << endl << endl << endl;
    }

    getch();
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        cout << " Enter data for node 1: ";
        cin >> data;

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            cout << " Enter data for node " << i << ": ";
            cin >> data;

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode;
            last = newNode;
        }

        cout << endl << endl << " DOUBLY LINKED LIST CREATED SUCCESSFULLY" << endl;
    }
}

void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        cout << " List is empty." << endl;
    }
    else
    {
        temp = head;
        cout << " DATA IN THE LIST: " << endl;

        while(temp != NULL)
        {
            cout << " DATA of " << n << " node = " << temp->data << endl;

            n++;

            temp = temp->next;
        }
    }
}

void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        cout << " Error, List is Empty!" << endl;
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;

        head->prev = newNode;

        head = newNode;

        cout << endl << " NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST" << endl;
    }
}

void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        cout << " Error, List is empty!" << endl;
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        cout << endl << " NODE INSERTED SUCCESSFULLY AT THE END OF LIST" << endl;
    }
}

void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        cout << " Error, List is empty!" << endl;
    }
    else
    {
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;

            if(temp->next != NULL)
            {
                temp->next->prev = newNode;
            }

            temp->next = newNode;

            cout << endl <<  " NODE INSERTED SUCCESSFULLY AT " << position << " POSITION" <<endl;
        }
        else
        {
            cout << " Error, Invalid position" << endl;
        }
    }
}
void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        cout << " Unable to delete. List is empty." << endl;
    }
    else
    {
        toDelete = head;

        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        free(toDelete);
        cout << endl <<  " SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST." << endl;
    }
}

void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        cout << " Unable to delete. List is empty." << endl;
    }
    else
    {
        toDelete = last;

        last = last->prev;

        if (last != NULL)
            last->next = NULL;

        free(toDelete);
        cout << endl << " SUCCESSFULLY DELETED NODE FROM END OF THE LIST." << endl;
    }
}

void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);

        cout << endl << " SUCCESSFULLY DELETED NODE FROM " << position << " POSITION.";
    }
    else
    {
        cout << " Invalid position!" << endl;
    }
}

void search_by_data()
{
    int n, count = 0;
    last = head;

    if (last == NULL)
    {
        cout << endl << " Error : List empty to search for data";
        return;
    }
    cout << endl << " Enter data to search : ";
    cin >> n;

    while (last != NULL)
    {
        if (last->data == n)
        {
            cout << endl << " Data found in " << count + 1 << " position" << endl;
            return;
        }
        else
             last = last->next;
            count++;
    }
    cout << endl << " Error : " << n << " not found in list";
}

void node_count()
{
    struct node *q = head;

    int cnt = 0;

    while (q != NULL)

    {
        q = q->next;

        cnt++;

    }
    cout << endl << " Number of nodes are: "<< cnt << endl;
}
int totalsum()
{
    int sum = 0;
    struct node *tmp;
    tmp = head;
    while(tmp)
    {
        sum += tmp->data;
        tmp = tmp->next;
    }
    return sum;
}
void displayDlListRev()
{
    struct node * tmp;
    int n = 0;

    if(last == NULL)
    {
        cout <<" No data found in the List yet.";
    }
    else
    {
        tmp = last;
        cout << endl << " Data in reverse order are: " <<endl;
        while(tmp != NULL)
        {
            cout << " Data in node " << n+1 << " :" << tmp->data << endl;
            n++;
            tmp = tmp->prev; // current pointer set with previous node
        }
    }
}
