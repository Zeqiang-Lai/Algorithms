
inline void swap(int &a, int &b){
    int temp = a;
    a = b; b = temp;
}

void bubblesort(int * a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
    }
}