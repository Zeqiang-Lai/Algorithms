#include "PTree.cpp"

class MFSet : public PTree{
public:
    /*
    输入说明： n 集合中元素个数
        循环1: 分别输入n个元素的数据
        循环2: a，b 表示第a个元素和第b个元素等价
    */
    void init(){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>nodes[i].data;
            nodes[i].parent = -1; 
        }
        // 表示等价关系的有序对
        int m,a,b;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            a = fix(a); b = fix(b);
            mix(a,b);
        }
    }
    int fix(int i){
        if(i < 1 || i > n) return -1;
        int j,k,t;
        for(j=i; nodes[j].parent>0; j=nodes[j].parent);
        for(k=i; k!=j; k=t){
            t=nodes[k].parent; nodes[k].parent=j;
        }// 把路上的所有节点都指向最老的爸爸
        return j;
    }
    void mix(int i, int j){
        if(i<1 || i>n || j<1 || j> n) return;
        if(nodes[i].parent > nodes[j].parent){
            nodes[j].parent += nodes[i].parent;
            nodes[i].parent = j;
        }else{
            nodes[i].parent += nodes[j].parent;
            nodes[j].parent = i;
        }
    }
};

int main()
{
    MFSet s;
    cout<<"hello"<<endl;
    /*
    输入： 1 2 3 4 5 6
    等价类 134 256
    */
    s.init();
    int a,b;
    cout<<"Init Finished"<<endl;
    int n;
    cout<<"Query times:";
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(s.fix(a) == s.fix(b)) cout<<"Same"<<endl;
        else cout<<"Different"<<endl;
    }
    return 0;
}