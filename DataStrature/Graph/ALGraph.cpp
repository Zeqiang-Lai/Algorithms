/*
图的邻接表表示法
Adjacency List Graph 
既可以用于有向图也可以用于无向图
有向图为了方便查找出度和入度，可以多建立一个逆邻接表
*/

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;

class ALGraph{
    struct ArcNode{
        int adjvex; // 这条边指向的节点的位置
        ArcNode *nextarc;   // 下一条边
        InfoType * info;    // 边的信息
    };
    struct VNode{
        VertexType data;    // 顶点信息
        ArcNode * firstarc; // 与该顶点相连的第一条边
    };
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