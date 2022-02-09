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


void stack::clearstack()		//清空
{
	top=base;
}


int stack::isempty()			//判空
{
	return top==base;
}


int stack::length()			//求长度
{
	return top-base;
}


char stack::gettop()			//取栈顶元素
{
	if(isempty())
		return '\0';
	
	return *(top-1);
}


int stack::push(char c)			//进栈
{
	if(top-base==10)
		return 0;
	*top++=c;
	return 1;
}


int stack::pop(char *p)			//出栈
{
	if(isempty())
		return 0;
	*p=*--top;
	return 1;
}


void stack::traverse()			//遍历
{
	for(char *p=base;p<top-1;p++)
		cout<<*p<<",";
	cout<<*p<<endl;
}
