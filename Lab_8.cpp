#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{

 
    // Initialize largest as root
    int large = root;
 
    // left = 2*i + 1
    int l = 2 * root + 1;
 
    // right = 2*i + 2
    int r = 2 * root + 2;
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[large])
        large = l;
 
    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[large])
        large = r;
 
    // If largest is not root
    if (large != root) {
        swap(arr[root], arr[large]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, large);
    }
}
  
  
// implementing heap sort
void heapSort(int arr[], int n)
{

 
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
   
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{   
    
    int length;
    cout<<"Enter the length of the array ";
    cin >> length;
    
    
   int heap_arr[length];
   for(int i = 0 ; i < length ; i++){
       cin >> heap_arr[i];
       
   }
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr,n);
}
