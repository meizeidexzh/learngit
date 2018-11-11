#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode{
	int w;
	struct TreeNode *left, *right;
};
typedef struct TreeNode *Huffman;
typedef Huffman PtrT;

/*--------------------------------MinHeap definition----------------------*/
typedef PtrT ElementType;
struct HeapNode{
	ElementType *vals;
	int size; int capacity;
};
typedef struct HeapNode *MinHeap;

void Insert(MinHeap H, ElementType item){
	int parent, child;
	if(H->size == H->capacity){
		cout << "Heap is full" << endl; return;
	}
	H->size ++;
	for(child=H->size-1; (child-1)/2>=0; child=parent){
		parent = (child -1)/2;
		if(child == 0 || item->w > H->vals[parent]->w) break;
		H->vals[child] = H->vals[parent];
	}
	H->vals[child] = item;
}

ElementType Delete(MinHeap H){
	if(H->size == 0){
		cout << "heap is empty" << endl; return NULL;
	}
	int parent, child; ElementType Min, temp;
	temp = H->vals[H->size-1]; Min = H->vals[0]; H->size --;
	for(parent=0; 2*parent+1<H->size; parent=child){
		child = 2*parent+1;
		if(child != H->size-1 && H->vals[child+1]->w<H->vals[child]->w)
			child ++;
		if(temp->w < H->vals[child]->w) break;
		H->vals[parent] = H->vals[child];
	} 
	H->vals[parent] = temp;
	return Min;
}

MinHeap CreateHeap(int *arr, int N){
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapNode));
	H->size = 0; H->capacity = 50; 
	H->vals = (ElementType*)malloc(sizeof(ElementType)*H->capacity);
	int i; PtrT temp;
	for(i=0; i<N; i++){
		temp = (PtrT)malloc(sizeof(struct TreeNode));
		temp->w = arr[i]; temp->left = temp->right = NULL;
		Insert(H, temp);
	}
	return H;
}

/*------------------------Minheap Definiton finished---------------------*/

Huffman CreateHuffman(int *arr, int N){
	MinHeap H = CreateHeap(arr, N);
	Huffman T; int i, len = H->size;
	for(i=1; i<len; i++){
		T = (Huffman)malloc(sizeof(struct TreeNode));
		T->left = Delete(H); T->right = Delete(H);
		T->w = T->left->w + T->right->w; Insert(H, T);
	} 
	T = Delete(H);
	return T;
}

void PrintHuffman(Huffman root){
	if(root){
		cout << root->w << " ";
		PrintHuffman(root->left); PrintHuffman(root->right);
	}
}

int main(){
	int arr[] = {5, 6, 7, 8, 15}, n = 5;
	Huffman T = CreateHuffman(arr, n);
	PrintHuffman(T);
	return 0;
}
