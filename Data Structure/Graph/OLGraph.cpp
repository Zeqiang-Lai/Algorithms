/*
有向图的十字链表表示法
Orthogonal List Graph 
*/

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;

class OLGraph{
    struct ArcBox{
        int tailvex, headvex;   // 该弧的头节点和尾节点
        ArcBox *hlink, *tlink;  // 头相同的下一条弧，尾相同的下一条弧
        InfoType * info;
    };
    struct VexNode{
        VertexType data;
        ArcBox *firstin, *firstout; // 该顶点第一条入弧和出弧
    };
    VexNode xlist[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;

private:
    void GreateDG(){}
    void GreateDN(){}
    void GreateUDG(){}
    void GreateUDN(){
        // 输入顶点数，边数，边有没有信息
        // 循环顶点数
            // 输入顶点信息
        // 循环边数
            // 输入弧的起点，终点
            // 找出起点终点位置
            // 插入这条弧
            // 如果弧有信息，则输入
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