/* Non Repeating Character */
/* Date: 2nd Mar 2019 */
/* Author: Shrinath Bhosale */
/* problem statement: https://practice.geeksforgeeks.org/problems/non-repeating-character/0 */

import java.util.Scanner;

class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while(t-- > 0) {
            int []h = new int[26];
            int n = scanner.nextInt();
            scanner.nextLine(); //consume trailing newline character
            String s = scanner.nextLine();
            for(int i=0; i<n; ++i) {
                ++h[s.charAt(i) - 'a'];
            }

            boolean found = false;
            for(int i=0; i<n; ++i) {
                if(h[s.charAt(i) - 'a'] == 1) {
                    System.out.println(s.charAt(i));
                    found = true;
                    break;
                }
            }

            if(!found)
                System.out.println(-1);
        }
    }
}
