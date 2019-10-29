/*
* Monk and Chamber of Secrets
* Date: 29th Oct 2019
* Author: Shrinath Bhosale
* Problem Statement: https://www.hackerearth.com/practice/data-structures/queues/basics-of-queues/practice-problems/algorithm/monk-and-chamber-of-secrets/description/
*/


import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Spider {
    int p;
    int i;
}

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();

        Queue<Spider> queue = new LinkedList<>();

        for(int i=1; i<=n; ++i) {
            int p = scanner.nextInt();

            Spider s = new Spider();
            s.p = p;
            s.i = i;

            queue.add(s);
        }

        Queue<Spider> temp = new LinkedList<>();
        for(int i=0; i<x; ++i) {
            int max = -1;
            int max_index = -1;
            for(int j=0; j<x; ++j) {
                if(!queue.isEmpty()) {
                    Spider s = queue.remove();
                    if(s.p > max) {
                        max = s.p;
                        max_index = s.i;
                    }

                    temp.add(s);
                }
            }

            while(!temp.isEmpty()) {
                Spider s = temp.remove();
                if(s.i != max_index) {
                    if(s.p != 0) {
                        --s.p;
                    }
                    queue.add(s);
                } else {
                    System.out.print(s.i + " ");
                }
            }
        }
    }
}

