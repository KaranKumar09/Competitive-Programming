#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
node* buildTree(node* root){
	cout<<"Enter data for building the tree: ";
	int val;
	cin>>val;
	root = new node(val);
	if(val == -1){
		return NULL;
	}
	cout<<"Enter data for left of "<<val<<endl;
	root->left = buildTree(root->left);
	cout<<"Enter data for right of "<<val<<endl;
	root->right = buildTree(root->right);
	return root;
}
void levelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
void inOrder(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<enld;
	inOrder(root->left);
	inOrder(root->right);
}
void preOrder(node* root){
	if(root == NULL){
		return;
	}
	preOrder(root->left);
	cout<<root->data<<endl;
	preOrder(root->right);
}
void postOrder(node* root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<endl;
}
node* insertNode(node* root,int val){
	if(root == NULL){
		return new node(val);
	}
	if(root->data > val){
		root->left = insertNode(root->left,val);
	}else{
		root->right = insertNode(root->right,val);
	}
	return root;
}
node* minVal(node* root){
	node* current = root;
	while(current != NULL && current->next != NULL){
		current = current->next;
	}
	return current;
}
node* deleteNode(node* root,int key){
	if(root == NULL){
		return root;
	}
	else if(key < root->data ){
		root->left = deleteNode(root->left, key);
	}
	else if(key > root->data){
		root->right = deleteNode(root->right,key);
	}
	else{
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		if(root->left != NULL && root->right != NULL){
			int mini = minVal(root->right)->data;
			root->data = mini;
			root->right = deleteNode(root->right,mini);
			return root;
		}
	}
}
int main(){
	node* root = NULL;
	root = buildTree(root);
	levelOrder(root);
	return 0;
}
