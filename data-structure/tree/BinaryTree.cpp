/*
二叉树，二叉链表实现
*/

#include<iostream>
using namespace std;

struct Node{
    int data;   // 节点数据
    Node *lc,*rc;   // 左孩子，右孩子
    Node(int x, Node *l=NULL, Node *r= NULL) : data(x),lc(l),rc(r) {}
};

class BTree{
public:
    Node *root; 
    
public:
    BTree(){}
    void CreateTree(Node *& now){
        int x;
        cout<<"Root:";
        cin>>x; 
        if(x==0) return;
        now = new Node(x);
        CreateTree(now->lc);
        CreateTree(now->rc);
    }

    int PreTraverse(Node *node, void (*visit) (Node *)){
        visit(node);
        if(node->lc != NULL) PreTraverse(node->lc,visit);
        if(node->rc != NULL) PreTraverse(node->rc,visit);
        return 1;
    }

    int InTraverse(Node *node, void (*visit) (Node *)){
        if(node->lc != NULL) InTraverse(node->lc,visit);
        visit(node);
        if(node->rc != NULL) InTraverse(node->rc,visit);
        return 1;
    }

    int PostTraverse(Node *node, void (*visit) (Node *)){
        if(node->lc != NULL) PostTraverse(node->lc,visit);
        if(node->rc != NULL) PostTraverse(node->rc,visit);
        visit(node);
        return 1;
    }
};

/*
演示二叉树如下
    1
  2   3
4  5 6 7

input : 1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
*/

void visit(Node * node)
{
    cout<<node->data<<" ";
}

int main()
{
    BTree tree;
    tree.CreateTree(tree.root);
    tree.PreTraverse(tree.root,visit);cout<<endl;
    tree.InTraverse(tree.root,visit);cout<<endl;
    tree.PostTraverse(tree.root,visit);cout<<endl;
    return 0;   
}