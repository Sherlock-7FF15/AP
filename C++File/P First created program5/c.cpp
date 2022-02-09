#include <iostream>
using namespace std;
class V
{
public:
	void Scanf()
	{
		cin>>length>>width>>height;
	}
	void Printf()
	{
		cout<<"V="<<length*width*height<<endl;
	}
private:
	int length,width,height;
};
int main()
{
	V v;
	v.Scanf();
	v.Printf();
	return 0;
}