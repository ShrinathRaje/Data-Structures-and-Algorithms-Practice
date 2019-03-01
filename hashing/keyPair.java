/* key pair */
/* Date: 1st Mar 2019 */
/* Author: Shrinath Bhosale */
/* problem statement: https://practice.geeksforgeeks.org/problems/key-pair/0 */

import java.util.Scanner;

class GFG {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            int sum = sc.nextInt();
            int [] arr = new int[n];
            for(int i=0; i<n; ++i)
                arr[i] = sc.nextInt();

            System.out.println(pairExists(arr,sum));
        }
    }

    public static String pairExists(int []a, int sum) {
        int l = a.length;
        int []h = new int[100001];

        for(int i=0; i<l; ++i) {
            int temp = sum - a[i];
            if(temp > 0 && h[temp] == 1) {
                return "Yes";
            }
            h[a[i]] = 1;
        }
        return "No";
    }
}
