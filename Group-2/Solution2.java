/* Solution o Problem 2 */

import java.io.*;
import java.util.*;
class KaranApplicaton{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashMap<String, ArrayList<String>> map = new HashMap<>();
        for(int i=1;i<=m;i++){
            StringTokenizer sr = new StringTokenizer(br.readLine());
            String a = sr.nextToken();
            String b = sr.nextToken();
            if(!(map.containsKey(a))){
                map.put(a, new ArrayList<>());
            }
            if(map.containsKey(b)){
                map.get(b).add(a);
            }
            else{
                map.put(b, new ArrayList<>());
                map.get(b).add(a);
            }
        }

        int flag = 1;
        while(flag!=0){
            String x = br.readLine();
            if(map.containsKey(x)){
                int len = map.get(x).size();
                System.out.println(len);
                for(int i=0;i<len;i++){
                    System.out.print(map.get(x).get(i) + " ");
                }
                System.out.println();
            }
            else{
                System.out.println("No Such member found!");
            }
            System.out.println("Enter 1 if you want to continue else Enter 0");
            flag = Integer.parseInt(br.readLine());
        }
    }
}


/* ---------- Complexity Analysis --------- */
/* Time Complexity - O(n) in worst case */
/* Space Complexity - O(n^2) in worst case */
