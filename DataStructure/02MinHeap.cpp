#include <iostream>
#include <cstdlib>
using namespace std;

struct HeapNode{
	int *vals;
	int size; int capacity;
};
typedef struct HeapNode *MinHeap;

MinHeap CreateHeap(int n){
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapNode));
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

#define Error -100000
int Delete(MinHeap H){
	int parent, child; int Min, temp;
	if(H->size == 0){
		cout << "heap is empty" << endl; return Error;
	}
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

MinHeap CreateHeap(int *arr, int n, int maxsize){
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapNode));
	H->size = 0; H->capacity = maxsize;
	H->vals =(int*)malloc(sizeof(int)*maxsize);
	int i;
	for(i=0; i<n; i++) Insert(H, arr[i]);
	return H;
} 

void PrintHeap(MinHeap H){
	int i;
	for(i=0; i<H->size; i++) cout << H->vals[i] << " "; cout << endl;
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1,0}, n=10;
	MinHeap H = CreateHeap(arr, n, 50);
	PrintHeap(H);
	for(int i=0; i<11; i++){
		Delete(H); PrintHeap(H);
	}
	return 0;
}
