#include <iostream>
using namespace std;
class stack						//ջ��
{
	public:
		stack();
		~stack();
		void clearstack();		//���
		int isempty();			//�п�
		int length();			//�󳤶�
		char gettop();			//ȡջ��Ԫ��
		int push(char);			//��ջ
		int pop(char*);			//��ջ
		void traverse();			//����
		char *base;				//ջ��ָ��
		protected:
	char *top;				//ջ��ָ��
};
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

const int prior[][5]={{1,1,2,2,1},
						{1,1,2,2,1},
						{1,1,1,1,1},
						{1,1,1,1,1},
						{2,2,2,2,0}};//1:>;2:<;0:=
const int n=5;
const char op[]={'+','-','*','/','#'};
int getIndex(char c)
{
	for(int i=0;i<n;i++)
	{
		if(op[i]==c)
			return i;
	}
	return -1;
}
int calculate(char *str)
{
	stack opnd,optr;
	char *p=str,c,num1,num2;
	int res;
	optr.push(*p++);
	for(;*p!='\0';)
	{
		if(*p>=48&&*p<=57)
			opnd.push(*p++);
		else if(getIndex(*p)>-1)
		{
			if(prior[getIndex(optr.gettop())][getIndex(*p)]==2)
			{
				//in
				optr.push(*p++);
			}
			else if(prior[getIndex(optr.gettop())][getIndex(*p)]==1)
			{
				//out
				optr.pop(&c);
				opnd.pop(&num2);
				opnd.pop(&num1);
				if(c=='+')
					res=num1+num2-48;
				else if(c=='-')
					res=num1-num2+48;
				else if(c=='*')
					res=(num1-48)*(num2-48)+48;
				else
					res=(num1-48)/(num2-48)+48;

				opnd.push(res);
			}
			else
			{
				//result
				return opnd.gettop()-48;
			}

		}
		else
		{
			cout<<"error!"<<endl;
			exit(1);
		}
	}
}
int main()
{
	char str[20];
	cout<<"Please input a equation:";
	cin>>str;
	int res=calculate(str);
	cout<<"The result is "<<res<<endl;
	return 0;
}
