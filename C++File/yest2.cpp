#include <iostream>
using namespace std;

void test1(int*& p){
      p++;
      cout<<"我是改变后的地址:"<<*p<<endl;
}

void test2(int* p){
      p++;
      cout<<"我不知道是啥："<<*p<<endl;
}

int main() {
      int a[2]={0,10};
      int* p;
      p=a;
      //test1(p);//这个p中传递的p的地址的引用
      test2(p);//这个p中存放着a的首地址
      cout<<"original point: "<<*p<<endl;
      return 0;
}
