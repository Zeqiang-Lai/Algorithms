/*
堆排序, 方便起见，下标从1开始
*/

// 调整第i个元素,最后一个元素为a[n]
void sift(int * a, int x, int n)
{
    int i=x, j=x*2;
    while(j <= n){
        if(a[j] > a[j+1]) j++;  // 取左右孩子较小者
        if(a[i] > a[j]){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j; j=i*2;
        }else break;
    }
}
void heapsort(int * a, int n)
{
    for(int i=n/2;i>=1;i--)
        sift(a,i,n);
    int *temp;
    temp = new int[n];
    for(int i=1;i<=n;i++){
        temp[i] = a[1];
        a[1] = a[n-i+1];
        sift(a,1,n-i);
    }
    for(int i=1;i<=n;i++)
        a[i] = temp[i];
    delete []temp;
}