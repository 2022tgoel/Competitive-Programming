import java.io.*;
import java.util.*;
public class Time_Crunch {
   static ArrayList<Integer>[] connections;
   static ArrayList<Integer>[] weights;
   static int V;
   static int E;
   static int start;
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      V = sc.nextInt();
      E = sc.nextInt();
      connections = new ArrayList[V];
      weights =  new ArrayList[V];
      start = sc.nextInt();
      for (int i = 0; i < V; i++) {
         int a = sc.nextInt();
         int b = sc.nextInt();
         int w = sc.nextInt();
         connections[a].add(b);;
         weights[a].add(w);
      }
      
   }
}