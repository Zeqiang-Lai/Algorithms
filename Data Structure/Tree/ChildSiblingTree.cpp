/*
树的孩子兄弟表示法
child and sibling
*/

#include<iostream>
using namespace std;
#define MAXN 100

struct CSNode{
    char data;
    CSNode *fchild,*nsibling;
};
class CSTree{
private:
    void Input(CSNode *& node){
        node = new CSNode();
        int check;
        cout<<"enter the data of the node(char)"<<endl;
        cin>>node->data;
        cout<<"if this node has a child? (yes 1/ no 0)"<<endl;
        cin>>check;
        if(check) Input(node->fchild);
        cout<<"if this node has a sibling? (yes 1/ no 0)"<<endl;
        cin>>check;
        if(check) Input(node->nsibling);
    }
public:
    CSNode * root;
    
    CSTree(){ root = NULL;}
    void init(){
        Input(root);
    }

    CSNode* Root(){
        return root;
    }
    void Child(CSNode *node){
        CSNode * temp = node->fchild;
        cout<<temp->data<<endl;
        while(temp->nsibling != NULL){
            temp = temp->nsibling;
            cout<<temp->data<<endl;
        }
    }
    // 其他树的操作，如遍历
};

int main()
{
    CSTree tree;
    tree.init();
    cout<<tree.root->data<<endl;
    tree.Child(tree.root);
    return 0;
}