#include<iostream>
#include<string>
using namespace std;

class mobile{
private:
	string name;
	int RAM;
	string processor;
	int battery;	
public:
	mobile(){
		name = "NULL";
		RAM = 0;
		processor = "NULL";
		battery = 0;
	}
	mobile(string name_a,int ram_a,string processor_a,int battery_a){
		this->name = name_a;
		this->processor = processor_a;
		this->RAM = ram_a;
		this->battery = battery_a;
	}
	mobile(mobile &mob)
	{
		name = mob.name;
		RAM = mob.RAM;
		processor = mob.processor;
		battery = mob.battery;
	}

	void getMobileData();
};
void mobile::getMobileData(){
	cout<<endl<<"Name: "<<name<<endl;
	cout<<endl<<"RAM:  "<<RAM<<endl;
	cout<<endl<<"processor: "<<processor<<endl;
	cout<<endl<<"battery: "<<battery<<endl;
}

int main()
{
	mobile doko;
	mobile doko2("Nokia",4,"Sanapdragon",4000);
	mobile doko3(doko2);

	doko.getMobileData();
	doko2.getMobileData();
	doko3.getMobileData();

	return 0;

}