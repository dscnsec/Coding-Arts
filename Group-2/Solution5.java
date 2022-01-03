/* Solution to Problem 2 */

import java.io.*;
import java.util.*;
class KaranApplicationP2Opt{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Taking the Inputs
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); //Input the number of users
        int m = Integer.parseInt(st.nextToken()); //Input the number of connections

        HashMap<String, ArrayList<String>> follower = new HashMap<>(); //Data Structure to store followers
        HashMap<String, ArrayList<String>> following = new HashMap<>(); //Data Structure to store followings
        for(int i=1;i<=m;i++){
            StringTokenizer sr = new StringTokenizer(br.readLine());
            String a = sr.nextToken();
            String b = sr.nextToken();
            if((follower.get(a)==null)){
                follower.put(a, new ArrayList<>());
            }
            if(following.get(b)==null){
                following.put(b, new ArrayList<>());
            }
            if(follower.get(b)!=null){
                follower.get(b).add(a);
            }
            else{
                follower.put(b, new ArrayList<>());
                follower.get(b).add(a);
            }
            if(following.get(a)!=null){
                following.get(a).add(b);
            }
            else{
                following.put(a, new ArrayList<>());
                following.get(a).add(b);
            }
        }

        //Calling the Method for suggestions
        Suggest(follower, following);
        
    }

    //Method for suggestions
    static void Suggest(HashMap<String, ArrayList<String>> follower, HashMap<String, ArrayList<String>> following) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int x = Integer.parseInt(br.readLine()); // Input for new number of connections
        for(int i=1;i<=x;i++){
            StringTokenizer sr = new StringTokenizer(br.readLine());
            String c = sr.nextToken(); //Input of First Name
            String d = sr.nextToken(); //Input of Second Name
            if((following.get(c)==null) || (follower.get(d)==null)){
                System.out.println(0);
                return;
            }
            ArrayList<String> suggestion = new ArrayList<>(); //Data Structure to store the suggestions
            suggestion = follower.get(d);
            suggestion.removeAll(following.get(c));
            if(suggestion.contains(c)){
                suggestion.remove(c);
            }
            // Printing the Suggestion(s)
            if(suggestion.size()!=0){
                for(int j=0;j<suggestion.size();j++){
                    System.out.print(suggestion.get(j)+" ");
                }
                System.out.println();
            }
            else{
                System.out.println(0); //Printing "0" in case no suggestion exist
            }
        }
    }
}

/*---------Complexity Analysis---------*/
/*-------Worst Case Complexities-------*/
/* Time Complexity - O(n^2) */
/* Space Complexity - O(n^2) */