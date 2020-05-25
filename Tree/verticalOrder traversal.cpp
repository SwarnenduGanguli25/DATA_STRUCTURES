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


map<int,vector<int>>mp;
void verticalOrder(node* root,int level){
	if(root==NULL) return;
	
	mp[level].push_back(root->data);
	verticalOrder(root->left,level-1);
	verticalOrder(root->right,level+1);
}

int main(){
	node* root=create();        //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
	preOrder(root);
	cout<<endl;
	cout<<"The vertical order traversal:\n";
	verticalOrder(root,0);
	for(auto it:mp){
		for(int x:it.second){
			cout<<x<<" ";
		}
	}
	return 0;
}
