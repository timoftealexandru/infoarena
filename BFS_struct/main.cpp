#include <fstream>
using namespace std;
int coada[100],viz[100],tata[100],n,m;
struct muchie
{
    int e1,e2;
}x[100];

void citire()
{
    int i;
    ifstream in("graf.in");
    in>>n>>m;
    for(i=1;i<=m;i++)
    {
        in>>x[i].e1>>x[i].e2;
    }
    in.close();
}
int verificare(int a,int b)
{
    int i;
    for(i=1;i<=m;i++)
        if((x[i].e1==a and x[i].e2==b) || (x[i].e1==b and x[i].e2==a)) return 1;
    return 0;
}
void bfs(int nod)
{
    int pi,ps,i;
    coada[1]=nod;
    viz[nod]=1;
    pi=1;
    ps=1;
    while(pi<=ps)
    {
        for(i=1;i<=n;i++)
            if(viz[i]==0 and verificare(coada[pi],i))
                {
                    viz[i]=1;
                    ps++;
                    coada[ps]=i;
                    tata[i]=coada[pi];
                }
                pi++;
    }
}
int main()
{
    int i;
    citire();
    bfs(1);
    ofstream out("graf.out");
    for(i=1;i<=n;i++)
    {
        out<<coada[i]<<" ";
    }
    out<<endl;
    for(i=1;i<=n;i++)
    {
        out<<tata[i]<<" ";
    }
    out.close();
    return 0;
}
