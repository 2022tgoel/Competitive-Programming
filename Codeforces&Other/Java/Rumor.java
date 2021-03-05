import java.util.*;
import java.io.*;

public class Rumor {
   static int v;
   static int c;
   static int[] costs;
   static ArrayList<Integer>[] adj; 
   static boolean[] visited;
   static long sum;
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      v = sc.nextInt();
      c = sc.nextInt();
      costs = new int[v];
      for(int i=0; i<v; i++){
         costs[i] = sc.nextInt();
      }
     
      ///Make matrix of connections
      
      adj = new ArrayList[v];
      for(int i=0; i<v; i++){
         adj[i] = new ArrayList<Integer>();
      }
      ////make graph
      
      for(int i=0; i<c; i++){
         int a = sc.nextInt()-1;
         int b = sc.nextInt()-1;
         adj[a].add(b);
         adj[b].add(a);
      }
      
      visited = new boolean[v];
      
      for(int cur=0; cur<v; cur++){
         if(visited[cur] == true) {
            continue;
         } else {
            sum += DFS(cur, Integer.MAX_VALUE);

         }
      }
      
      System.out.println(sum);  
   }
   
   static int DFS(int cur, int min) 
    { 
        visited[cur] = true; 
        min = Math.min(min, costs[cur]);
        ArrayList<Integer> con = adj[cur];
        for (int n : con) 
        { 
            if (!visited[n]) 
                min = DFS(n, min); 
        } 
        return min;
    } 
   
   
    /* DFS base Implementation, Source: GeeksforGeeks
    void DFSUtil(int v,boolean visited[]) 
    { 
        visited[v] = true; 

        Iterator<Integer> i = adj[v].listIterator(); 
        while (i.hasNext()) 
        { 
            int n = i.next(); 
            if (!visited[n]) 
                DFSUtil(n, visited); 
        } 
    } 

    void DFS(int v) 
    { 
        boolean visited[] = new boolean[V]; 
        DFSUtil(v, visited); 
    } 
    */

}