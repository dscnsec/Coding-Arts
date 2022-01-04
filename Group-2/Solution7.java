//Solution to Problem 7

import java.util.*;
import java.io.*;

class RefRavi{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); //Input of number of students i.e. the number of Heights
        HashMap<Integer, Integer> heights = new HashMap<>(); //Data Structure to store the Heights of the Students
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            int h = Integer.parseInt(st.nextToken()); //Taking the heights as input
            int x = heights.getOrDefault(h, 0);
            heights.put(h, x+1);
        }
        //Iterating the HashMap for the Height of which only one student is present 
        for (Map.Entry<Integer, Integer> set : heights.entrySet()) {
            if(set.getValue() == 1){
                System.out.println(set.getKey()); //Printing the required output
                break; //Ending the loop and thus ending the program
            }
        }
    }
}

/*
--------Complexity Analysis--------
------Worst Case Complexities------
=>  Time Complexity - O(n) 
=>  Space Complexity - O(n) 
*/