class stack						//栈类
{
	public:
		stack();
		~stack();
		void clearstack();		//清空
		int isempty();			//判空
		int length();			//求长度
		char gettop();			//取栈顶元素
		int push(char);			//进栈
		int pop(char*);			//出栈
		void traverse();			//遍历
		char *base;				//栈底指针
		protected:
	char *top;				//栈顶指针
};
