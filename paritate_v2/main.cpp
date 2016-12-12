#include <iostream>
#include<fstream>
#include<math.h>
using namespace std;
ofstream out("paritate.out");
struct paritate
{
    int suma;
}x[60000];

int n,ok,gresit[550],m;
void solve()
{
    char ch;
    int i,j,nr,p,sc;
    ifstream in("paritate.in");
    i=0;
    ok=1;
    m=0;
    while(in>>ch and !in.eof())
    {

        p=ch-'0'; //out<<p<<" ";
        nr=0;
        sc=0;
        for(j=0;j<7;j++)
        {
            in>>ch;
            if(ch=='1'){ nr++; sc=sc+pow(2,6-j);}
        }
        x[i].suma=sc;
        if((p==1 and nr%2!=1) or (p==0 and nr%2!=0))
            { ok=0;  gresit[m]=i; m++;}
        i++;
    }
    in.close();
    n=i;
    if(ok==0)
    {
        out<<"NU"<<endl;
        for(i=0;i<m;i++)
            out<<gresit[i]<<" ";
    }
    else
    {
        out<<"DA"<<endl;
        for(i=0;i<n;i++)
            out<<char(x[i].suma);
    }
}
int main()
{
   solve();
    return 0;
}
