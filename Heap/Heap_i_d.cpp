#include<bits/stdc++.h>
using namespace std;
class heap{
	public:
		int arr[1001];
		int size=0;
	heap(){
		arr[0]=-1;
		size=0;
	}

	// time complexity =t(logn)
	void insert(int val){
		size = size+1;
		int index = size;
		arr[index] = val;
		while(index>1)
		{
			int parent = index/2;
			if(arr[parent]<arr[index])
			{
				swap(arr[parent],arr[index]);
				index = parent;
			}
			else
			{
				return;
			}
		}
	}
	// tc ->o(1)
	void deletion(){
		 if(size==0)
		 {
		 	cout<<"Nothing to delete"<<endl;
		 	return;
		 }
		 //step1:put last element into first index
		 arr[1]=arr[size];
		 //step2:remove last element
		 size--;
		 //step3:take root node to its correct position
		 int i = 1;
		 while(i<size)
		 {
		 	int lefIndex = 2*i;
		 	int righthIndex =2*i+1;
		 	if(leftIndex<size && arr[i]<arr[leftIndex])
		 	{
		 		swap(arr[i],arr[leftIndex]);
		 		i = leftIndex;
		 	}
		 	else if(rightIndex<size && arr[i]<arr[rightIndex])
		 	{
		 		swap(arr[i],arr[rightIndex]);
		 		i = rightIndex;
		 	}
		 	else
		 	{
		 		return;
		 	}
		 }
	}
	void print()
	{
		for(int i = 1; i <=size;i++)
		{
			cout<<arr[i]<<" ";
		}cout<<endl;
	}

};
// heapify algorithm for max heap it follow 1 base indexing
// at 0 base indexing left =2*i+1 Right = 2*i+2
void heapify(int arr[],int n,int i)
{
	int largest = i;
	int left =2*i;
	int right =2*i+1;
	if(left<n && arr[largest]<arr[left]){
		largest = left;
	}
	if(right<n && arr[largest]<arr[right]){
		largest = right;
	}
	if(largest!=i){
		
			swap(arr[largest],arr[i]);
			heapify(arr,n,largest);
	
	}
}
// heapify algorithm for min heap it follow 0 base indexing 
void heapify(int arr[],int n,int i)
{
	int smallest = i;
	int left =2*i+1;
	int right =2*i+2;
	if(left<n && arr[smallest]>arr[left]){
		smallest = left;
	}
	if(right<n && arr[smallest]>arr[right]){
		 smallest= right;
	}
	if(smallest!=i){
		
			swap(arr[smallest],arr[i]);
			heapify(arr,n,smallest);
	
	}
}







int main(){
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(42);
	h.insert(87);
	h.deletion();
	h.print();
	int arr[6]={-1,54,53,55,52,50};
	int n = 5;
	for(int i = n/2;i>0;i--){
		heapify(arr,n,i);
	}
	// Tc->o(n);
	cout<<"Printing the array now"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}

	return 0;
}