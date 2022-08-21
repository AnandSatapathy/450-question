#include<iostream>
#include<string>
using namespace std;
class base
{
public:
	
	~base(){
		cout<<"Base Class Destructor"<<endl;
	}
	
};
class derived: public base
{
public:
	
	~ derived(){
		cout<<" derived class Destructor"<<endl;
	}
	
};
int main()
{
	base *ptr = new derived();
	delete ptr;
}