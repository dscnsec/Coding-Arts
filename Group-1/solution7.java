
/*
Approach-
-finding non duplicate numbers
Time Complexity = O(n+m), where n is number of duo students and m is number of trio students.
Space Complexity =  O(1) + O(1) = O(1), no extra space is required
*/

import java.util.Scanner;

public class ProblemStatement7 {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] duoArray =new int[n];

        for(int i=0;i<n;i++) {
            duoArray[i] = sc.nextInt();
        }

        int m=sc.nextInt();
        int[] trioArray =new int[m];

        for(int i=0;i<m;i++) {
            trioArray[i] = sc.nextInt();
        }

           // for duo
           int singleNumber = 0;
            for (int i = 0; i < n; i++) {
                singleNumber = singleNumber ^ duoArray[i];
            }
            System.out.print(singleNumber + " ");

            // for trio
            int ones = 0;
            int twos = 0;
            for (int i = 0; i < m; i++) {
                ones = (ones ^ trioArray[i]) & ~twos;
                twos = (twos ^ trioArray[i]) & ~ones;
            }
            System.out.println(ones);
    }
}
