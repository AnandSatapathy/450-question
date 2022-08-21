#include<iostream>
#include<string>
using namespace std;

 // Non-Parametrized Construct
class Person{
 private:
 	string name;
 	int age;
 	float height;
 public:
 	// Non-Parametrized Construct
 	Person(){
 		name="NULL";
 		age=0;i
 		height=0;
 	}
 	// Parametrized Construct
 	
 	void getData(){
 		cout<<endl<<"Name: "<<name;
 		cout<<endl<<"Age: "<<age;
 		cout<<endl<<"Height: "<<height;
 	}
};


int main(){
	Person obj;
	obj.getData();
	return 0;
}