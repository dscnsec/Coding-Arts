
/*Time complexity-
 O(x*n) for Karan's Queries, here-
 - x= number of new connections created
 - n= number of users of this Application
 Space complexity-
 O(n+m) space is required to store the connections and followers, here-
 - n= number of users of this Application
 - m= number of connections.
 Approach-
 1.Store the name of the users and their followers(in ArrayList) in the HashMap.
 2.Add new connections as well(Check for the primary key violation).
 3.Find the suggestions. If no suggestions found than 0 is printed.
 */

import java.util.*;//including util package for taking canner inputs 
public class Application_for_Karan
{
  public static void main(String[] args)
  {
	Scanner input=new Scanner(System.in);
	long n,m;
	n =input.nextLong();// number of users.
	m =input.nextLong();// number of connections.
	HashMap<String,ArrayList<String>> mp = new HashMap<String,ArrayList<String>>();
	String user_a;
	String user_b;
	for (long i = 0; i < m; i++)
	{
		user_a = input.next();//user
		user_b = input.next();// a following b user
		//Checking if b(Key) is there in the HashMap
		if(!mp.containsKey(user_b))
		{
		    ArrayList<String> ar1 = new ArrayList<String>();
		    ar1.add(user_a);
		    mp.put(user_b, ar1);
		}
		else
		{
		    mp.get(user_b).add(user_a);
		}
	}
	
	long new_connections;
	new_connections = input.nextLong();// number of new connections.
	while ((new_connections--) != -1)
	{
		user_a =input.next();
		user_b =input.next();
	
		if (!mp.containsKey(user_b))
		{
			
			System.out.print(0);
		}
		else
		{
			int c = 0;
			for (String bb : mp.get(user_b))
			{
				boolean flag = false;
				for (String aa : mp.get(bb))
				{
					if (aa.compareTo(user_a) == 0)
					{
						flag = true;
					}
				}
				if (!flag)
				{
					c++;
					System.out.print(bb);
					System.out.print(" ");
				}
			}
			if (c == 0)
			{
			    //if no suggestions found than 0 is printed
				System.out.print(0);
			}
		}
		System.out.print("\n");	
	}	
  }//main method ends
}//class ends
