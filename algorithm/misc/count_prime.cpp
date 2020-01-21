/*
筛法求素数
g++ count_prime.cpp -o count_prime -std=c++11

blog: https://zeqiang-lai.github.io/Algorithms/%E7%AD%9B%E6%B3%95%E6%B1%82%E7%B4%A0%E6%95%B0.html
date: 2020-1-21
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> countPrimes(int n) {
    vector<bool> vis(n,false);
    vector<int> prime;

    for(int i=2;i<n;i++){
        if(!vis[i]) prime.push_back(i);
        for(int j=0;j<prime.size() && i*prime[j]<=n;j++){
            vis[i*prime[j]] = true;
            if(i%prime[j] == 0) break;	//优化
        }
    }
    return prime;
}

int main()
{
    vector<int> primes = countPrimes(1000);
    for(int a : primes) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}