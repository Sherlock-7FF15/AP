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
