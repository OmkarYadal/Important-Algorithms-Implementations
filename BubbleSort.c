#include<stdio.h>
#define size 100
void swap(int *,int *);
void bubble(int [],int);
void print(int [],int);

int main() {
    int a[size],n,i;
    printf("Enter the total number of the elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    bubble(a,n);
    print(a,n);
    return 0;
}
void swap(int *a,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble(int a[],int n) {
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
                swap(&a[j],&a[j+1]);
        }
    }
}
void print(int a[],int n) {
    int i;
    printf("The sorted array is\n");
    for(i=0; i<n; i++)
        printf("%d\n",a[i]);
}
