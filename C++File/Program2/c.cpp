#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
T max(T a,T b,T c)
{
	if(b>a)
		a=b;
	if(c>a)
		a=c;
	return a;
}
int main()
{
	cout<<"Please input your name and age:"<<endl;
	char name[10];
	int age;
	cin>>name;
	cin>>age;
	cout<<"Your name is "<<setw(10)<<name<<endl;
	cout<<"Your age is "<<setw(10)<<age<<endl;
	return 0;
}