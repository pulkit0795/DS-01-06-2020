//Quick sort
//Pulkit Goyal(11912066[IT])

#include<stdio.h>
#include<stdlib.h>

void swap(int *p,int *q)
{
       int temp=*p;
	*p=*q;
	*q=temp;
}
int partition(int *a,int lb,int ub)
{
   int pivot=a[lb];
   int start=lb;
   int end=ub;
    while(start<end) {
       while((a[start]<=pivot)&&(start<=ub)) {
          start++;
       }
       while((a[end]>pivot)&&(end>=lb)) {
         end--;
       }
       if(start<end) {
          swap(&a[start],&a[end]);
       }
     }

     swap(&a[lb],&a[end]);
     return end;
}

void quicksort(int *a,int lb,int ub)
{
   if(lb<ub) {
      int local=partition(a,lb,ub);
      quicksort(a,lb,local-1);
      quicksort(a,local+1,ub);
   }
}

int main()
{
   int *a;
   int  n;
   printf("Enter the size of Array: ");
   scanf("%d",&n);
   a=(int *)malloc(n*sizeof(int));
   printf("Enter teh elements: ");
   for(int y=0;y<=n-1;y++) {
	   scanf("%d",&a[y]);
   }
   quicksort(a,0,n-1);
   printf("\nThe sorted array is:\n");
   for(int x=0;x<n;x++) {
     printf(" %d",a[x]);
   }
}

