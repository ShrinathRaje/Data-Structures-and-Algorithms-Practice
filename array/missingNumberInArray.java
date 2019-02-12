/* find the missing number in an array */
/* Date: 12 Feb 2019 */
/* Author: Shrinath Bhosale */
/* problem statement: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0 */

import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int sumOfn = n * (n + 1) / 2;
            int sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += sc.nextInt();
            }
            System.out.println(sumOfn - sum);
        }

    }
}
