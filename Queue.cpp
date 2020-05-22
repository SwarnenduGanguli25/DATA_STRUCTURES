#include<iostream>

using namespace std;

struct Queue{
	int num;
	struct Queue* next;
};
struct Queue *front=NULL;

void enqueue(int n){
	struct Queue *newNode=new Queue;
	newNode->num=n;
	if(front==NULL){
		newNode->next=NULL;
		front=newNode;
		return;
	}
	else{
		struct Queue *rear=front;
		while(rear->next!=NULL){
			rear=rear->next;
		}
		newNode->next=NULL;
		rear->next=newNode;
	}
}


void dequeue(){
	if(front==NULL){
		cout<<"list is empty"<<endl;
	}
	else{
		cout<<front->num <<" is deleted"<<endl;
		front=front->next;
	}
}


void display(){
	struct Queue *rear=front;
	while(rear!=NULL){
		cout<<rear->num<<endl;
		rear=rear->next;
	}
}

int main(){
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	display();
	dequeue();
	display();
	return 0;
}
