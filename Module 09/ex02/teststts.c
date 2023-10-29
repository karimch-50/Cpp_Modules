#include <stdio.h>
 
// Function that returns 0 if a pair
// is found unsorted
int arraySortedOrNot(int arr[], int n)
{
    // Array has one or no element or the
    // rest are already checked and approved.
    if (n == 1 || n == 0)
        return 1;
 
    // Unsorted pair found (Equal values allowed)
    if (arr[n - 1] < arr[n - 2])
        return 0;
 
    // Last pair was sorted
    // Keep on checking
    return arraySortedOrNot(arr, n - 1);
}
 
// Driver code
int main()
{
    int arr[] = { 34 ,84 ,158 ,166 ,191 ,246 ,275 ,404 ,452 ,587 ,630 ,664 ,\
	 679 ,746 ,767 ,829 ,836 ,899 ,907 ,984 ,926};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (arraySortedOrNot(arr, n))
        printf("Yes\n");
    else
        printf("No\n");
 
    return 0;
}
