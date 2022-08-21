#include<iostream>
using namespace std;
class home{
	int length,breath;
	public:	
		void setData(int x,int y)
		{
			 length = x;
			 breath =y;
		}
		void area(){
			cout<<length*breath<<endl;
		}
};







int main()
{

home h1;
h1.setData(18,29);
h1.area();   


}