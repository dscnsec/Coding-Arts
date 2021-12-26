//Time complexity is n+m.
//n=Number of users.
//m=number of connections.
import java.util.*;

class ProblemStatement2{

    static Map<String, ArrayList<String>> hashMap = new HashMap<String, ArrayList<String>>();
    public static void main(String... arg) {
        Scanner sc=new Scanner(System.in);
        //enter the number of users
        int num=sc.nextInt();
        //enter the number of connections
        int n=sc.nextInt();
        String k,v;
        //enter the name of the follower and the account that user is following
        for(int i=0;i<n;i++)
        {
            k=sc.next();
            v=sc.next();
            //add the information about the connections
            addValues(v,k);
        }


        // System.out.println("Enter the name");
        while(true)
        {
            Iterator<String> it = hashMap.keySet().iterator();
            ArrayList<String> tempList = null;
            String ar[]=new String[num];
            String s=sc.next();
            int c=0;
            while (it.hasNext()) {
                String key = it.next().toString();
                tempList = hashMap.get(key);
                if (tempList != null) {
                    for (String value: tempList) {
        	 /*comparing the users,if a particular account is followed then
        	 the name of that account is stored in an array(ar)*/
                        if(s.equals(key)) {
                            ar[c]=value;
                            c++;
                        }
                    }
                }
            }
            //printing the number of followers of a user
            if(c>0)
                System.out.println(c);
            //printing the name of the followers according to the time of following,i.e latest follower will be printed at the last.
            for(int i=0;i<c;i++)
            {
                System.out.print(ar[i]);
                System.out.print(" ");
            }
            System.out.println();
            //
        }
    }
    private static void addValues(String key, String value) {
        ArrayList<String> tempList = null;
        if (hashMap.containsKey(key)) {
            tempList = hashMap.get(key);
            if(tempList == null)
                tempList = new ArrayList<String>();
            tempList.add(value);
        } else {
            tempList = new ArrayList<String>();
            tempList.add(value);
        }
        hashMap.put(key,tempList);
    }
}
