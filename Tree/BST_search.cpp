#include<bits/stdc++.h>

using namespace std;

class node{
	public:
		node* left;
		int data;
		node* right;
		node(int d){
			data=d;
			left=right=NULL;
		}
};

node* create(node* root,int d){
	if(root==NULL) return new node(d);
	if(d<=root->data)
		root->left=create(root->left,d);
	else
		root->right=create(root->right,d);
		
	return root;
}

void search(node* root,int val){
	if(root==NULL){
		cout<<"Not found"<<endl;
		return;
	}
	if(root->data==val){
		cout<<"Found"<<endl;
		return;
	}
	if(root->data>val) search(root->left,val);
	if(root->data<val) search(root->right,val);
}

void preOrder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	node* root=NULL;
	root=create(root,23);
	create(root,14);
	create(root,40);
	create(root,30);
	create(root,7);
	create(root,17);
	preOrder(root);
	cout<<endl;
	search(root,100);
	search(root,17);
	return 0;
}
