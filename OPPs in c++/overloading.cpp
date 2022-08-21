#include<bits/stdc++.h>
using namespace std;

class A{
private:
	int weight=0;
public:
	A( int x=0){
		weight = x;
	}
	void displayWeight(){
		cout<<"Weight: "<<weight<<endl;
	}
	A operator+( A W ){
		A temp;
		temp.weight = weight + W.weight;
		return temp;
	}
};


int main(){
	A person(67);
	A person2(56);
	A total;
	total = person + person2;

}