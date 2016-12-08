#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream in ("rj.in");
ofstream out("rj.out");
char a[102][102];
int n,m,xr,yr,xj,yj;
const int dx={-1,-1,0,1,1,1,0,-1};
const int dy={0,1,1,1,0,-1,-1,-1};
void citire()
{
    char sir[102];
    int i,j;
    in>>n>>m;
    in.get();
    for(i=1;i<=n;i++)
    {
        in.getline(sir,102,'\n');
            for(j=0;j<m;j++)
                {
                    a[i][j+1]=sir[j];
                    if(a[i][j+1]=='R'){xr=i;yr=j+1;}
                    if(a[i][j+1]=='J'){xj=i;yj=j+1;}
                }

    }
    in.close();
    for(i=1;i<=n;i++)
    {
            out<<a[i]+1;
        out<<endl;
    }
    out.close();

}
int bune(int ii,int jj)
{
    return (ii=1 and ii<=n and jj>=1 and jj<=m);
}
void drum(int i,int j,int pas)
{
    int ii,jj,k;
    for(k=0;k<8;k++)
    {
        ii=i+dx[k];
        jj=j+dy[k];
        if(bune(ii,jj))
            if((a[ii][jj]==' ')and (ar[ii][jj]>pas or ar[ii][jj]==0))
            {
                ar[ii][jj]pas;
                drum(ii,jj,pas+1);
            }
    }
}
int main()
{
    citire();
    return 0;
}
