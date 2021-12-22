/* Solution to Problem 1 */

import java.io.*;
import java.util.*;
class RituBday{

    // Method to find ChocoBox
    static int ChocoBox(int[] A, int[] B)
    {
        int n = A.length;
        int m = B.length;
        if (n > m)
            return ChocoBox(B, A); // Swapping to make A smaller
 
        int start = 0;
        int end = n;
        int realmidinmergedarray = (n + m + 1) / 2;
 
        while (start <= end) {
            int mid = (start + end) / 2;
            int leftAsize = mid;
            int leftBsize = realmidinmergedarray - mid;
            int leftA
                    = (leftAsize > 0)
                    ? A[leftAsize - 1]
                    : Integer.MIN_VALUE; // checking overflow of indices
            int leftB = (leftBsize > 0) ? B[leftBsize - 1] : Integer.MIN_VALUE;

            int rightA = (leftAsize < n) ? A[leftAsize] : Integer.MAX_VALUE;

            int rightB = (leftBsize < m) ? B[leftBsize] : Integer.MAX_VALUE;
 
            // To check if correct partition is done
            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 0)
                    return (Math.max(leftA, leftB)
                            + Math.min(rightA, rightB))
                            / 2;
                return Math.max(leftA, leftB);
            }
        else if (leftA > rightB) {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return 0;
    }
 

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);

        //Taking input of n
        int n = sc.nextInt();

        //Creating an array for Pile A
        int[] a = new int[n];
        
        // Taking Input of weights of boxes in Pile A 
        for(int i=0;i<n;i++){ 
            a[i] = sc.nextInt();
        }
        
        //Taking input of m
        int m = sc.nextInt(); //Taking input of m

        //Creating an array for Pile B
        int[] b = new int[m];


        // Taking Input of weight of boxes in Pile B
        for(int i=0;i<m;i++){ 
            b[i] = sc.nextInt();
        }

        System.out.println(ChocoBox(a,b));
    }
}