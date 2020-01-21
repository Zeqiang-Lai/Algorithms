/*
matrix graph
图的数组表示法
*/

#define MAX_VERTEX_NUM 100

typedef int InfoType;
typedef enum {DG,DN,UDG,UDN} GraphKind;

class MGraph{
    struct ArcCell{
        int adj;    // 有向图为边的信息类型，无向图则为是否有边
        InfoType * info;
    };
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