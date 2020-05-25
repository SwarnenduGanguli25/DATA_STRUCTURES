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

void zigZagOrder(node* root){
	if(root==NULL) return;
	stack<node*>currLevel,nextLevel;
	bool leftToRight=true;
	currLevel.push(root);
	while(!currLevel.empty() or !nextLevel.empty()){
		node* top=currLevel.top();
		cout<<top->data<<" ";
		currLevel.pop();
		if(leftToRight==true){
			if(top->left)
				nextLevel.push(top->left);
			if(top->right)
				nextLevel.push(top->right);
		}
		else{
			if(top->right)
				nextLevel.push(top->right);
			if(top->left)
				nextLevel.push(top->left);
		}
		if(currLevel.empty()==true){
		leftToRight=!leftToRight;
		swap(currLevel,nextLevel);
		cout<<endl;
		}
	}
}

int main(){
	node* root=create();        //1 2 6 -1 7 -1 -1 -1 3 4 9 -1 -1 -1 5 -1 8 -1 -1
	preOrder(root);
	cout<<endl;
	cout<<"The zigzag order traversal:\n";
	zigZagOrder(root);
	return 0;
}
