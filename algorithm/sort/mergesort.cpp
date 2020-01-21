
#include "insertsort.cpp"
#define MINLEN 10

void merge(int *a, int lo, int mid, int hi)
{
    int * temp = new int[hi-lo+1];
    int i=lo,j=mid+1,num=0;
    while(i<=mid && j<=hi){
        if(a[i] <= a[j]) temp[num++] = a[i++];
        else temp[num++] = a[j++];
    }
    while(i<=mid) temp[num++] = a[i++];
    while(j<=hi) temp[num++] = a[j++];
    for(i=0;i<num;i++) a[lo+i] = temp[i];
    delete [] temp;
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

void mergesort(int * a, int n)
{
    // printf("mergesort\n");
    merge_sort(a,1,n);
}