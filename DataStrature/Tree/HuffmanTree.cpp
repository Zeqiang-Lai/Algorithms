/*
哈夫曼树用三叉链表树实现
*/
#include<iostream>
using namespace std;

struct Node{
    int weight;   // 节点数据
    int lc,rc,parent;   // 左孩子，右孩子,父亲
};

class HuffmanTree{
private:
    Node * HT;
    char ** HC;
    int num;
    void selectMin(int n, int &s1, int &s2){
        s1 = 0; s2 = 0;
        for(int i=1;i<=n;i++){
            if(HT[i].parent != 0) continue;
            if(HT[i].weight < HT[s1].weight || s1 == 0) s1 = i;
        }
        for(int i=1;i<=n;i++){
            if(HT[i].parent != 0 || i == s1) continue;
            if(HT[i].weight < HT[s2].weight || s2 == 0) s2 = i;
        }
    }

public:
    // w 每个字符权值, n 字符数量
    void HuffmanCoding(int * w, int n){
        if(n <= 1) return;
        num = n;
        int m = 2*n-1;  // Huffman树的节点数
        HT = new Node[m+1]; // 0号不用
        for(int i=1;i<=n;i++){
            HT[i].weight = w[i];
            HT[i].lc = HT[i].rc = HT[i].parent = 0;
        }
        for(int i=n+1;i<=m;i++){
            HT[i].weight = 0;
            HT[i].lc = HT[i].rc = HT[i].parent = 0;            
        }
        // 建树
        for(int i=n+1;i<=m;i++){
            int s1,s2;
            selectMin(i-1,s1,s2);
            // printf("%d %d\n",HT[s1].weight,HT[s2].weight);
            HT[s1].parent = HT[s2].parent = i;
            HT[i].lc = s1; HT[i].rc = s2;
            HT[i].weight = HT[s1].weight + HT[s2].weight;
        }
        // 根据树求编码
        HC = new char*[n+1];
        char * temp = new char[n];  // n长度肯定够
    
        temp[n-1] = '\0';
        for(int i=1;i<=n;i++){
            int start = n-1;
            int c,f;
            for(c = i, f = HT[i].parent; f!=0; c=f,f=HT[f].parent)
                if(HT[f].lc == c) temp[--start] = '0';
                else temp[--start] = '1';
            HC[i] = new char[n-start];
            for(int j=start; j<n; j++)
                HC[i][j-start] = temp[j];
        }
        delete []temp;
    }

    void decoding(){

    }
    void display()
    {
        for(int i=1;i<=num;i++)
            printf("%s\n",HC[i]);
    }
};


int main()
{
    int n;
    cin>>n;
    int w[100];
    for(int i=1;i<=n;i++)
        cin>>w[i];
    HuffmanTree T;
    T.HuffmanCoding(w,n);
    T.display();
    return 0;
}