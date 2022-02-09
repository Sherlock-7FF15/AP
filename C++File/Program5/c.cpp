#include <iostream>
using namespace std;
class Time
{
public:
	int hour;
	int min;
	int sec;
};
int main()
{
	void settime(Time &);
	void display(Time &);
	Time t;
	settime(t);
	display(t);
	return 0;
}
void settime(Time &t)
{
	cin>>t.hour;
	cin>>t.min;
	cin>>t.sec;
}
void display(Time &t1)
{
	cout<<t1.hour<<":"<<t1.min<<":"<<t1.sec<<endl;
}