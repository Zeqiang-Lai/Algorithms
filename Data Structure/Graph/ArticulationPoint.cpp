/*
求无向连通图的所有重节点
采用深度优先搜索，邻接表方式存储图
回顾：
重节点（割点）：删掉之后，连通图不再连通
*/

#include<iostream>
#include<stdio.h>
#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef char VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
struct ArcNode{
    int adjvex; // 这条边指向的节点的位置
    ArcNode *nextarc;   // 下一条边
    InfoType * info;    // 边的信息
    ArcNode(int adj, ArcNode *next = NULL, InfoType *ifo = NULL) : adjvex(adj), nextarc(next), info(ifo) {}
};
struct VNode{
    VertexType data;    // 顶点信息
    ArcNode * firstarc; // 与该顶点相连的第一条边
};

class ALGraph{
public:
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;

private:
    void GreateDG(){}   //有向图
    void GreateDN(){}   //有向网
    void GreateUDG(){}
    void GreateUDN(){
        // 输入顶点数，边数，边有没有信息
        // 循环顶点数
            // 输入顶点
            // 输入与顶点相关联的边
        int hasArcIfo;
        // printf("Enter: vexnum, arcnum, has arcinformation(1 yes 0 no)\n");
        scanf("%d%d%d",&vexnum, &arcnum, &hasArcIfo);
        for(int i=0;i<vexnum;i++){
            // printf("Node%d:",i);
            char c = getchar(); // 去掉回车
            scanf("%c",&vertices[i].data);
            int adj; scanf("%d",&adj);
            vertices[i].firstarc = new ArcNode(-1);
            ArcNode * p = vertices[i].firstarc;
            while(adj != -1){
                p->nextarc = new ArcNode(adj); 
                p = p->nextarc;
                scanf("%d", &adj);
            }
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

int count = 1;  // 当前顶点访问次序
int visit[MAX_VERTEX_NUM];  // 记录各个顶点访问次序
int low[MAX_VERTEX_NUM];    // 记录每个顶点及其孩子的，最早访问祖先的访问次序

void DFSArticul(ALGraph &G, int v0){
    int min;    // 存储v0节点及其孩子的最早访问祖先的次序,默认为v0本身的访问次序
    visit[v0] = min = ++count;  // 记录访问次序
    for(ArcNode *p = G.vertices[v0].firstarc->nextarc; p; p = p->nextarc){
        int w = p->adjvex;
        if(visit[w] == 0){
            DFSArticul(G,w);
            if(low[w] < min) min = low[w];
            if(low[w] >= visit[v0]) printf("Point:%c\n",G.vertices[v0].data);
        }else if(visit[w] < min) min = visit[w];    //若该节点是v0祖先,则与min比较
    }
    low[v0] = min;
}

void FindArticul(ALGraph &G){
    for(int i=0;i<MAX_VERTEX_NUM;i++) visit[i] = 0; //初始化visit,0代表未访问
    visit[0] = count = 1;   // 选取0号顶点作为根
    ArcNode *p = G.vertices[0].firstarc->nextarc;
    int v = p->adjvex;
    DFSArticul(G,v);

    if(count < G.vexnum){   //表示根存在两棵子树.[1]
        printf("Point:%c\n",G.vertices[0].data);
        while(p->nextarc != NULL){
            p = p->nextarc; v = p->adjvex;
            if(visit[v] == 0) DFSArticul(G,v);
        }
    }
}

int main()
{
    freopen("artculationpoint.in","r",stdin);
    ALGraph G;
    G.GreateGraph(UDN);
    for(int i=0;i<G.vexnum;i++){
        printf("%c:",G.vertices[i].data);
        ArcNode * p = G.vertices[i].firstarc;
        while(p != NULL){
            printf("%d ",p->adjvex);
            p = p->nextarc; 
        }
        printf("\n");
    }
    FindArticul(G);
    for(int i=0;i<G.vexnum;i++) printf("%d ",visit[i]); printf("\n");
    for(int i=0;i<G.vexnum;i++) printf("%d ",low[i]); printf("\n");
    return 0;
}
/*
Test data
测试数据
5 10 0
A
1 
2
-1
L
0
3
4
-1
F
0
-1
M
1
4
-1
J
3
1
-1
*/

/*
[1] count 表示访问次序,由于是连通图,若根只有一棵子树，则必定访问完所有节点,即 count = G.vexnum
    若 count < G.vexnum, 则表示根至少还有一棵子树
*/