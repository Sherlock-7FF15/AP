#include <iostream>
#include<iomanip>
using namespace std;

const int x = 10;

void func(int a, int b=2, int c=3, int d=4) {
      cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}

int main()
{
      x=11;
      func(20);
}
