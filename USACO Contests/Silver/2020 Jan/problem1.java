import java.util.*;
import java.io.*;
public class problem1 {
   static int N;
   static int K;
   static int[] b;
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("berries.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      K = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(f.readLine());
      b = new int[K];
      for (int i = 0; i < K; i++) b[i] = Integer.parseInt(st.nextToken());
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("berries.out")));
      out.println();
      out.close();   
   }
}