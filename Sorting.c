#include<stdio.h>
#define size 10
void sort(int [],int);

int main() {
    int a[size],n,i;
    printf("Enter the total number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("The sorted array is\n");
    for(i=0; i<n; i++)
        printf("%d\n",a[i]);
    return 0;
}

void sort(int a[],int n) {
    int i,temp,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
