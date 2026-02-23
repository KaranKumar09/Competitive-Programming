#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void insertAtHead(node* &head,int d){
	node* temp=new node(d);
	temp->next=head;
	head=temp;
}
void insertAtTail(node* &tail,int d){
	node* temp=new node(d);
	tail->next=temp;
	temp=tail;
}
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node* node1=new node(10);
//	cout<<node1->data<<endl;
//	cout<<node1->next<<endl;
	node* head=node1;
	node* tail=node1;
	display(head);
//	insertAtHead(head,12);
//	display(head);
	insertAtTail(tail,14);
	display(head);
	
}

