#include <iostream>
using namespace std;
class Time
{
public:
	void set();
	void show()
{
	cout<<hour<<":"<<min<<":"<<sec<<endl;
}
private:
	int hour;
	int min;
	int sec;
};
inline void Time::set()
{
	cin>>hour>>min>>sec;
}
int main()
{
	Time t;
	t.set();
	t.show();
	return 0;
}