/*
最小生成树
普林姆算法 图采用邻接矩阵表示
*/

#include<iostream>

#define MAX_VERTEX_NUM 100
#define INF 2000000

typedef int InfoType;
typedef enum {DG,DN,UDG,UDN} GraphKind;

class MGraph{
    struct ArcCell{
        int adj;    // 边的权值，或是否有边
        InfoType * info;    // 其他信息
    };
public:
    int vexs[MAX_VERTEX_NUM];
    ArcCell arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
private:
    void GreateDG(){}
    void GreateDN(){}
    void GreateUDG(){}
    void GreateUDN(){
        // 输入顶点数，边数，边有没有信息
        // 输入顶点
        // 初始化邻接矩阵
        // 输入邻接矩阵，若边有信息，输入边的信息
        int hasArcIfo;
        scanf("%d%d%d",&vexnum,&arcnum,&hasArcIfo);
        for(int i=0;i<vexnum;i++)
            scanf("%d", &vexs[i]);
        for(int i=0;i<vexnum;i++)
            for(int j=0;j<vexnum;j++) arcs[i][j].adj = INF;
        int x,y,w;
        for(int i=0;i<arcnum;i++){
            scanf("%d%d%d",&x,&y,&w);
            arcs[x][y].adj = w;
            arcs[y][x].adj = w;
        }
    }

public:
    void GreateGraph(int k){
        kind = (GraphKind)k;
        switch(kind){
            case DG: GreateDG();
            case DN: GreateDN();
            case UDG: GreateUDG();
            case UDN: GreateUDN();
        }
    }
};

// Prim算法
struct {
    int adjvex;
    int lowcost;
}closedge[MAX_VERTEX_NUM];

int minimun(int num){
    int minn,i=0;
    while(closedge[i].lowcost == 0) i++;
    minn = i;
    for(;i<num;i++)
        if(closedge[i].lowcost != 0 && closedge[i].lowcost < closedge[minn].lowcost) minn = i;
    return minn;
}

void MiniSpanTree_Prim(MGraph &G, int u){
    for(int i=0;i<G.vexnum;i++) // 初始化数组,更新当前的最短边
        if(i != u) {
            closedge[i].adjvex = u;
            closedge[i].lowcost = G.arcs[u][i].adj;
        }
    closedge[u].lowcost = 0;    // 若某个点加入最小生成树, lowcost置为0做标记
    for(int i=1;i<G.vexnum;i++){    // 剩下的点
        int k = minimun(G.vexnum);
        printf("%d->%d\n",closedge[k].adjvex+1,G.vexs[k]+1);
        closedge[k].lowcost = 0;    // 加入k点
        for(int j=0;j<G.vexnum;j++)
            if(G.arcs[k][j].adj < closedge[j].lowcost){ // 加入新点后,更新边
                closedge[j].lowcost = G.arcs[k][j].adj;
                closedge[j].adjvex = G.vexs[k];
            }
    }
}
// Prim

// Kruskal算法
void Kruskal(MGraph G){

}
// Kruskal
int main()
{
    freopen("minispanningtree.in","r",stdin);
    MGraph G;
    G.GreateGraph(UDN);
    MiniSpanTree_Prim(G,0);
    return 0;
}
/*
测试数据
Test
6 10 1
0 1 2 3 4 5
0 1 6
0 2 1
0 3 5
1 2 5
2 3 5
2 4 6
2 5 4
1 4 3
3 5 2
4 5 6

*/