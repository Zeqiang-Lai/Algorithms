/*
AC自动机
g++ ac_automaton.cpp -o ac_automaton -std=c++11

date: 2020-1-25
blog: https://zeqiang-lai.github.io/Algorithms/AC自动机.html
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class AcNode {
public:
    AcNode* m_childs[26] = { nullptr };
    bool m_is_end;  // 是否是单词边界
    char m_c;
    
    // 新增:
    AcNode* fail = nullptr;

    // 可选:
    int str_size;    // 存储该节点对应的字符串的长度

    AcNode(char c) {
        m_c = c;
        m_is_end = false;
    }
};

class ACAutomaton{
public:
    ACAutomaton() {
        root = new AcNode(' ');
    }
    
    void insert(string word) {
        AcNode* node = root;
        char c;
        for(int i=0; i<word.size(); i++) {
            c = word[i] - 'a';
            if(node->m_childs[c] == NULL) {
                node->m_childs[c] = new AcNode(c);
            }
            node = node->m_childs[c];
        }
        node->m_is_end = true;
        node->str_size = word.size();
    }

    void build() {
        queue<AcNode*> q;
        for(int i=0; i<26; i++) {
            if(root->m_childs[i] != NULL) {
                root->m_childs[i]->fail = root;
                q.push(root->m_childs[i]);
            } else { root->m_childs[i] = root; }
        }
        AcNode* current;
        while(!q.empty()) {
            current = q.front();
            q.pop();
            for(int i=0; i<26;i ++) {
                if(current->m_childs[i] != NULL) {
                    current->m_childs[i]->fail = current->fail->m_childs[i];
                    q.push(current->m_childs[i]);
                } else {
                    current->m_childs[i] = current->fail->m_childs[i]; // 路径压缩
                }
            }
        }
    }

    vector<vector<int> > query(const string& s) {
        vector<int> pos, size;
        vector<vector<int> > ans;
        ans.push_back(pos);
        ans.push_back(size);

        if(s.size() == 0) return ans;
        AcNode* node = root->m_childs[s[0]-'a'];
        for(int i=1; i<s.size(); i++) {
            node = node->m_childs[s[i]-'a'];
            for(AcNode* tmp=node; tmp&&tmp->m_is_end; tmp=tmp->fail) {
                ans[0].push_back(i);
                ans[1].push_back(tmp->str_size);
            }
        }
        return ans;
    }
protected:
    AcNode* root;
};

void printResult(string s, vector<vector<int> > ans)
{
    for(int i=0; i<ans[0].size(); i++) {
        cout << s << endl;
        for(int k=0; k<ans[0][i]-ans[1][i]+1; k++)
            cout << " ";
        for(int k=0; k<ans[1][i]; k++)
            cout << s[ans[0][i]-ans[1][i]+k+1];
        cout << endl;
    }
}

int main() 
{
    ACAutomaton automaton;
    cout << "start" << endl;
    automaton.insert("she");
    automaton.insert("he");
    automaton.insert("her");
    automaton.insert("his");
    automaton.insert("him");
    automaton.build();
    cout << "built" << endl;
    string s = "sherhim";
    vector<vector<int> > ans = automaton.query(s); // she,he,her,him
    cout << ans[0].size() << endl;
    printResult(s, ans);
}
// s   h
// h  e  i
// e  r  s m