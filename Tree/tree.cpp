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

node* create(){
	int d;
	cin>>d;
	if(d==-1) return NULL;
	node* root=new node(d);
	root->left=create();
	root->right=create();
	return root;
}

void preOrder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	node* root=create();
	preOrder(root);
	return 0;
}
