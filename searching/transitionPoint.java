/* find transition point */
/* Date: 12 Feb 2019 */
/* Author: Shrinath Bhosale */
/* problem statement: https://practice.geeksforgeeks.org/problems/find-transition-point/1 */


// function problem: Array will be passed to the transitionPoint method */
class GfG
{
	private static int index = -1;
    
    private static int search(int []arr, int l, int r) {
        if(l > r)
            return index;
            
        int mid = l + (r-l)/2;
        
        if(arr[mid] == 1) {
            index = mid;
            return search(arr, l, mid - 1);
        } else {
            return search(arr, mid+1, r);
        }
    }
    
	int transitionPoint(int arr[],int n)
	{
        return search(arr, 0, n-1);
    } 
}
