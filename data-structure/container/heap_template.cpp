#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Heap
{
    vector<T> data;

  public:
    Heap() {}
    bool add(T x);
    int remove();
    bool empty() { return data.empty(); }
};

template<typename T>
bool Heap<T>::add(T x)
{
    data.push_back(x);
    int i = data.size()-1, fa;
    while(i > 0) {
        fa = (i+1)/2 - 1;
        if(data[fa] > data[i]) {
            swap(data[fa], data[i]);
            i = fa;
        } else break;
    }
    return true;
}

template<typename T>
int Heap<T>::remove()
{
    T val = data[0];
    data[0] = data.back();
    data.pop_back();
    int i = 0, j = 2*(i+1) - 1;
    while(j < data.size()) {
        if(j+1 < data.size() && data[j] > data[j+1]) j++;
        if(data[i] > data[j]) {
            swap(data[i],data[j]);
            i = j; j = 2*(i+1) - 1;
        } else break;
    }
    return val;
}

int main()
{
    Heap<int> a;
    a.add(1);
    a.add(5);
    a.add(3);
    a.add(2);
    while(!a.empty()){
        cout << a.remove() << endl;
    }
}