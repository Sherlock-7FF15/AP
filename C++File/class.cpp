class A
{
    public:
        A(int aa=1):a(aa){};
    protected:
        int a;
};

class B:virtual A
{
    public:
        B(int aa=1,int bb=2):A(aa),b(bb){};
    protected:
        int b;
};

class C:virtual A
{
    public:
        C(int aa=1,int cc=3):A(aa),c(cc){};
    protected:
        int c;
};
class D:public C,public B
{
    public:
        D(int aa=1,int bb=2,int cc=3,int dd=4):B(aa,bb),C(aa,cc),d(dd){};
    protected:
        int d;
};