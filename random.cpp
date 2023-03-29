#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
void getnum(){
  
}

int main() {
  int num[25]={26};
  int duplicate=0;
  int n=0,c=1,ij=0,j=0;
  int bingo[5][5]={0};
  
  
  srand(time(NULL));
  
  for(int i=0;i<25;i++){
    duplicate=0;
    while (duplicate ==0){
      c=1;
      n=rand()%(25-1+1)+1;
      for(int j=0;j<25;j++){
        if(num[j]==n){
          c=0;
          break;
        }
      }
      if (c==0)
        duplicate=0;
      else{
        duplicate=1;
        num[i]=n;
        ij=i/5;
        j=i%5;
        bingo[j][ij]=n;
        break;
      }
    }
  }
  int finish=0,line=0;
  while(finish==0){
    n=rand()%(25-1+1)+1;
    bingo[n/5][n%5]=0;
    for(int i=0;i<5;i++){
      if(bingo[0][i]==0){
        line=0;
        for(int j=0;j<5;j++){
          if(bingo[i][j]==0){
            line++;
          }
        }
        if (line==5){
          cout<<"bingo!";
          return(0);
        }
      }
    }
    for(int i=0;i<5;i++){
      if(bingo[i][0]==0){
        line=0;
        for(int j=0;j<5;j++){
          if(bingo[j][i]==0){
            line++;
          }
        }
        if (line==5){
          cout<<"bingo!";
          return(0);
        }
      }
    }
    if(bingo[0][0]==0){
        line=0;
        for(int j=0;j<5;j++){
          if(bingo[j][j]==0){
            line++;
          }
        }
        if (line==5){
          cout<<"bingo!";
          return(0);
        }
      }
    if(bingo[4][0]==0){
        line=0;
        for(int j=0;j<5;j++){
          if(bingo[4-j][j]==0){
            line++;
          }
        }
        if (line==5){
          cout<<"bingo!";
          return(0);
        }
      }

  }
  
}