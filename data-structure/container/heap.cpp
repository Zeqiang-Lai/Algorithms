#include <iostream>
using namespace std;

class Heap
{
    int data[1000];
    int size;

    void sift();

  public:
    Heap() : size(0) {}
    bool add(int x);
    int remove();
    bool empty() { return size == 0; }
};

bool Heap::add(int x)
{
    if(size == 999) return false;
    data[++size] = x;
    int i = size;
    while(i > 1) {
        if(data[i/2] > data[i]) {
            swap(data[i/2], data[i]);
            i /= 2;
        } else break;
    }
    return true;
}

int Heap::remove()
{
    int val = data[1];
    data[1] = data[size--];
    int i = 1, j = 2*i;
    while(j <= size) {
        if(j+1 <= size && data[j] > data[j+1]) j++;
        if(data[i] > data[j]) {
            swap(data[i],data[j]);
            i = j; j = 2*i;
        } else break;
    }
    return val;
}

int main()
{
    Heap a;
    a.add(1);
    a.add(5);
    a.add(3);
    a.add(2);
    while(!a.empty()){
        cout << a.remove() << endl;
    }
}