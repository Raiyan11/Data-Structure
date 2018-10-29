#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int a;
    double d;
    char ch;
    struct node *link;
}*head;

void insertLast(int value,char cha,double data)
{
    struct node *temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->a=value;
    newNode->ch=cha;
    newNode->d=data;
    newNode->link=NULL;
    temp->link=newNode;
}
void traverse(struct node *head)
{
    struct node *temp=head->link;
    cout<<endl<<" List:  ";
    while(temp!=NULL)
    {
        cout<<temp->a<<","<<temp->ch<<","<<temp->d<<"--->";
        temp=temp->link;
    }
    cout<<endl<<endl;
}

int nodeCounter(struct node *head)
{
    struct node *temp=head->link;
    int counter=0;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->link;
    }
    return counter;
}


void deleteLast()
{
    struct node *temp=head;
    struct node *temp2;
    while((temp->link)->link!=NULL) temp=temp->link;
    temp2=temp->link;
    temp->link=NULL;
    free((temp2));
}


void findingNode(struct node *head,int value)
{
    int sum=0;
    int counter=0;//this will count the node number that fills the sum requirement
    struct node *temp=head->link;
    while(temp!=NULL)
    {
        sum=sum+temp->a;
        counter++;
        if(sum>value)break;
        temp=temp->link;
    }
    //cout<<"SUM: "<<sum<<endl;
    int total=nodeCounter(head);
    for(int i=counter+1;i<=total;i++)deleteLast();
}

void labTask6()
{
    int value;
    cout<< endl <<" Enter a value: ";
    cin>>value;
    findingNode(head,value);
    traverse(head);
}


int main()
{
    head=(struct node *)malloc(sizeof(struct node));
    head->link=NULL;
    insertLast(2,'s',2.3);
    insertLast(4,'m',9.0);
    insertLast(5,'t',3.4);
    insertLast(8,'h',3);
    insertLast(3,'j',6.7);
    traverse(head);
    labTask6();//this function for task 6
    //traverse(head);
    return 0;
}

Output:
List:  2,s,2.3 - - 4, m, 9.0 - - 5, t, 3.4 - - 8, h, 3 - - 3, j, 6.7
Input: 10
List: 2,s,2.3 - - 4, m, 9.0 - - 5, t, 3.4 
