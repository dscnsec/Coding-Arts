//        Complexity:

//        We traverse both the arrays of size n and m respectively and add the smaller element in the third array.
//        In the end, we copy the rest of the elements from arr1[ ] or arr2[ ]. So time complexity is:
//        Time Complexity : O(n + m)

//        Since we are taking an extra array arr3[ ], it will take space O(n+m), it will have space complexity of:
//        Auxiliary Space : O(n + m)


import java.util.Scanner;

class birthdaySurprise {

    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int pile1[]=new int[n];

        for(int i=0;i<n;i++) {
            pile1[i] = sc.nextInt();
        }

        int m=sc.nextInt();
        int pile2[]=new int[m];

        for(int i=0;i<m;i++) {
            pile2[i] = sc.nextInt();
        }

        int[] combinedPiles = new int[n+m];
        sorted_array(pile1, pile2, n, m, combinedPiles);

        // Return the middle element of merged combinedPiles array
        System.out.print(combinedPiles[combinedPiles.length/ 2]);

    }
    static void sorted_array(int[] pile1, int[] pile2, int n, int m, int[] combinedPiles){

        {
            // take three pointers at first index of each array
            int i = 0, j = 0, k = 0;

            // Traverse both pile1 and pile2
            while (i < n && j < m)
            {
                // Check if current element of pile1 is smaller than current element of pile2.
                // If true, store first element of pile1 in combinedPiles array and increment pile1 index.
                // Else do the same with pile2
                if (pile1[i] < pile2[j])
                    combinedPiles[k++] = pile1[i++];

                else
                    combinedPiles[k++] = pile2[j++];
            }

            // Store remaining elements of pile1 in combinedPiles array
            while (i < n)
                combinedPiles[k++] = pile1[i++];

            // Store remaining elements of pile2 in combinedPiles array
            while (j < m)
                combinedPiles[k++] = pile2[j++];
        }
    }
}
