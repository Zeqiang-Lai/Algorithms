
void insertsort(int * a, int s, int n)
{
    int i,j,temp;
    for(i=s;i<s+n;i++){
        temp = a[i];
        for(j=i-1;j>=s && a[j] > temp;j--) a[j+1]=a[j];
        a[j+1] = temp;
    }
}