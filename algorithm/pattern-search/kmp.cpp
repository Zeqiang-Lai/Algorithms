/*
KMP算法
g++ kmp.cpp -o kmp -std=c++11

test case 1: 
BBC ABCDAB ABCDABCDABDE
ABCDABD

blog: https://zeqiang-lai.github.io/Algorithms/kmp.html
date: 2020-1-21
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 优化
vector<int> get_next2_opt(const string& p) {
    vector<int> next(p.size());
    next[0] = -1;
    int i=0, k=-1;
    while(i < p.size() - 1) {
        if(k == -1 || p[i] == p[k]) {
            i++; k++;
            if(p[k] != p[i]) next[i] = k;
            else next[i] = next[k];
        } else { k = next[k]; }
    }
    return next;
}

vector<int> get_next2(const string& p) {
    vector<int> next(p.size());
    next[0] = -1;
    int i=0, k=-1;
    while(i < p.size() - 1) {
        if(k == -1 || p[i] == p[k]) {
            i++; k++;
            next[i] = k;
        } else { k = next[k]; }
    }
    return next;
}

vector<int> get_next_opt(const string& p) {
    vector<int> next(p.size());
    next[0] = -1;
    for(int i=1;i<p.size();i++){
        int k=i-1;
        while(k!=0 && p[i-1] != p[next[k]]) k=next[k];  // 先找出"OK"的前缀后缀
        if(p[i] != p[next[k]+1]) next[i] = next[k] + 1;
        else next[i] = next[next[k]+1];
    }
    return next;
}

vector<int> get_next(const string& p) {
    vector<int> next(p.size());
    next[0] = -1;
    for(int i=1;i<p.size();i++){
        int k=i-1;
        while(k!=0 && p[i-1] != p[next[k]]) k=next[k];  // 先找出"OK"的前缀后缀
        next[i] = next[k] + 1;
    }
    return next;
}

vector<int> get_next_vanilla(const string& p) {
    vector<int> next(p.size());
    next[0] = -1;
    for(int i=1; i<p.size(); i++) {
        int n_match = 0;
        // 枚举所有可能的相同前缀后缀
        for(int k=1; k<i; k++) {
            bool ok = true;
            for(int j=0; j<k; j++) {
                if(p[j] != p[i-k+j]) ok = false;
            }
            if(ok == true) n_match = k;
        }
        next[i] = n_match;
    }
    return next;
}

int find_kmp(const string& s, const string& p, vector<int>(*_get_next)(const string&)) {
    vector<int> next = _get_next(p);
    for(int x : next) {
        cout << x << " ";
    }
    cout << endl;
    int i=0, j=0;
    while(i < s.size() && j < p.size()) {
        if(s[i] == p[j]) { i++; j++; } 
        else {
            if(next[j] == -1) i++;  // 如果p[0]都不匹配, i要加1了
            else j = next[j]; 
        }
    }
    if(j == p.size()) return i-j;
    else return -1;
}

int find_vanilla(const string& s, const string& p) {
    int pos = -1;
    bool ok = true;
    for(int i=0; i<s.size(); i++) {
        ok = true;
        for(int j=0; j<p.size(); j++) {
            if(s[i+j] != p[j]) { ok = false; break; }
        }
        if(ok) { pos = i; break; }
    }
    return pos;
} 

int find_vanilla2(const string& s, const string& p) {
    int i=0, j=0;
    while(i < s.size() && j < p.size()) {
        if(s[i] == p[j]) { i++; j++; } 
        else { i=i-j+1; j=0; }
    }
    if(j == p.size()) return i-j;
    else return -1;
} 

string getline(int buffer_size=1024) {
    char buffer[buffer_size];
    cin.getline(buffer, buffer_size);
    string str(buffer);
    return str;
}

void printResult(string source, string pattern, int pos) {
    if(pos == -1) {
        cout << "could not find """ << pattern << """ in " << source << endl;
    } else {
        cout << "found """ << pattern << """ at " << pos << endl;
        cout << source << endl;
        for(int i=0; i<pos; i++) cout << " ";
        cout << pattern << endl;
    }
}

int main()
{
    string source = getline();
    string pattern = getline();
    // int pos = find_vanilla2(source, pattern);
    int pos = find_kmp(source, pattern, get_next_opt);
    printResult(source, pattern, pos);
    return 0;
}