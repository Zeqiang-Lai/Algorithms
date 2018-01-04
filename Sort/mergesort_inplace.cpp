
#include "insertsort.cpp"
#define MINLEN 10

inline void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int *a, int n){
    int i=0,j=n-1;
    while(i<j) swap(a[i++],a[j--]);
}

void exchange(int *a, int lo, int mid, int hi)
{
    reverse(a+lo,mid-lo);
    reverse(a+mid,hi-mid+1);
    reverse(a+lo,hi-lo+1);
}

void merge(int *a, int lo, int mid, int hi)
{
    int i=lo, j=mid+1, k;
    while(i < j && j<=hi){
        while(a[i] <= a[j] && i<j) i++;
        k = j;
        while(a[j] <= a[i] && j<=hi) j++;
        exchange(a,i,k,j-1);
        i += j-k;
    }
}

void merge_sort(int *a, int lo, int hi)
{
    if(hi - lo < MINLEN) insertsort(a,lo,hi-lo+1);
    else{
        int mid = (lo+hi)/2;
        merge_sort(a,lo,mid);
        merge_sort(a,mid+1,hi);
        merge(a,lo,mid,hi);
    }
}

void mergesort_inplace(int * a, int n)
{
    // printf("mergesort\n");
    merge_sort(a,1,n);
}