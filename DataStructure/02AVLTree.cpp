#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left, *right;
};
typedef struct TreeNode *BinTree;
typedef BinTree AVLTree;

int Max(int a, int b){
	return a > b? a : b;
}

int Height(AVLTree root){
	if(!root) return -1;
	return Max(Height(root->left), Height(root->right)) + 1;
} 

BinTree LL(BinTree root){
	BinTree temp = root->left;
	root->left = temp->right; temp->right = root;
	return temp;
}

BinTree RR(BinTree root){
	BinTree temp = root->right;
	root->right = temp->left; temp->left = root;
	return temp;
}

BinTree LR(BinTree root){
	root->left = RR(root->left);
	return LL(root);
}

BinTree RL(BinTree root){
	root->right = LL(root->right);
	return RR(root);
}

BinTree Insert(BinTree root, int item){
	if(!root){
		root = (BinTree)malloc(sizeof(struct TreeNode));
		root->val = item; root->left = root->right = NULL;
	}
	else{
		if(item > root->val){
			root->right = Insert(root->right, item);
			if(Height(root->left)-Height(root->right) == -2){
				if(item > root->right->val) root = RR(root);
				else root = RL(root);
			}
		}
		else if(item < root->val){
			root->left = Insert(root->left, item);
			if(Height(root->left)-Height(root->right) == 2){
				if(item > root->left->val) root = LR(root);
				else root = LL(root);
			}
		}
	}
	return root;
}

AVLTree BuildAVL(int *arr, int N){
	int i; AVLTree T = NULL;
	for(i=0; i<N; i++) T = Insert(T, arr[i]);
	return T;
}

void PrintTree(BinTree root){
	if(root){
		cout << root->val << " ";
		PrintTree(root->left); PrintTree(root->right);
	}
}

int main(){
	int arr[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9}, n=16;
	AVLTree T = BuildAVL(arr, n);
	PrintTree(T);
	return 0;
}
