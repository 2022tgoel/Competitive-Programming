import java.util.*;
import java.io.*;

public class Prerequisites {
   static ArrayList<Integer>[] graph= new ArrayList[100000];
   static ArrayList<Integer> etour = new ArrayList<Integer>();
   static boolean[] visited = new boolean[100000];
   static int[] first = new int[100000];
   static int[] depth = new int[100001];
   static int N;
   static int Q;
   static int n = 1; 
   static int[] tree;
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      N = sc.nextInt();
      Q = sc.nextInt();
      for (int i = 0; i < N; i++)
         graph[i] = new ArrayList<Integer>();
      for (int i = 0; i < N-1; i++)
         graph[sc.nextInt()- 1].add(sc.nextInt()-1);
      eulerianTour(0, 0);
      depth[100000] = Integer.MAX_VALUE;
      for (int i = 0; i<N; i++) first[i] = -1;
      for (int i = 0; i<etour.size(); i++) 
         if (first[etour.get(i)] == -1)  first[etour.get(i)] = i;
      int len = etour.size();
      while ((len = len>>1) > 0) {
         n = n<<1;
      }
      n = n<<1;
      build(etour);
      /*
      for(int i=0; i < N; i++) System.out.print(depth[i] + ",");
      System.out.println();
      for(int i=0; i < 2*n; i++) System.out.print(tree[i] + ",");
      System.out.println();
      */
      for (int i = 0; i < Q; i++) {
         int a = first[sc.nextInt()-1];
         int b = first[sc.nextInt()-1];
       //  System.out.println(a + " " + b);
         System.out.println(query(Math.min(a,b), Math.max(a,b) + 1)+1);
      }
   }
   
   static void eulerianTour (int ind, int d) {
      visited[ind] = true;
      depth[ind] = d;
      etour.add(ind);
      for (int i : graph[ind]) {
         if (visited[i]!=true) {
            eulerianTour(i, d+1);
            etour.add(ind);
         }
      }
      
   }
      // function to build the tree 
    static void build(ArrayList<Integer> arr)  
    {  
        tree = new int[n*2]; 
        // insert leaf nodes in tree 
        for (int i = 0; i < n; i++) {
            if (i < arr.size()) tree[n + i] = arr.get(i); 
            else tree[n+i] = 100000;
         }
        // build the tree by calculating 
        // parents 
        for (int i = n - 1; i > 0; --i)  {
            if (depth[tree[i << 1]] < depth[tree[i << 1 | 1]]) 
               tree[i] = tree[i<<1];
            else 
               tree[i] = tree[i << 1 | 1];  
        }  
    } 

    // function to get sum on 
    // interval [l, r) 
    static int query(int l, int r)  
    {  
        int res = -1; 
          
        // loop to find the sum in the range 
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
        { 
            if ((l & 1) > 0) {
         //      System.out.println(tree[l]);
               if (res == -1) res = tree[l++];
               else if (depth[tree[l]] < depth[res]) 
                  res = tree[l++];
               else 
                  l++;
            }
            if ((r & 1) > 0)  {
                if (res == -1) res = tree[--r];
                else if (depth[tree[--r]] < depth[res]) 
                  res = tree[r];
             //   System.out.println(tree[r]);
            }
        } 
        if (res==-1) return tree[l];  
        return res; 
    } 
   
}
