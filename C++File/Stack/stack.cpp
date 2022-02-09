#include <iostream>
#include "stack.h"
using namespace std;


stack::stack()
{
	top=base=new char[10];
}

stack::~stack()
{
	delete[] base;
}


void stack::clearstack()		//���
{
	top=base;
}


int stack::isempty()			//�п�
{
	return top==base;
}


int stack::length()			//�󳤶�
{
	return top-base;
}


char stack::gettop()			//ȡջ��Ԫ��
{
	if(isempty())
		return '\0';
	
	return *(top-1);
}


int stack::push(char c)			//��ջ
{
	if(top-base==10)
		return 0;
	*top++=c;
	return 1;
}


int stack::pop(char *p)			//��ջ
{
	if(isempty())
		return 0;
	*p=*--top;
	return 1;
}


void stack::traverse()			//����
{
	for(char *p=base;p<top-1;p++)
		cout<<*p<<",";
	cout<<*p<<endl;
}
