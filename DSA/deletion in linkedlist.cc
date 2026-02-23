//
//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//    Node(int val) {
//        data = val;
//        next = NULL;
//    }
//};
//
//void insertAtHead(Node* &head, int val) {
//    Node* temp = new Node(val);
//    temp->next = head;
//    head = temp;
//}
//
//void display(Node* head) {
//    Node* temp = head;
//    while (temp != NULL) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
//    cout << endl;
//}
//
//void insertAtTail(Node* &tail, int val) {
//    Node* temp = new Node(val);
//    tail->next = temp;
//    tail = temp;
//}
//
//void insertAtMiddle(Node* &head, Node* &tail, int val, int position) {
//    if (position == 1) {
//        insertAtHead(head, val);
//        return;
//    }
//
//    Node* temp = head;
//    int count = 1;
//    while (count != position - 1 && temp->next != NULL) {
//        temp = temp->next;
//        count++;
//    }
//
//    Node* nodeToInsert = new Node(val);
//    nodeToInsert->next = temp->next;
//    temp->next = nodeToInsert;
//
//    // If we inserted at the end, update the tail
//    if (nodeToInsert->next == NULL) {
//        tail = nodeToInsert;
//    }
//}
//
//void deletionAtHead(Node* &head) {
//    if (head == NULL) return;  // If the list is empty, nothing to delete
//    Node* temp = head;
//    head = head->next;
//    delete temp;
//}
//
//int main() {
//    Node* node1 = new Node(10);
//    Node* head = node1;
//    Node* tail = node1;
//    display(head);
//
//    insertAtHead(head, 20);
//    display(head);
//
//    insertAtTail(tail, 30);
//    display(head);
//
//    insertAtMiddle(head, tail, 40, 3);
//    display(head);
//
//    deletionAtHead(head);
//    display(head);
//
//    return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	arr[n-1]++;
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	
}
