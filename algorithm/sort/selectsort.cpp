inline void swap(int &a, int &b){
    int temp = a;
    a = b; b = temp;
}

void selectsort(int *a, int n)
{
    printf("selectsort\n");
    int argmin = 0;
    for(int i=0;i<n;i++){
        argmin = i;
        for(int j=i;j<n;j++)  
            if(a[j] < a[argmin]) argmin = j;
        swap(a[i],a[argmin]);
    }            
}