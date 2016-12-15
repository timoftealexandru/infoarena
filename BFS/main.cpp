#include <fstream>
using namespace std;
int a[100][100],coada[100],viz[100],tata[100],n,m;
void citire()
{
    int i,e1,e2;
    ifstream in("graf.in");
    in>>n>>m;
    for(i=1;i<=m;i++)
    {
        in>>e1>>e2;
        a[e1][e2]=1;
        a[e2][e1]=1;
    }
    in.close();
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
            if(viz[i]==0 and a[coada[pi]][i]==1)
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
