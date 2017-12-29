/*
顺序二叉树，用数组实现,适用于完全二叉树
左孩子2i，右孩子2i+1
*/

#include<iostream>
using namespace std;
#define MAXN 100

int tree[MAXN];

int main()
{
    tree[0] = 1;    //根节点
    int root = 1;
    tree[root*2] = 2 // 根的左孩子置为2
    tree[root*2+1] = 3 // 根的右孩子置为3
    return 0;
}