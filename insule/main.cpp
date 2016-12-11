#include <iostream>
#include<fstream>
using namespace std;
ifstream in("insule.in");
ofstream out("insule.out");
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
void FILL(int a[][101],int n,int m,int val,int i,int j);
void afisare(int a[][101],int n,int m);
int bune(int ii,int jj,int n,int m);
int main()
{
    int a[101][101],n,m,i,j,nr,nb,ng,lg,ii,jj,nec,k,cx[2500],cy[2500];
    char s[101];
    in>>n>>m; in.get();
    for(i=0;i<n;i++)
    {
        in.getline(s,101,'\n');
        for(j=0;j<m;j++)
            a[i][j]=s[j]-'0';
    }
    in.close();
    nr=0;nb=0;ng=0;
  /* cout<<n<<" "<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
  */  for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                nr++;
                FILL(a,n,m,-1,i,j);
            }
            if(a[i][j]==2)
            {
                ng++;
                FILL(a,n,m,-2,i,j);
            }
            if(a[i][j]==3)
            {
                nb++;
                FILL(a,n,m,-3,i,j);
            }
        }
//    afisare(a,n,m);
    out<<endl<<nr<<" "<<ng<<" "<<nb<<endl;
    nec=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(a[i][j]==-1)
            {
                for(k=0;k<4;k++)
                {
                    ii=i+dx[k];
                    jj=j+dy[k];
                    if(bune(ii,jj,n,m))
                        if(a[ii][jj]==0)
                        {
                            a[ii][jj]=1;
                            cx[nec]=ii;
                            cy[nec]=jj;
                            nec++;
                        }
                }

            }
        }
        for(i=0;i<nec;i++)
            out<<cx[i]<<" ";
        out<<endl;
        for(i=0;i<nec;i++)
            out<<cy[i]<<" ";
    out.close();
    return 0;
}
void FILL(int a[][101],int n,int m,int val,int i,int j)
{
    int k,ii,jj;
    a[i][j]=val;
    for(k=0;k<4;k++)
    {
        ii=i+dx[k];
        jj=j+dy[k];
        if(bune(ii,jj,n,m))
            if(a[ii][jj]==-val)
            {
                FILL(a,n,m,val,ii,jj);
            }
    }
}
/*void afisare(int a[][101],int n,int m)
{
    int i,j;
    cout<<n<<" "<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}*/
int bune(int ii,int jj,int n,int m)
{
    return(ii>=0 and ii<n and jj>=0 and jj<m);

}
