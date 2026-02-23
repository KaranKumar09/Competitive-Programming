#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node* prev;
	node(int val){
		data=val;
		next=NULL;
		prev = NULL;
	}
};
void insertAtHead(node* &head,int d){
	node* temp=new node(d);
	temp->next=head;
	head->prev = temp;
	head = temp;
}
void insertAtTail(node* &tail,int d){
	node* temp=new node(d);
	tail->next=temp;
	tail->prev = tail;
	temp=tail;
}
void insertAtPosition(node* head, node* tail, int data, int position){
//	if(position == 0){
//		insertAtHead(head,data);
//		return;
//	}
	node* temp = head;
	int count = 0;
	while(count != position -1 ){
		temp = temp->next;
		count++;
	}
	node* toInsert = new node(data);
	toInsert->next = temp->next;
	temp->next = toInsert;
	toInsert->prev = temp;
	temp->next->prev = toInsert;
	if(toInsert->next == NULL){
		insertAtTail(tail,data);
		return;
	}
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
//	display(head);
//	insertAtHead(head,12);
//	display(head);
//	insertAtTail(tail,14);
//	display(head);
	insertAtPosition(head,tail,50,1);
	display(head);
	
}

