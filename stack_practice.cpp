#include<iostream>

using namespace std;

struct Stack{
	int top;
	int cap;
	int *arr;
};


struct Stack* create(int n){
	struct Stack* st = new Stack;
	st->top=-1;
	st->cap=n;
	st->arr=new int[st->cap];
	return st;
}


void push(struct Stack* st,int n){
	st->arr[++st->top]=n;
	cout<<"Element inserted"<<endl;
}

void pop(struct Stack* st){
	int d=st->arr[st->top];
	st->top--;
	cout<<"The popped element is "<<d<<endl;
}


bool isEmpty(struct Stack* st){
	if(st->top==-1){
		return true;
	}
	else{
		return false;
	}
}

void display(struct Stack* st){
	for(int i=0;i<=st->top;i++){
		cout<<st->arr[i]<<endl;
	}
}


int main(){
	struct Stack* st=NULL;
	int n,d,f,a,b=1;
	cout<<"Enter the stack size you want"<<endl;
	cin>>n;
	st=create(n);
	cout<<"Stack has been created"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"Insert element"<<endl;
		cin>>d;
		push(st,d);
	}
	cout<<"Stack is now filled"<<endl;
	cout<<"Do you want to pop?(if yes press 1 or else 0)"<<endl;
	cin>>f;
	if(f==1){
		cout<<"How many times do you want to pop "<<endl;
		cin>>a;
		if(a>st->cap){
				while(b<=st->cap){
					pop(st);
					b++;
				}
				cout<<"Stack is empty no more can be popped"<<endl;
			}
		else{
		for(b=1;b<=a;b++){	
		pop(st);
		}
		display(st);
	}
}
	else{
		display(st);
	}
	
	return 0;
}






