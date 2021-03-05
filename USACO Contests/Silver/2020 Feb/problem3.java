import java.util.*;
import java.io.*;
public class problem3 {
   static ArrayList<Integer>[] graph;
   static int[] increm;
   static int N;
   static boolean[] visited;
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("clocktree.in"));
      N = Integer.parseInt(f.readLine());
      StringTokenizer st = new StringTokenizer(f.readLine());
      increm = new int[N];
      for (int i = 0; i < N; i++) {
         increm[i] = Integer.parseInt(st.nextToken());
      }
      graph = new ArrayList[N];
      for (int i = 0; i < N; i++) graph[i] = new ArrayList<Integer>();
      for (int i = 0; i < N-1; i++) {
         st = new StringTokenizer(f.readLine());
         int a = Integer.parseInt(st.nextToken()) - 1;
         int b = Integer.parseInt(st.nextToken()) - 1;
         graph[a].add(b);
         graph[b].add(a);
      }
      int s = 0;
      for (int i = 0; i< N; i++) {
         visited = new boolean[N];
         int iter = solve(i); 
         if (iter == 0 || iter == 11) s++;
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("clocktree.out")));
      out.println(s);
      out.close();   
   }
   static int solve(int a) {
      visited[a] = true;
      int n = increm[a];
      for (int i : graph[a]) {
         if (visited[i] != true) n+=solve(i); 
      }
      n = n % 12;
      return 12 - n;
   }
}