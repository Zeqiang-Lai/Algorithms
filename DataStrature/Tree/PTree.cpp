/*
树
双亲表示法
*/

#include<iostream>
using namespace std;
#define MAXN 100

struct Pnode{
    char data;
    int parent;
};

class PTree{

public:
    Pnode nodes[MAXN];
    int r,n;    // 根的位置和节点数

    PTree(){r=0; n=0;}
    void Init(){
        cout<<"number of nodes and position of root"<<endl;
        cin>>n>>r;
        for(int i=0;i<n;i++)
            cin>>nodes[i].data>>nodes[i].parent;
    }
    Pnode& Parent(Pnode& node){
        if(node.parent >=0 && node.parent <n)
            return nodes[node.parent];
        return nodes[0];
    }
    Pnode& Root(){
        return nodes[r];
    }
    int* Childs(int p){
        int * childs = new int[10];
        int num = 0;
        for(int i=0;i<n;i++)
            if(nodes[i].parent == p){
                childs[++num] = i;
            }
        childs[0] = num;
        return childs;
    }
};

// int main()
// {
//     PTree tree;
//     tree.Init();
//     cout<<tree.Root().data<<endl;
//     cout<<tree.Parent(tree.nodes[2]).data<<endl;
//     cout<<"-----Childs-----"<<endl;
//     int * childs = tree.Childs(1);
//     for(int i=1;i<=childs[0];i++){
//         cout<<tree.nodes[childs[i]].data<<endl;
//     }
//     return 0;
// }