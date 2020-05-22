#include <iostream>
using namespace std;

	struct Node{
		int num;
		Node *next;
	};
	
	struct Node *head=NULL;
	// delete item from end
	void deleteItemEnd(){
		if (head==NULL){
			cout << "List is empty";
		}
		
		if(head->next==NULL){
			cout<<"only one element";
		}
		// 1 -> 3 -> 5 -> 7 -> NILL
		Node *secLast = head;
		while(secLast->next->next!=NULL){
			secLast=secLast->next;
		}
		secLast->next=NULL;
		
		
	}
		
		
	
		
		
	// delete item from start
	void deleteItem(){
		if (head==NULL){
			cout << "List is empty";
		}
		cout << head->num << " is deleted";
		head=head->next;
		}
	
	// Insert Node at start
	void insertNode(int n){
		
		struct Node *newNode=new Node;
		newNode->num=n;
		newNode->next=head;
		head=newNode;
		
	}
		// Insert Node at end
	void insertNodeEnd(int n){
		
		struct Node *newNode=new Node;
		newNode->num=n;
		newNode->next = NULL;
		//if there are no elements present in the linked list
		if(head == NULL) {
			head=newNode;
			return;
		}		
		//If there are elments present already
		struct Node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
		
	}
	
	void display(){
		struct Node *temp=head;
		while(temp!=NULL){
			cout <<temp->num<<endl;
			temp=temp->next;
		}
	}
	
int main() {
	// your code goes here
	insertNode(10);
	insertNode(12);
	insertNode(14);
	insertNode(16);
	insertNodeEnd(6);
	display();
	deleteItem();
	display();
	
	

	
	
	
	return 0;
}
