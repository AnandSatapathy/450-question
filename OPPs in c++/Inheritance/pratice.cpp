#include<iostream>
#include<string>

using namespace std;

class rectangle{
public:
	int length,breath;

	void area(){
		cout<<"Area:-"<<length*breath<<endl;
	}
};
class cuboid: public rectangle{
public:
	int height;
	void volume(){
		cout<<"Volume:-"<<length*breath*height<<endl;
	}
};
int main(){
	cuboid c;
	c.length=10;
	c.breath=20;
	c.height=30;
	c.area();
	c.volume();
	return 0;
}



