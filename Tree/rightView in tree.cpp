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

void rightView(node* root,int level,int& maxLevel){
	if(root==NULL) return;
	if(level>maxLevel){
		cout<<root->data<<" ";
		maxLevel=level;
	}
	rightView(root->right,level+1,maxLevel);
	rightView(root->left,level+1,maxLevel);
}

int main(){
	node* root=create();              //1 2 4 7 8 -1 -1 -1 -1 -1 3 -1 5 6 -1 -1 -1
	preOrder(root);
	cout<<endl;
	int maxLevel=0;
	cout<<"The right view of tree:\n";
	rightView(root,1,maxLevel);
	return 0;
}
