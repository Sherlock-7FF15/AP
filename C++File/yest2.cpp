#include <iostream>
using namespace std;

void test1(int*& p){
      p++;
      cout<<"���Ǹı��ĵ�ַ:"<<*p<<endl;
}

void test2(int* p){
      p++;
      cout<<"�Ҳ�֪����ɶ��"<<*p<<endl;
}

int main() {
      int a[2]={0,10};
      int* p;
      p=a;
      //test1(p);//���p�д��ݵ�p�ĵ�ַ������
      test2(p);//���p�д����a���׵�ַ
      cout<<"original point: "<<*p<<endl;
      return 0;
}
