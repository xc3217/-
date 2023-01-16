#include<iostream>
using  namespace std;
int m, ans=0;
#define MAXVEX  100 

typedef  int EdgeType; 
typedef  string VertexType; 
bool label[MAXVEX];
typedef  struct
{
    VertexType vexs[MAXVEX]; 
    EdgeType arc[MAXVEX][MAXVEX]; 
    int numNodes, numEdges; 
} MGraph;

void fun(int s,MGraph *G)
{
    label[s] = 1;
    cout << G->vexs[s] << ' ';
    for (int i = 0; i < G->numNodes; i++)
    {
        if (!label[i] && G->arc[s][i])
        {
            label[i] = 1;
            fun(i,G);

        }
    }
}
int locate(MGraph* G, string a)
{
    for (int i = 0; i < G->numNodes; i++)
        if (a == G->vexs[i]) return i;
    return -1;
}
void CreateMGraph(MGraph* Gp)
{
    int i, j, k, w;
    cout << "请输入顶点数和边数（空格分隔）：" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;
    cout << "请输入顶点信息（空格分隔）：" << endl;
    for (i = 0; i < Gp->numNodes; i++)
        cin >> Gp->vexs[i];
    for (i = 0; i < Gp->numNodes; i++)
    {
        for (j = 0; j < Gp->numNodes; j++)
        {
                Gp->arc[i][j] = 0; /* 顶点没有到自己的边*/
        }
    }
    string v1, v2;
    for (k = 0; k < Gp->numEdges; k++)
    {
        cout << "请输入边（vi, vj)的上标i，下标j:"<< endl;
        cin >> v1 >> v2;
        i = locate(Gp, v1);
        j = locate(Gp, v2);
        Gp->arc[i][j] = 1;
        Gp->arc[j][i] = Gp->arc[i][j]; /* 因为是无向图，矩阵对称 */
    }
}

void print(MGraph* G)
{
    cout << "领接矩阵为：" << endl;
    for (int i = 0; i < G->numNodes; i++)
    {
        for (int j = 0; j < G->numNodes; j++)
            cout << G->arc[i][j] << " ";
        cout << endl;
    }
}
void DFS(MGraph* G)
{
    for (int i = 0; i < G->numNodes; i++)
    {
        if (!label[i])
        {
            fun(i, G);
            ans += 1;
            cout << endl;
        }
    }

    cout <<"连通分支数为："<< ans;
}
int main(void)
{
    MGraph MG;
    CreateMGraph(&MG);
    print(&MG);
    DFS(&MG);
    return  0;
}
