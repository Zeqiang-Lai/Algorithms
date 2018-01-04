#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAXN 1000

void getnext(int *next, char b[], int len){
    next[0] = -1;

    // method 1
    // for(int i=1;i<len;i++){
    //     int k=i-1;
    //     while(k!=0 && b[i-1] != b[next[k]]) k=next[k];
    //     if(k == 0) next[i] = 0;
    //     else next[i] = next[k] + 1;
    // }

    // method 2
    int i=1,j=-1;
    while(i<len){
        if(j == -1 || b[i-1] == b[j]) {
            if(j == -1) next[i] = 0;
            else next[i] = j + 1;
            if(b[i] == b[j+1]) next[i] = next[j+1];
            i++;j++;
        }else j = next[j];
    }
}

int kmp(char a[], char b[]){
    int next[MAXN];
    int a_len = strlen(a), b_len = strlen(b);
    getnext(next,b,b_len);
    int i=0,j=0;
    while(i<a_len && j<b_len){
        if(j==-1 || a[i] == b[j]) {i++;j++;}
        else j = next[j];
    }
    if(j >= b_len) return i-b_len;
    return -1;
}

int main()
{
    char s[MAXN], subs[MAXN];
    std::cin>>s;
    std::cin>>subs;
    std::cout<<kmp(s,subs);
    return 0;
}