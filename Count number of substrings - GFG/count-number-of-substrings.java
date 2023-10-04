//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main (String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            String s = sc.next ();
            int k = sc.nextInt();
    		System.out.println (new Solution().substrCount (s, k));
        }
        
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    private long atMost(String str, int K) {  
        int[] chars = new int[26]; 
        int i=0;
        int j=0;
        int distinct=0;
        long len=0;
        while(j<str.length()) {
            int jth = str.charAt(j) - 'a';
            chars[jth]++;
            if(chars[jth]==1) {
                distinct++;
            }
            while(distinct>K) {
                int ith = str.charAt(i) - 'a';
                chars[ith]--;
                if(chars[ith] == 0) {
                    distinct--;
                }
                i++;
            }
            len += j-i+1;
            j++;
        }
        return len;
    }

long substrCount (String S, int K) {
        if(K==0 || S.length() == 0) {
            return 0;
        }
        return atMost(S, K) - atMost(S, K-1);
    }
}