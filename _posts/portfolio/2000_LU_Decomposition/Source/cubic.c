//
//  Cubic Spline Interpolation Program Ver.0.1
//
//                     Stop Motion Device
//                                    for
//                 Taking Motion Pictures
//

//  Coded by Kim,Dong-ho in DGU
//  2000.10.11

#include <stdio.h>
#include <conio.h>
#include <math.h>

int n;
float t[20]={0}, f[5][20]={0};
float a[5][20][20]={0};
float b[5][20]={0};
float l[5][20][20]={0}, u[5][20][20]={0};
float c[5][20]={0}, x[5][20]={0};

// 데이터 파일 읽기
void input_data(void)
{
  int i;
  FILE *fp1;
    if ((fp1 = fopen("input.txt","r")) == NULL)
    {
      fprintf(stderr, "ERROR OPENING FILE...");
      exit(1);
    }
    fscanf(fp1,"%d ", &n);
    i=1;
    while (i<n+1)
    {
      fscanf(fp1,"%f %f %f %f %f",&t[i],&f[1][i],&f[2][i],&f[3][i],&f[4][i]);
      i++;
    }
  fclose(fp1);
}

// 입력 데이터에서 큐빅 스플라인의 연립방정식으로 만듦...
void make_equ(void)
{
  int i,e;

  e=1;
  while (e<5)
  {
    i=1;
    while (i<n-1)
    {
      a[e][i][i-1]=t[i+1]-t[i];
      a[e][i][i+0]=2.0*(t[i+2]-t[i]);
      a[e][i][i+1]=t[i+2]-t[i+1];
      b[e][i]=6.0*(   (f[e][i+2]-f[e][i+1])/(t[i+2]-t[i+1]) + (f[e][i]-f[e][i+1])/(t[i+1]-t[i])   );
      i++;
    }
    a[e][1][0]=0.0;
    a[e][n-2][n-1]=0.0;
    e++;
  }

}


//
// LU Decomposition 해법 함수들
//

// Make matrix "L" and "U"
void make_lu(void)
{
  int i, j,k,e;
  float sum;

  e=1;
  while (e<5)
  {
    // Step 0 : u[1][1], u[2][2], u[3][3] 에 1 값 넣기(대각행렬)
    i=1;
    while (i<n-1)  
    {
      u[e][i][i]=1;
      i++;
    }
    // Step 1
    i=1;
    while (i<n-1)  
    {
      l[e][i][1]=a[e][i][1];
      i++;
    }
    j=2;
    while (j<n-1)  
    {  
      u[e][1][j]=a[e][1][j]/l[e][1][1];
      j++;
    }
    // Step 2
    j=2;
    while (j<n-1)
    {
      i=j;
      while (i<n-1)
      {
        k=1;
        sum=0;
        while (k<j)
        {
          sum=sum+l[e][i][k]*u[e][k][j];
          k++;
        }
        l[e][i][j]=a[e][i][j]-sum;
        i++;
      }
      i=j+1;
      while (i<n-1)
      {
        k=1;
        sum=0;
        while (k<j)
        {
          sum=sum+l[e][j][k]*u[e][k][i]; 
          k++;
        }
        u[e][j][i]=(a[e][j][i]-sum)/l[e][j][j];
        i++;
      }
      j++;
    }
    e++;
  }

}


// Forward Substitution
void forward_substitution(void)
{
  int i,j,k,e;
  float sum;

  e=1;
  while (e<5)
  {
    c[e][1]=b[e][1]/l[e][1][1];
    i=2;
    while (i<n-1)
    {
      k=1;
      sum=0;
      while (k<i)
      {
        sum=sum+l[e][i][k]*c[e][k];
        k++;
      }
      c[e][i]=(b[e][i]-sum)/l[e][i][i];
      i++;
    }
    e++;
  }
  
}


// Backward Substitution
void back_substitution()
{
  int i,j,k,e;
  float sum;

  e=1;
  while (e<5)
  {
    x[e][n-1]=c[e][n-2];
    i=n-3;
    while (i>0)
    {
      k=i+1;
      sum=0;
      while (k<n-1)
      {
        sum=sum+u[e][i][k]*x[e][k+1];
        k++;
      }
      x[e][i+1]=c[e][i]-sum;
      i--;
    }
    e++;
  }
    
}


void lu_decomp(void)
{
  make_lu();
  forward_substitution();
  back_substitution(); 
}


//
//  결과 데이터 생성 및 출력
//
void result(void)
{
  int i,j,k,e;
  float v_t;
  float v_f[5][5]={0};

  FILE *fp3;

  if ((fp3 = fopen("output.txt","w")) == NULL)
  {
    fprintf(stderr, "ERROR OPENING FILE... %s", "d:\\tc\\output.txt");
    exit(1);
  }

  // No.     : 연번
  // Sec.   : 실제 시간 (초)
  // Axis1 : Track
  // Axis2 : Lift
  // Axis3 : Pan
  // Axis4 : Tilt
  //fprintf(fp3,"No.      Sec.         Axis1         Axis2        Axis3        Axis3 \n");

  i=1;
  v_t=t[1];
  while ((v_t<=t[n]) && (i<1000))
  {
    k=1;
    while (k<n-1)
    {
      if ( (v_t>=t[k]) && (v_t<t[k+1]) )
      {
        j=k;
      }
      k++;
    }
    if ( (v_t>=t[n-1]) && (v_t<=t[n]) )
    {
      j=n-2;
    }

    fprintf(fp3,"%4d      %6.3f       %6.3f       %6.3f       %6.3f       %6.3f \n"
                  ,i,v_t,v_f[1][4],v_f[2][4],v_f[3][4],v_f[4][4]);

    e=1;
    while (e<5)
    {
      v_f[e][0] = x[e][j] / ( 6.0 * (t[j+1]-t[j]) );
      v_f[e][1] = x[e][j+1] / (6.0 * (t[j+1]-t[j]) );
      v_f[e][2] = f[e][j] / (t[j+1]-t[j]) - x[e][j] * (t[j+1]-t[j]) / 6.0;
      v_f[e][3] = f[e][j+1] / (t[j+1]-t[j]) - x[e][j+1] * (t[j+1]-t[j]) / 6.0;
      v_f[e][4] = 
            v_f[e][0] *  (t[j+1]-v_t) *  (t[j+1]-v_t) *  (t[j+1]-v_t)
            + v_f[e][1] * (v_t-t[j]) * (v_t-t[j]) * (v_t-t[j])
            + v_f[e][2] * ( t[j+1]-v_t )
            + v_f[e][3] * ( v_t-t[j] );
      e++;
    }

    v_t=v_t+ (1.0/24.0);
    i++;
  }

  fclose(fp3);

}



void main(void)
{
  input_data();
  make_equ();
  lu_decomp();
  result();
  printf("Operation Done... Press any key!");
  getchar();
}
