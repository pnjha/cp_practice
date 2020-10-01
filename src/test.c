#include <stdio.h> 
  
int fun(int *ptr) 
{ 
   int x = 10; 
  
   // size of a pointer is printed 
   printf("sizeof(ptr) = %d\n", sizeof(ptr)); 
  
   // This allowed because ptr is a pointer, not array 
   int arr1[] = {10, 20, 30, 40, 50, 60};
   ptr = arr1; 
  
   printf("*ptr = %d \n", *ptr); 
  
   return 0; 
} 
// Driver code 
int main(){
 
   int arr[] = {10, 20, 30, 40, 50, 60}; 
   fun(arr); 
   return 0; 
} 
