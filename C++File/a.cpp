#include <iostream>
using namespace std;

void EightQueen(int &row,int &next,int &key[]){
      if(row>3){
            return;
      }
//	int obj[4][4]={0};
	int i,j;
	int judge;
	i=row+1;
	int rare=key[next-1];
	for(j=0;j<4;j++){
            judge=Judgement(i,j,rare);
            if(judge==true){
                  key[next]=i*4+j+1;
                  next++;
                  row++;
                  EightQueen(row,next,key);
            }
	}
}

int Judgement(int i,int j,int rare){
      m=i-1;


}

int main(){
      int x=0;
      int next=0;
      int row=0;
      int key[16]={};
	EightQueen(row,next,key);
	return 0;
}
