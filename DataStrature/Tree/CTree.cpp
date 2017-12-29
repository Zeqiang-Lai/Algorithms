/*
树的孩子表示法
*/

#include<iostream>
using namespace std;
#define MAXN 100

struct CTNode{
    int child;
    CTNode * next;
    CTNode(int c) : child(c),next(NULL) {}
};
struct CTBox{
    char data;
    int parent;
    CTNode * fchild;    // 第一个不存信息
};
class CTree{
public:
    CTBox nodes[MAXN];
    int n,r;    // 节点树，根的位置

    CTree(){n = r = 0;}
    void init(){
        cout<<"number of nodes and position of root"<<endl;
        cin>>n>>r;
        for(int i=0;i<n;i++){
            cin>>nodes[i].data>>nodes[i].parent;
            nodes[i].fchild = new CTNode(-1);
        }
        cout<<"Please enter the position of the childs of the following node"<<endl;
        for(int i=0;i<n;i++){
            cout<<nodes[i].data<<endl;
            int m,index;
            cout<<"numbers of childs"<<endl;
            cin>>m;
            if(m > 0) {
                CTNode *temp = nodes[i].fchild;
                for(int j=0;j<m;j++){
                    cin>>index;
                    temp->next = new CTNode(index);
                    temp = temp->next;
            }
            }
        }
    }
    CTBox& Parent(CTBox& node){
        return nodes[node.parent];
    }
    CTBox& Root(){
        return nodes[r];
    }
    void Childs(CTBox& node){
        cout<<"---childs----"<<endl;
        CTNode * temp = node.fchild;
        while(temp->next != NULL){
            temp = temp->next;
            cout<<nodes[temp->child].data<<endl;
        }
    }
};

int main()
{
    CTree tree;
    tree.init();
    tree.Childs(tree.nodes[0]);
    return 0;
}