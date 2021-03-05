import java.io.*;
import java.util.*;

public class Rose_Garden {
   static int N;
   static int M;
   static int[] flowers;
   static int[] costs = new int[100001];
   static int[] dp = new int[5001];
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      N = sc.nextInt();
      M = sc.nextInt();
      flowers = new int[N+1];
      for (int i = 1; i <= N; i ++) flowers[i] = sc.nextInt();
      for (int i = 1; i <= M; i++) costs[i] = sc.nextInt();
      for (int i = M-1; i >=1; i--) costs[i] = Math.min(costs[i+1], costs[i]);
      Arrays.sort(flowers);
      dp[0] = 0;
      for (int i = 1; i <= N; i ++) {
         dp[i] = Integer.MAX_VALUE;
         for (int j = 1; j <= i; j++) {
            dp[i] = Math.min(dp[i], costs[flowers[i]-flowers[j]+1] + dp[j-1]); 
         }
      }
      System.out.println(dp[N]);
   }  
}

public class SegTree { 
      
    // limit for array size 
    static int N = 100000;  
      
    static int n; // array size 
      
    // Max size of tree 
    static int []tree = new int[2 * N]; 
      
    // function to build the tree 
    static void build( int []arr)  
    {  
          
        // insert leaf nodes in tree 
        for (int i = 0; i < n; i++)  
            tree[n + i] = arr[i]; 
          
        // build the tree by calculating 
        // parents 
        for (int i = n - 1; i > 0; --i)  
            tree[i] = tree[i << 1] + 
                      tree[i << 1 | 1];  
    } 
      
    // function to update a tree node 
    static void updateTreeNode(int p, int value)  
    {  
          
        // set value at position p 
        tree[p + n] = value; 
        p = p + n; 
          
        // move upward and update parents 
        for (int i = p; i > 1; i >>= 1) 
            tree[i >> 1] = tree[i] + tree[i^1]; 
    } 
      
    // function to get sum on 
    // interval [l, r) 
    static int query(int l, int r)  
    {  
        int res = 0; 
          
        // loop to find the sum in the range 
        for (l += n, r += n; l < r; 
                             l >>= 1, r >>= 1) 
        { 
            if ((l & 1) > 0)  
                res += tree[l++]; 
          
            if ((r & 1) > 0)  
                res += tree[--r]; 
        } 
          
        return res; 
    }    
}