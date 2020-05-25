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

void levelOrder(node* root){
	if(root==NULL) return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* front=q.front();
		cout<<front->data<<" ";
		q.pop();
	if(front->left!=NULL)
		q.push(front->left);
	if(front->right!=NULL)
		q.push(front->right);
	}
}

int main(){
	node* root=create();
	preOrder(root);
	cout<<endl;
	cout<<"The level order traversal of tree:\n";
	levelOrder(root);
	return 0;
}
