#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct TreeNode *PtrT;
struct TreeNode{
	int val;
	struct TreeNode *left, *right;
};
typedef PtrT BinTree;


BinTree Insert(BinTree T, int item){
	PtrT temp; 
	if(!T){
		T = (PtrT)malloc(sizeof(struct TreeNode));
		T->val = item; T->left = T->right = NULL;
	}
	else{
		if(item > T->val) T->right = Insert(T->right, item);
		else if(item < T->val) T->left = Insert(T->left, item);
	}
	return T;
}

PtrT FindMin(BinTree root){
	if(root->right) root = root->right;
	return root;
}

BinTree Delete(BinTree T, int item){
	PtrT temp;
	if(!T){
		cout << "target element not found" << endl; return NULL;
	}
	if(item > T->val) T->right = Delete(T->right, item);
	else if(item < T->val) T->left = Delete(T->left, item);
	else{
		if(T->left && T->right){
			temp = FindMin(T->right); 
			T->val = temp->val;
			T->right = Delete(T->right, temp->val);
		}
		else{
			temp = T;
			if(T->left) T = T->left;
			else T = T->right; 
			free(temp);
		}
	}
	return T;
}

BinTree BuildTree(int *arr, int N){
	int i; PtrT T=NULL;
	for(i=0; i<N; i++) T = Insert(T, arr[i]);
	return T;
}

void PrintTree(BinTree root){
	if(root){
		cout << root->val <<" ";
		PrintTree(root->left); PrintTree(root->right);
	}
}



int main(){
	int arr[] = {1, 5, 4, 3, 2, 6}, n = 6;
	BinTree T = BuildTree(arr, n);
	PrintTree(T); cout << endl;
	Delete(T, 5);
	PrintTree(T);
	return 0;
}
