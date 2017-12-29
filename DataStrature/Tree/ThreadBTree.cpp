/*
线索二叉树
前序线索树，中序线索树，后续线索树
*/

#include<iostream>
using namespace std;

enum Tag{Link, Thread};

struct Node{
    int data;   // 节点数据
    Tag ltag,rtag;  // 标志指针为线索还是指向
    Node *lc,*rc,*parent;   // 左孩子，右孩子,父亲
    Node(int x, Node *l=NULL, Node *r= NULL,Node *p=NULL) : data(x),lc(l),rc(r),parent(p) {}
};

class ThreadBTree{
private:
    Node *pre;
    void PreThreading(Node *p){
        if(p){
            if(p->lc == NULL){
                p->lc = pre;
                p->ltag = Thread;
            }
            if(pre && pre->rc == NULL){
                pre->rc = p;
                pre->rtag = Thread;
            }
            pre = p;
            if(p->ltag == Link) PreThreading(p->lc);
            if(p->rtag == Link) PreThreading(p->rc);
        }
    }
    void InThreading(Node *p){
        if(p){
            InThreading(p->lc);
            if(!p->lc){p->ltag = Thread; p->lc = pre;}
            if(!pre->rc) {pre->rtag = Thread; pre->rc = p;}
            pre = p;
            InThreading(p->rc);
        }
    }
    void PostThreading(Node *p){
        if(p){
            PostThreading(p->lc);
            PostThreading(p->rc);
            if(p->lc == NULL){
                p->lc = pre;
                p->ltag = Thread;
            }
            if(pre && pre->rc == NULL){
                pre->rc = p;
                pre->rtag = Thread;
            }
            pre = p;
        }
    }

public:
    Node *root, *thrt; 
    
public:
    ThreadBTree(){}
    void CreateTree(Node *& now,Node *& p){
        int x;
        cout<<"Root:";
        cin>>x; 
        if(x==0) return;
        now = new Node(x);
        now->ltag = now->rtag = Link;
        now->parent = p;
        CreateTree(now->lc,now);
        CreateTree(now->rc,now);
    }
    // 前序遍历线索化
    int PreOrderThreading(){
        PreThreading(root);
        return 1;
    }

    // 中序遍历线索化
    int InOrderThreading(){
        thrt = new Node(0);
        thrt->ltag = Link; thrt->rtag = Thread;
        thrt->rc = thrt;
        if(!root) thrt->lc = thrt;
        else{
            thrt->lc = root; pre = thrt;
            InThreading(root);
            pre->rtag = Thread; pre->rc = thrt;
            thrt->rc = pre;
        }
        return 1;
    }
    // 后序遍历线索化
    int PostOrderThreading(){
        PostThreading(root);
        return 1;
    }

// 线索化遍历方式
    int PreTraverse_Thr(void (*visit)(Node *)){
        if(root){
            Node *p = root;
            pre = NULL;
            while(p != NULL){
                // 先访问左子树
                while(p->lc != NULL && p->ltag == Link){
                    visit(p); p = p->lc;
                }
                visit(p);
                // 根据线索访问右子树
                while(p && p->rtag == Thread){
                    p = p->rc; visit(p);
                }
                // 若右子树有左子树，访问左子树，否则访问右子树
                if(p->ltag == Link) p = p->lc;
                else p = p->rc;
            }
        }
        return 1;
    }
    int InTraverse_Thr(void (*visit)(Node*)){
        if(thrt == NULL) return 0;
        Node * p = root;
        while(p != thrt){
            while(p->ltag == Link) p = p->lc;
            visit(p);
            while(p->rtag == Thread && p->rc != thrt){
                p = p->rc; visit(p);
            }
            p = p->rc;
        }
        return 1;
    }
    int PostTraverse_Thr(void (*visit)(Node*)){
        if(root){
            Node *p = root;
            pre = NULL;
            while(p != NULL){
                while(p->lc != pre && p->ltag == Link) p = p->lc;
                while(p && p->rtag == Thread){
                    visit(p); pre=p; p=p->rc;
                }
                if(p == root) visit(p);
                while(p && p->rc == pre){
                    visit(p); pre=p; p=p->parent;
                }
                if(p && p->rtag == Link) p = p->rc;
            }
        }
        return 1;
    }

// 原始遍历方式
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
    ThreadBTree tree;
    Node * temp = NULL;
    tree.CreateTree(tree.root,temp);
    // 前序遍历
    tree.PreTraverse(tree.root,visit);cout<<endl;
    tree.PreOrderThreading();
    tree.PreTraverse_Thr(visit);cout<<endl;

    // 中序遍历
    // tree.InTraverse(tree.root,visit);cout<<endl;
    // tree.InOrderThreading();
    // tree.InTraverse_Thr(visit);cout<<endl;

    // 后序遍历
    // tree.PostTraverse(tree.root,visit);cout<<endl;   
    // tree.PostOrderThreading();
    // tree.PostTraverse_Thr(visit);cout<<endl;

    return 0;   
}