import java.util.*;
import java.io.*;

public class Cookies {
   static int[] jars = new int[100000];
   static int[] goodness = new int[100000];
   static int[] goodness1 = new int[100000];
   static int N;
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      N = sc.nextInt();
      for(int i = 0; i < N; i++) jars[i] = sc.nextInt();
      int cur_min = jars[0];
      for(int i = 1; i < N-2; i++) {
         goodness[i] = jars[i] - cur_min;
         if (i > 2) goodness[i] = Math.max(goodness[i-1], goodness[i]);
         cur_min = Math.min(jars[i], cur_min); 
      }
      int cur_max = jars[N-1];
      for(int i = N-2; i >=2; i--) { 
         goodness1[i] = cur_max - jars[i];
         if (i < N-2) goodness1[i] = Math.max(goodness1[i+1], goodness1[i]);
         cur_max = Math.max(jars[i], cur_max);
      }
      int solution = -1*Integer.MAX_VALUE;
      for(int i = 1; i < N-2; i++) solution = Math.max(goodness[i] + goodness1[i+1], solution);
      System.out.println(solution);
   }
}