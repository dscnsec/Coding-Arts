//Solution to Problem 7

import java.util.*;
import java.io.*;

class RefRavi{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); //Input of number of students in duo race
        int[] a = new int[n]; //Data Structure to store the Heights of the Students for duo race
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            a[i] = Integer.parseInt(st.nextToken()); //Taking the heights as input for duo race
        }
        int m = Integer.parseInt(br.readLine()); //Input of number of students in trio race
        int[] b = new int[m]; //Data Structure to store the Heights of the Students for trio race
        StringTokenizer sr = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++){
            b[i] = Integer.parseInt(sr.nextToken()); //Taking the heights as input for trio race
        }

        //For the student in duo race
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans ^ a[i]; //XOR because x^x=0
        }
        System.out.print(ans + " ");

        //For the student in trio race
        int ones = 0, twos = 0;
        int common_bit_mask;

        for (int i = 0; i < m; i++) {
            twos = twos | (ones & b[i]);
            ones = ones ^ b[i];
            common_bit_mask = ~(ones & twos);
            ones &= common_bit_mask;
            twos &= common_bit_mask;
        }
        System.out.println(ones);
    }
}

/*
--------Complexity Analysis--------
------Worst Case Complexities------
=>  Time Complexity - O(n+m) 
=>  Space Complexity - O(1) 
*/