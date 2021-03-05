import java.util.*;
import java.io.*;
public class problem1 {
   static int N;
   static int M;
   static int K;
   static int[] cows;
   static int[] n_cows;
   static boolean[] visited;
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("swap.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());
      cows = new int[N];
      n_cows = new int[N];
      for (int i = 0; i < N; i++) cows[i] = i;
      for (int i = 0; i< M; i++) {
         st = new StringTokenizer(f.readLine());
         int start = Integer.parseInt(st.nextToken())-1;
         int end = Integer.parseInt(st.nextToken())-1;
         while (start < end) {
            int a = cows[start];
            cows[start] = cows[end];
            cows[end] = a;
            start++;
            end--;
         }
      }
      for (int i = 0; i < N; i++) {
         n_cows[i] = cows[i];
      }
      
      visited = new boolean[N];
      for (int i = 0; i < N; i++) {
         if (visited[i]!=true) {
            int x = findLenCycle(i);
            for (int j = 0; j < x; j++) rotate(i);
            for (int y : n_cows) System.out.println(y);
         }
      
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("swap.out")));
      for (int i : n_cows) out.println(i+1);
      out.close();   
   }
   static public int findLenCycle(int index) {
      visited[index] = true;
      int cur = cows[index];
      int num = 1;
      while (cur!=index) {
         visited[cur] = true;
         cur = cows[cur];
         num++;
      }
      return num;
   }
   static void rotate(int index) {
      int past = index;
      int sends = cows[index];
      int stay = cows[index];
      while (sends!=index) {
         int go = cows[sends];
         stay = n_cows[sends];
         n_cows[sends] = n_cows[past];  
         past = sends;    
         sends = go;
         
      }
      n_cows[index] = stay;
   }

}