#include <stdio.h>
#include <stdlib.h>
 
typedef long long ll; 
 
int temp[100000]; 
 
ll  _mergeSort(int arr[], int temp[], int left, int right,int k);
ll merge(int arr[], int temp[], int left, int mid, int right, int x);
 
/* This function sorts the input array and returns the
   number of inversions in the array */
ll mergeSort(int arr[], int array_size, int k)
{
    return _mergeSort(arr, temp, 0, array_size - 1,k);
}
 
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
ll _mergeSort(int arr[], int temp[], int left, int right, int k)
{
  int mid;
  ll inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
 
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid,k);
    inv_count += _mergeSort(arr, temp, mid+1, right,k);
 
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right,k);
  }
  return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
ll merge(int arr[], int temp[], int left, int mid, int right, int x)
{
  int i, j, k;
  ll inv_count = 0;
 
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i*x] <= arr[j*x])
    {
        temp[k] = arr[i*x];
      k++;
      i++;
    }
    else
    {
      temp[k++] = arr[x*(j++)];
 
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
 
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[x*(i++)];
 
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[x*(j++)];
 
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[x*i] = temp[i];
 
  return inv_count;
}

ll executa(int* arr, int tam, int k) {
    ll total = 0;
    for (int i = 0; i < k; i++) {
        total += mergeSort(arr+i, 1 + (tam-i-1)/k, k);
    }
    return total;
}

int arr[100000];
int N, K;

/* Driver progra to test above functions */
int main(int argv, char** args)
{
  int T;
  scanf("%d", &T);
  
  for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &K);
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }  
        
        ll inv = executa(arr, N, K);
        
        int prev = arr[0];
        bool imp = false;
        for (int i = 1; i < N; i++) {
            if (arr[i] < prev) {
                imp = true;
                break;
            }
        }
        
        if (imp) printf("impossivel\n");
        else printf("%lld\n", inv);
    } 
    
  return 0;
}
