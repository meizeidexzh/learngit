#include <iostream>
#include <cstdlib>
using namespace std;

#define null -100000

struct TreeNode{
	int val;
	struct TreeNode *left, *right;
};

typedef struct TreeNode *BinTree;
typedef BinTree PtrT;

BinTree BuildTree(int *arr, int n){
	int i; PtrT p, temp[n];
	for(i=n-1; i>=0; i--){
		if(arr[i] == null) temp[i] = NULL;
		else{
			p = (PtrT)malloc(sizeof(struct TreeNode));
			p->val = arr[i]; p->left = p->right = NULL; temp[i] = p;
			if(2*i+1<=n-1) p->left = temp[2*i+1];
			if(2*i+2<=n-1) p->right = temp[2*i+2];
		}
	}
	return temp[0];
}

void PreOrder(BinTree root){
	if(root){
		cout << root->val <<" ";
		PreOrder(root->left); PreOrder(root->right);
	}
}

void PreOrderNo(BinTree root){
	BinTree p, stack[50]; int size=0;
	p = root;
	while(p || size != 0){
		while(p){
			stack[size] = p; size ++; cout << p->val << " ";
			p = p->left; 
		}
		if(size != 0){
			p = stack[size-1]; size --;
			p = p->right;
		}
	}
	cout << endl;
}

void InOrder(BinTree root){
	if(root){
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}

void InOrderNo(BinTree root){
	BinTree stack[50]; int size=0;
	while(root || size != 0){
		while(root){
			stack[size] = root; size ++; 
			root = root->left;
		}
		if(size != 0){
			root = stack[size-1]; size --; cout << root->val << " ";
			root = root->right;
		}
	}
	cout << endl;
}

void PostOrder(BinTree root){
	if(root){
		PostOrder(root->left); PostOrder(root->right);
		cout << root->val << " ";
	}
}

void PostOrderNo(BinTree root){
	BinTree stack[50]; int size;
	BinTree cur, pre; cur = pre = NULL;
	if(!root) return;
	stack[size] = root; size ++;
	while(size != 0){
		cur = stack[size-1];
		if(!cur->left && !cur->right){
			cout << cur->val << " ";
			pre = cur; size --;
		}
		else if((!pre) && ((pre == root->left) || (pre == root->right))){
			cout << cur->val << " ";
			pre = cur; size --;
		}
		else{
			if(root->left) stack[size++] = root->left;
			if(root->right) stack[size++] = root->right;
		}
	}
	cout << endl;
}


void LevelOrder(BinTree root){
	BinTree Q[50]; int head, tail, capacity;
	head = tail = 0; capacity = 50;
	if(!root) return;
	tail = (tail+1)%capacity;
	Q[tail] = root;
	while(head != tail){
		head = (head+1)%capacity;
		root = Q[head]; cout << root->val << " ";
		if(root->left){
			tail = (tail+1)%capacity;
			Q[tail] = root->left;
		}
		if(root->right){
			tail = (tail+1)%capacity;
			Q[tail] = root->right;
		}
	}
	cout << endl;
}



void PrintTree(BinTree root){
	PostOrder(root); cout << endl;
}



int main(){
	cout  << (3 << 1) << endl;
	return 0;
}
