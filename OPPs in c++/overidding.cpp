#include<iostream>
#include<string>
using namespace std;

class base{
public:
	void msg(){
		cout<<"It is the base class"<<endl;
	}
};
class derived: public base{
public:
	void msg(){
		cout<<"It is the derived class"<<endl;
	}
};
int main()
{
	derived d1;
	d1.msg();
	return 0;
}