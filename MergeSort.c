#include <stdio.h>
#include<conio.h>
  
void mergesort(int arr[], int l, int h);
  
void main(void) 
{
 int array[100],n,i = 0; 
 printf("Enter the number of elements to be sorted: ");
 scanf("%d",&n);
 printf("\nEnter the elements to be sorted: \n");
 for(i = 0 ; i < n ; i++ )
 {
  printf("\tArray[%d] = ",i);
  scanf("%d",&array[i]);
 }
  
  
 printf("\nBefore Mergesort:");  
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
  
 mergesort(array, 0, n - 1); 
 
 printf("\nAfter Mergesort:"); 
 for(i = 0; i < n; i++)
 {
  printf("%4d", array[i]);
 }
 printf("\n");
 getch();
}
  
void mergesort(int arr[], int l, int h) 
{
 int i = 0;
 int length = h - l + 1;
 int x = 0;
 int merge1 = 0;
 int merge2 = 0;
 int temp[100];
  
 if(l == h)
 return;
  
 x  = (l + h) / 2;
  
 mergesort(arr, l, x);
 mergesort(arr, x + 1, h);
   
 for(i = 0; i < length; i++)
 {
  temp[i] = arr[l + i];
 }
  
 merge1 = 0;
 merge2 = x - l + 1;
  
 for(i = 0; i < length; i++) 
 {
  if(merge2 <= h - l)
  {
   if(merge1 <= x - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     arr[i + l] = temp[merge2++];
    }
 
    else
    {
     arr[i + l] = temp[merge1++];
    }
   }
 
   else
   {
    arr[i + l] = temp[merge2++];
   }
  }
 
  else
  {
   arr[i + l] = temp[merge1++];
  }
 }
}