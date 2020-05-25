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

int height(node* root){
	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

int diameter(node* root){
	if(root==NULL) return 0;
	int h1=height(root->left);
	int h2=height(root->right);
	int op=h1+h2;
	int diamL=diameter(root->left);
	int diamR=diameter(root->right);
	if(op>=diamL && op>=diamL) return op;
	if(diamL>=op && diamL>=diamR) return diamL;
	if(diamR>=op && diamR>=diamL) return diamR;
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
	cout<<endl;
	cout<<"The height of tree is "<<height(root)<<endl;
	cout<<"The diameter of tree is "<<diameter(root)<<endl;
	return 0;
}
