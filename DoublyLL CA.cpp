#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};
void insertE(struct Node** head, int data){
	struct Node * newNode=new Node; // node that we waant to inssert
	struct Node * last=*head; // copy of head poiinnter
	newNode->data=data; // default
	newNode->next=NULL; //
	
	if(*head==NULL){
		newNode->prev=NULL;
		*head=newNode;
		return;
	}
	
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=newNode;
	newNode->prev=last;

}
void insertF(struct Node** head, int data)
{
	struct Node * newNode=new Node;
	newNode->data=data;
	newNode->next=(*head);
	newNode->prev=NULL;
	
	if((*head)!=NULL){
		(*head)->prev=newNode;
	}
	(*head)=newNode;
}
void display(struct Node* node){
	//struct Node* last;
	while(node!=NULL){
		cout<<node->prev<<"<<="<<node->data<<"=>"<<node->next<<endl;
		//last=node;
		node=node->next;
		
	}
}
int main() {
	// your code goes here
	struct Node * head=NULL;
	insertF(&head,10);
	insertF(&head,20);
	insertF(&head,30);
	insertF(&head,40);
	insertE(&head,50);
	display(head);
	return 0;
}
