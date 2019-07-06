#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void enqueue(int data, node *&front, node *&rear)
{
	node *n = new node;
		n->data=data;
		n->next= NULL;
		//cout<<"Node Created "<<endl;
	if(front==NULL && rear ==NULL)
	{
		cout<<"Entering "<<n->data<<endl;
		front = rear = n;
	}
	else
	{
		rear->next=n;
		rear = n;
	}
}

int dequeue(node *&front, node *&rear)
{
	if(front==rear && rear==NULL)
	{
		cout<<"Queue is empty";
		return -1;
	}
	else
	{
		int d = front->data;
		cout<<"Removing "<<d<<endl;
		node *temp = front->next;
		front->next=NULL;
		front = temp;
		if(front==NULL)
		{
			rear = NULL;
		}
		return d;
	}
}

void display(node *front, node *rear)
{
	node *temp = front;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	node *front=NULL, *rear=NULL;
	
	enqueue(1, front, rear);
	enqueue(2, front, rear);
	enqueue(3, front, rear);
	display(front, rear);
	cout<<dequeue(front, rear)<<endl;
	enqueue(4, front, rear);
	enqueue(5, front, rear);
	cout<<dequeue(front, rear)<<endl;
	cout<<dequeue(front, rear)<<endl;
	cout<<dequeue(front, rear)<<endl;
	cout<<dequeue(front, rear)<<endl;
	
    return 0;	
}























































































































