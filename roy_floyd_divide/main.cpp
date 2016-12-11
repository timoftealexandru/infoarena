#include <iostream>
#include<fstream>
using namespace std;
#define inf 20000000
ofstream out("graf.out");
int a[100][100],b[100][100],m,n,s;
void roy_floyd();
void afisare();
void divide(int x,int y);
int main()
{
    int i,j,x,y,c;
    ifstream in("graf.in");
    in>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           {
               a[i][j]=inf;
           }
    for(i=0;i<m;i++)
    {
        in>>x>>y>>c;
        a[x][y]=c;
        a[y][x]=c;
    }
    in.close();
    out<<"mat initiala="<<endl;
    afisare();
    roy_floyd();
    out<<"mat cu costuri minime="<<endl;
    afisare();
    out<<endl<<endl;
    cout<<"x=";cin>>x;
    cout<<"y=";cin>>y;
    out<<a[x][y]<<endl;
    divide(x,y);
    out.close();

    return 0;
}
void afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            if(a[i][j]==inf)out<<"* ";
        else out<<a[i][j]<<" ";
        out<<endl;
    }
}
void roy_floyd()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i!=j and i!=k and j!=k)
                    if(a[i][j]>a[i][k]+a[k][j])
                        a[i][j]=a[i][k]+a[k][j];
}
void divide(int x,int y)
{
          int k=1,ok=1;
          while(k<=n and ok)
              {
                if(x!=y and y!=k)
                if(a[x][y]==a[x][k]+a[k][y])
                    {
                        divide(x,k);
                        divide(k,y);
                        ok=0;
                    }
                    k++;
                }
            if(ok==1)out<<x<<" ";



}
