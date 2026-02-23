#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int val){
		data = val;
		next = NULL;
	}
};
void insertAtHead(Node* &head , int val){
	Node* temp = new Node(val);
	temp->next = head;
	head = temp;
}
void display(Node* &head){
	Node* temp = head;
	while(temp !=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
void insertAtTail(Node* &tail,int val){
	Node* temp = new Node(val);
	tail->next = temp;
	tail = temp;
}
void insertAtMiddle(Node* head ,Node* tail,int val,int position){
	if(position == 1){
		insertAtHead(head , val);
		return;
	}
	Node* temp = head;
	int count = 1;
	while(count!= position - 1){
		temp = temp->next;
		count++;
	}
	Node* nodeToInsert = new Node(val);
	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
	if(nodeToInsert->next == NULL){
		insertAtTail(tail,val);
		return;
	}
}
int sumOfElements(Node* head){
	int sum =0;
	while(head !=NULL){
		sum+= head->data;
		head = head->next;
	}
	return sum;
}
void findingOddEven(Node* head){
	cout << "Even numbers are: ";
	Node* temp = head;
	while(temp != NULL){
		if(temp->data % 2 == 0){
			cout << temp->data << " ";
		}
		temp = temp->next;
	}
	cout << endl;
	
	cout << "Odd numbers are: ";
	temp = head;
	while(temp != NULL){
		if(temp->data % 2 != 0){
			cout << temp->data << " ";
		}
		temp = temp->next;
	}
	cout << endl;
}
Node* reverseList(Node* head){
	Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next; // store next node
        curr->next = prev; // reverse the current node's pointer
        prev = curr;       // move pointers one position ahead
        curr = next;
    }
    return prev;
    
}
int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	display(head);
	insertAtHead(head , 20);
	display(head);
	insertAtTail(tail,30);
	display(head);
	insertAtMiddle(head ,tail,40 , 3); 
	display(head);
	int sum1 = sumOfElements(head);
	cout<<"Sum of elements: "<<sum1<<endl;
	insertAtHead(head,31);
	display(head);
	findingOddEven(head);
	head=reverseList(head);
	display(head);
	return 0;
}
