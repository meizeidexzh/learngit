#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int FindRootPos(int L, int R){
	int n = R-L+1;
	int k = log(n)/log(2);
	if((n+1-pow(2,k)) <= pow(2,k-1)) return n-pow(2, k-1)+L;
	return pow(2,k)-1+L;
}

void Solution(int *source, int L, int R, int *target, int pos){
	int M = FindRootPos(L, R);
	if(L > R) return;
	target[pos] = source[M];
	Solution(source, L, M-1, target, 2*pos+1);
	Solution(source, M+1, R, target, 2*pos+2);
}

void Swap(int *a, int *b){
	int c = *a; *a = *b; *b = c;
}

void PercDown(int *arr, int p, int n){
	int parent, child; int temp;
	temp = arr[p];
	for(parent=p; 2*parent+1<n; parent=child){
		child = 2*parent+1;
		if(child != n-1 && arr[child+1] > arr[child])
			child ++;
		if(temp > arr[child]) break;
		else
			arr[parent] = arr[child];
	}
	arr[parent] = temp;
}

void HeapSort(int *arr, int N){
	int i;
	for(i=N/2-1; i>=0; i--) 
		PercDown(arr, i, N);
	for(i=N-1; i>=0; i--){
		Swap(arr, arr+i);
		PercDown(arr, 0, i);
	}
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,0}, n=10, out[500], i;
	HeapSort(arr, n);
	Solution(arr, 0, n-1, out, 0);
	for(i=0; i<n; i++){
		if(i != 0) cout << " ";
		cout << out[i];
	} 
	return 0;
}
