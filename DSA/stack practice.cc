#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int data){
		this->data = data;
		next = NULL;
	}
};
class Stack{
	private:
		node* top;
	public:
		stack(){
			top = NULL;
		}
		void push(int data) {
	        node* newNode = new node(data);
	        if (top == NULL) {
	            top = newNode;
	        } else {
	            newNode->next = top;
	            top = newNode;
	    	}
        }
        void pop(){
        	if(top == NULL){
        		cout<<"Stack is empty"<<endl;
        		return;
			}
			node* temp=top;
			top = top->next;
			delete temp;
		}
		int peek(){
			if(top == NULL){
				cout<<"Stack is empty"<<endl;
        		return -1;
			}
			return top->data;
		}
		void display(){
			if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
		}
};
int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}

