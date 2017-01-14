#include <iostream>
#include<fstream>
using namespace std;
ifstream in("graf.in");
ofstream out("graf.out");
struct muchie
{
    int e1,e2;
}x[100];
int n,m,viz[100],t[100],k,sir[100];
void dfs(int nod);
int vecin(int a,int b);
int main()
{
    int nod,i;
    cout<<"nod=";
    cin>>nod;
    in>>n>>m;
    for(i=0;i<m;i++)
        in>>x[i].e1>>x[i].e2;
    in.close();
    dfs(nod);
    out<<"DFS=";
    for(i=1;i<=k;i++)
        out<<sir[i]<<" ";
    out<<endl<<"T=";
    for(i=1;i<=n;i++)
        out<<t[i]<<" ";
    out.close();
    return 0;
}
void dfs(int nod)
{
    int i;
    k++;
    sir[k]=nod;
    viz[nod]=1;
    for(i=1;i<=n;i++)
        if(vecin(nod,i))
            if(viz[i]==0)
            {
                t[i]=nod;
                dfs(i);
            }
}
int vecin(int a,int b)
{
    int i;
    for(i=0;i<m;i++)
        if((x[i].e1==a  and x[i].e2==b) || (x[i].e1==b and x[i].e2==a)) return 1;
    return 0;
}
