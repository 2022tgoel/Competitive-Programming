import java.io.*;
import java.util.*;
public class Walk {
   static ArrayList<Integer>[] graph;
   static boolean[] visited;
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int num_nodes = sc.nextInt();
      int num_edges = sc.nextInt();
      graph = new ArrayList[num_nodes + 1];
      visited = new boolean[num_nodes + 1];
      for (int i = 0; i < num_edges; i++) {
         int x = sc.nextInt();
         int y = sc.nextInt();
         if (x == y) continue;
         if (graph[x] == null) graph[x] = new ArrayList<Integer>();
         if (graph[y] == null) graph[y] = new ArrayList<Integer>();
         graph[x].add(y);
         graph[y].add(x);
      }
      for (int i : traverse(1, new ArrayList<Integer>())) System.out.print(i + " ");
   }
   static ArrayList<Integer> traverse(int v, ArrayList<Integer> path) 
   { 
        // Mark the current node as visited and print it 
        if (!visited[v]) {
            visited[v] = true; 
            path.add(v);
        }
        int next_v = Integer.MAX_VALUE;
        for (int node: graph[v]) 
        { 
            if (visited[node]) next_v = Math.min(next_v, visited_traverse(node, new boolean[visited.length]));
            else next_v = Math.min(next_v, node);
        } 
        if (next_v == Integer.MAX_VALUE) return path;
        else return traverse(next_v, path);
    }
    
    static int visited_traverse(int v, boolean[] sub_visited){
      sub_visited[v] = true;
      int best = Integer.MAX_VALUE;
      for (int node : graph[v]){
         if (visited[node] && !sub_visited[node]) best = Math.min(best, visited_traverse(node, sub_visited));
         else if (!visited[node]) best = Math.min(best, node);
      }
      return best;
    }
}
