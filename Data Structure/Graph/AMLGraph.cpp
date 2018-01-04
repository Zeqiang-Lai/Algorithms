/*
无向图的邻接多重表表示
adjacency multilist 
每条边都存储头和尾
*/

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef enum {unvisited, visited} visitIf;

class ALGraph{
    struct EBox{
        int ivex, jvex; // 边的两个位置
        EBox *ilink,*jlink;   // 依附与这两个顶点的下一条边
        InfoType * info;    // 边的信息
    };
    struct VNode{
        VertexType data;    // 顶点信息
        EBox * firstedge; // 与该顶点相连的第一条边
    };
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;

private:
    void GreateDG(){}
    void GreateDN(){}
    void GreateUDG(){}
    void GreateUDN(){
        // 输入顶点数，边数，边有没有信息
        // 与十字链表相似
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