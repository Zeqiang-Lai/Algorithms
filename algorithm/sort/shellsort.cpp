/*
希尔排序
通过大的增量 减少排序相距较远的两个元素的移动元素次数
在各个增量区间采用直接插入排序
*/
#define MAX_GAP 10

void shellsort(int * a, int n)
{
    int gaps[MAX_GAP] = {1,2,3,5,9};
    int num_gap = 5;
    for(int k=num_gap-1;k>=0;k--)
        for(int i=gaps[k];i<n;i++){
            int j, temp = a[i];
            for(j=i;j>=gaps[k] && a[j-gaps[k]] > temp; j-=gaps[k])
                a[j] = a[j-gaps[k]];
            a[j] = temp;
        }
}