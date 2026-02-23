#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

int search(int inorder[],int start,int end,int curr){
	for(int i=start;i<=end;i++){
		if(inorder[i]==curr){
			return i;
		}
	}
	return -1;
}
Node* buildTree(int postorder[],int inorder[],int start,int end){ 
	static int idx=4;
	if(start>end){
		return NULL;
	}
	int curr=postorder[idx];
	idx--;
	Node* node=new Node(curr);
	if(start==end){
		return node;
	}
	int pos=search(inorder,start,end,curr);
	node->left=buildTree(postorder,inorder,start,pos-1);
	node->right=buildTree(postorder,inorder,pos+1,end);
	return node;
}
void inorderPrint(Node* root){
	if(root==NULL){
		return;
	}
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}
int main(){
	int postorder[] = {4, 2, 5, 3, 1};
	int inorder[]={4,2,1,5,3};
	Node* root=buildTree(postorder,inorder,0,4);
	inorderPrint(root);
}
//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//    Node(int val) {
//        data = val;
//        left = NULL;
//        right = NULL;
//    }
//};
//
//// Function to find the index of the current root in inorder
//int search(int inorder[], int start, int end, int curr) {
//    for (int i = start; i <= end; i++) {
//        if (inorder[i] == curr) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//// Recursive function to build the tree from postorder and inorder arrays
//Node* buildTree(int postorder[], int inorder[], int start, int end, int& idx) {
//    if (start > end) {
//        return NULL;
//    }
//
//    int curr = postorder[idx];
//    idx--;
//    Node* node = new Node(curr);
//
//    if (start == end) {
//        return node;
//    }
//
//    int pos = search(inorder, start, end, curr);
//    node->right = buildTree(postorder, inorder, pos + 1, end, idx);  // Build right subtree first
//    node->left = buildTree(postorder, inorder, start, pos - 1, idx);   // Then build left subtree
//    
//    return node;
//}
//
//// Function to print the inorder traversal of the tree
//void inorderPrint(Node* root) {
//    if (root == NULL) {
//        return;
//    }
//    inorderPrint(root->left);
//    cout << root->data << " ";
//    inorderPrint(root->right);
//}
//
//int main() {
//    int postorder[] = {4, 2, 5, 3, 1};
//    int inorder[] = {4, 2, 1, 5, 3};
//    int n = sizeof(postorder) / sizeof(postorder[0]);  // Size of the array
//    int idx = n - 1;  // Initialize the index for the postorder array
//
//    Node* root = buildTree(postorder, inorder, 0, n - 1, idx);
//    inorderPrint(root);
//    
//    return 0;
//}

