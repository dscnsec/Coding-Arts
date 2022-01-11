/*
  Time Complexity - O(min(log(m),log(n))
  Space Complexity - O(1)
*/

import java.util.*;

public class BS{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] PileA = new int[n];

        for(int i=0;i<n;i++){
            PileA[i] = sc.nextInt();
        }

        int m = sc.nextInt();

        int[] PileB = new int[m];

        for(int i=0;i<m;i++){
            PileB[i] = sc.nextInt();
        }

        System.out.println(GiftBoxes(PileA,PileB));
    }

    static int GiftBoxes(int[] PileA, int[] PileB)
    {
        // Swapping to make PileA smaller
        int n = PileA.length;
        int m = PileB.length;
        if (n > m)
            return GiftBoxes(PileB, PileA);

        int start = 0;
        int end = n;
        int MergedArrayMid = (n + m + 1) / 2;

        while (start <= end) {

            int mid = (start + end) / 2;
            int SizeLeftPileA = mid;
            int SizeLeftPileB = MergedArrayMid - mid;

            int PileALeft = (SizeLeftPileA > 0) ? PileA[SizeLeftPileA - 1] : Integer.MIN_VALUE;

            int PileBLeft = (SizeLeftPileB > 0) ? PileB[SizeLeftPileB - 1] : Integer.MIN_VALUE;

            int PileARight = (SizeLeftPileA < n) ? PileA[SizeLeftPileA] : Integer.MAX_VALUE;

            int PileBRight = (SizeLeftPileB < m) ? PileB[SizeLeftPileB] : Integer.MAX_VALUE;

            // check if correct partition is done
            if (PileALeft <= PileBRight && PileBLeft <= PileARight) {
                if ((m + n) % 2 == 0)
                    return (Math.max(PileALeft, PileBLeft)
                            + Math.min(PileARight, PileBRight))
                            / 2;
                return Math.max(PileALeft, PileBLeft);
            }
            else if (PileALeft > PileBRight) {
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return 0;
    }
}
