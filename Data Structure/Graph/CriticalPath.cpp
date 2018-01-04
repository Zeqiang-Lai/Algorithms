/*
AOE-网关键路径
*/
#include<iostream>
#include<string.h>
#include<queue>
#define MAX_VERTEX_NUM 1000

class ALGraph{
     struct ArcNode{
        int adjvex; // 这条边指向的节点的位置
        ArcNode *next;   // 下一条边
        int info;    // 边的信息
        int tag;    // 是否为关键活动
        ArcNode(int a,int i): adjvex(a), info(i), next(NULL),tag(0) {}
    };
    struct VNode{
        char data[20];    // 顶点信息
        int indegree;
        ArcNode * firstarc; // 与该顶点相连的第一条边
    };
    VNode vertices[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    int ve[MAX_VERTEX_NUM];
    int tpo[MAX_VERTEX_NUM];
    int st;
    int *path;

    void outputPath(int now, int count){
        path[count] = now;
        if(vertices[now].firstarc->next == NULL){
            printf("%s",vertices[path[0]].data);
            for(int i=1;i<=count;i++)
                printf("-%s",vertices[path[i]].data);    
            printf("\n");        
            return;
        }
        std::priority_queue< int,std::vector<int>,std::greater<int> >q;
        ArcNode * temp = vertices[now].firstarc;
        while(temp->next != NULL){
            temp = temp->next;
            if(temp->tag) q.push(temp->adjvex);
        }        
        while(!q.empty()){
            outputPath(q.top(),count+1);
            q.pop();
        }
    }

public:
    void init(){
        scanf("%d,%d",&vexnum,&arcnum);
        for(int i=0;i<vexnum;i++) {vertices[i].firstarc = new ArcNode(0,0);vertices[i].indegree = 0;}

        char c = getchar();
        c = getchar();
        int i=0,num = 0;
        do{
            if(c == ',') {vertices[num].data[i] = '\0';num++;i=0;}
            else vertices[num].data[i++] = c;
            c = getchar();
        }while(c != '\n');
        vertices[num].data[i] = '\0';
        num = 0;
        int from,to,w;
        while(num < arcnum){
            scanf("<%d,%d,%d>%c",&from,&to,&w,&c);
            vertices[to].indegree++;
            ArcNode * temp = new ArcNode(to,w);
            temp->next = vertices[from].firstarc->next;
            vertices[from].firstarc->next = temp;
            num++;
        }
    }
    int topologicalOrder(){
        // 输入保证无环
        int in[MAX_VERTEX_NUM];
        std::priority_queue< int,std::vector<int>,std::greater<int> >q;
        std::queue<int> T;
        int count = 0;

        for(int i=vexnum-1;i>=0;i--) {
            in[i] = vertices[i].indegree; 
            if(vertices[i].indegree == 0) {q.push(i);st = i;}
            ve[i] = 0;
        }
        while(!q.empty()){
            int j = q.top();
            tpo[count++] = j;
            q.pop();
            ArcNode * temp = vertices[j].firstarc;
            while(temp->next != NULL){
                temp = temp->next;
                int k = temp->adjvex;
                if(--in[k] == 0) q.push(k);
                if(ve[j] + temp->info > ve[k]) ve[k] = ve[j] + temp->info;
            }
        }
        if(count == vexnum){
            printf("%s",vertices[tpo[0]].data);
            for(int i=1;i<count;i++)
                printf("-%s",vertices[tpo[i]].data);
            printf("\n");
            return 1;
        }
        return 0;
    }
    void criticalPath(){
        int vl[MAX_VERTEX_NUM];
        for(int i=0;i<vexnum;i++) vl[i] = ve[i];
        for(int i=vexnum-1;i>=0;i--){
            ArcNode * temp = vertices[tpo[i]].firstarc;
            while(temp->next != NULL){
                temp = temp->next;
                int k = temp->adjvex;
                if(vl[k] - temp->info < vl[tpo[i]]) vl[tpo[i]] = vl[k] - temp->info;
            }
        }
        for(int i=0;i<vexnum;i++){
            ArcNode * temp = vertices[i].firstarc;
            while(temp->next != NULL){
                temp = temp->next;
                int k = temp->adjvex;
                int ee = ve[i], el = vl[k] - temp->info;
                if(ee == el) temp->tag = 1;
            }
        }
        path = new int[vexnum];
        // 输出关键路径
        outputPath(st,0);
        delete []path;
    }
    void display(){
        for(int i=0;i<vexnum;i++){
            printf("%s\n",vertices[i].data);
        }
    }
};

int main()
{
    // freopen("p.in","r",stdin);
    ALGraph g;
    g.init();
    if(g.topologicalOrder()) g.criticalPath();
    else printf("NO TOPOLOGICAL PATH\n");
    return 0;
}