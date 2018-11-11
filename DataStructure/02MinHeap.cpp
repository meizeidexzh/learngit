#include <iostream>
#include <cstdlib>
using namespace std;

struct HeapNode{
	int *vals;
	int size; int capacity;
};
typedef struct HeapNode *MinHeap;

MinHeap CreateHeap(int n){
	MinHeap H = (MinHeap)amlloc(sizeof(struct HeapNode));
	H->size = 0; H->capacity = n;
	H->vals = (int*)malloc(sizeof(int)*n);
	return H;
}

void Insert(MinHeap H, int item){
	if(H->size == H->capacity){
		cout << "heap is full" << endl; return;
	}
	int parent, child; H->size ++;
	for(child=H->size-1; (child-1)/2>=0; child=parent){
		parent = (child-1)/2;
		if(child == 0 || item > H->vals[parent]) break;
		H->vals[child] = H->vals[parent];
	}
	H->vals[child] = item;
}

int Delete(MinHeap H){
	int parent, child; int Min, temp;
	temp = H->vals[H->size-1]; Min = H->vals[0]; H->size --;
	for(parent=0; 2*parent+1<H->size; parent=child){
		child = 2*parent + 1;
		if(child != H->size-1 && H->vals[child+1]<H->vals[child])
			child ++;
		if(temp < H->vals[child]) break;
		H->vals[parent] = H->vals[child];
	}
	H->vals[parent] = temp;
	return Min;
}




int main(){
	
	return 0;
}
