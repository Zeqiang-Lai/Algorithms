
inline void swap(int &a, int &b){
    int temp = a;
    a = b; b = temp;
}

int median3(int *a, int lo, int hi)
{
    int mid = (lo+hi)/2;
    if(a[lo] > a[mid]) swap(a[lo],a[mid]);
    if(a[lo] > a[hi]) swap(a[lo],a[hi]);
    if(a[mid] > a[hi]) swap(a[mid],a[hi]);
    swap(a[lo],a[mid]);
    return a[lo];
}

int partition(int *a, int lo, int hi)
{
    int i=lo, j=hi;
    int pivot = median3(a,lo,hi);
    while(i<j){
        while(a[j] >= pivot && j>i) j--;
        a[i] = a[j];
        while(a[i] <= pivot && i<j) i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}
void sort(int *a, int lo, int hi)
{
    if(lo < hi){
        int mid = partition(a,lo,hi);
        sort(a,lo,mid-1);
        sort(a,mid+1,hi);
    }
}

void quicksort(int * a, int n)
{
    sort(a,0,n-1);
}