#include <iostream>
const int F=3;
const int H=6;
void fila (double matriz [][H],int n,int m,int x);
void print(double matriz [][H]);
void suma(double matriz [][H],int f1,int f2);
int main (void){
  double matriz [F][H];
  matriz [0][0]=1;  matriz [0][1]=1;  matriz [0][2]=1;
  matriz [1][0]=1;  matriz [1][1]=0;  matriz [1][2]=1;
  matriz [2][0]=0;  matriz [2][1]=1;  matriz [2][2]=1;
  matriz [0][3]=0;  matriz [0][4]=0;  matriz [0][5]=1;
  matriz [1][3]=0;  matriz [1][4]=1;  matriz [1][5]=0;
  matriz [2][3]=1;  matriz [2][4]=0;  matriz [2][5]=0;
  /*for(int n=0;n<F;++n){
    for(int m=F;m<H;++m){
      if (m==n+F) matriz [n][m]=1;
      else matriz [n][m]=0;
    }
  }*/
  print(matriz);
  for (int iii=0;iii<F;++iii){
    for (int ii=0;ii<F;++ii){
      if(ii!=iii){
	fila (matriz,iii,ii,1);
	if (matriz[ii][iii]!=0)suma (matriz,iii,ii);
	if (ii==F-1) fila (matriz,iii,ii,0);
      }
    }
  }
  print(matriz);
  return 0;
}
void fila (double matriz [][H],int n,int m,int x){
  for(int ii=0;ii<H;++ii){
    if (matriz [n][ii]!=0){
      for (int iii=(ii+1);iii<H;++iii){
	matriz[n][iii]/=matriz[n][ii];
	if (x==1 && matriz[m][ii]!=0) matriz[n][iii]*=(-1*matriz[m][ii]);
      }
      matriz [n][ii]/=matriz [n][ii];
      if (x==1 && matriz[m][ii]!=0) matriz [n][ii]*=(-1*matriz[m][ii]);
      break;
    }
  }
}
void suma (double matriz [][H], int f1, int f2){
  for (int ii=0;ii<H;++ii){
    matriz[f2][ii]+=matriz [f1][ii];
  }
}  
void print(double matriz [][H]){
  for(int n=0;n<F;++n){
    for(int m=0;m<H;++m){
      std::cout<<matriz[n][m]<<'\t';
    }
    std::cout<<'\n';
  }
  std::cout<<'\n';
}
