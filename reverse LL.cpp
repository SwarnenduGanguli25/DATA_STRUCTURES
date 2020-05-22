#include <iostream>
using namespace std;

struct Node{
		int num;
		Node *next;
};
struct Node *head=NULL;
	
void insertNode(int n){
		
		struct Node *newNode=new Node;
		newNode->num=n;
		newNode->next = NULL;
		if(head == NULL) {
			head=newNode;
			return;
		}		
		struct Node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		
	}
	
void reverse()
{
	struct Node* temp=head;
	struct Node* prev=NULL;
	struct Node* r;
	while(temp!=NULL)
	{
		r=temp->next;
		temp->next=prev;
		prev=temp;
		temp=r;
	}
	head=prev;
}

	
	
void display(){
		struct Node *temp=head;
		while(temp!=NULL){
			cout <<temp->num<<endl;
			temp=temp->next;
		}
	}
	
	
	
int main(){
	insertNode(10);
	insertNode(12);
	insertNode(14);
	insertNode(16);
	display();
	cout<<endl;
	reverse();
	display();
	return 0;
}
