/*
Trie树
g++ trie.cpp -o trie -std=c++11

date: 2020-1-24
blog: https://zeqiang-lai.github.io/Algorithms/trie树.html
*/

#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* m_childs[26] = { nullptr };
    bool m_is_end;  // 是否是单词边界
    char m_c;

    TrieNode(char c) {
        m_c = c;
        m_is_end = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }
    
    void insert(string word) {
        TrieNode* node = root;
        char c;
        for(int i=0; i<word.size(); i++) {
            c = word[i] - 'a';
            if(node->m_childs[c] == NULL) {
                node->m_childs[c] = new TrieNode(c);
            }
            node = node->m_childs[c];
        }
        node->m_is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = searchNode(word);
        if(node == NULL) return false;
        else return node->m_is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = searchNode(prefix);
        return !(node == NULL);
    }

    TrieNode* searchNode(string prefix) {
        TrieNode* node = root;
        char c;
        for(int i=0; i<prefix.size(); i++) {
            c = prefix[i] - 'a';
            if(node->m_childs[c] == NULL) return NULL;
            node = node->m_childs[c];
        }
        if(node == root) return NULL;
        else return node;
    }
protected:
    TrieNode* root;
};

int main()
{
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 返回 true
    cout << trie.search("app") << endl;   // 返回 false
    cout << trie.startsWith("app") << endl; // 返回 true
    trie.insert("app");   
    cout << trie.search("app") << endl;     // 返回 true

    return 0;
}