#include<iostream>
#include<string>
using namespace std;
class base {
public:
	base(){
		cout << "Default constructor of Base" << endl;
	}
	base(int b)
	{
		cout<<"Parameters of the class"<<b;

	}
};
class derived:public base {
public:
	derived():base(){
		cout<<"Default derived constructor"<<endl;
	}
	derived(int b):base( b){
		cout<<"Parameters of derived constructor"<<endl;
	}
};

int main()
{

	derived d1;
	derived d2(2);
	return 0;

}







