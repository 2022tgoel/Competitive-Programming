import java.util.*;

public class E {
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int shops = sc.nextInt();
      int roads = sc.nextInt();
      HashMap<Integer, Integer> ids = new HashMap<Integer, Integer>();
      int[] pops = new int[shops];
      Edge[] r = new Edge[roads*2];
      for (int i = 0; i < shops; i++) {
         ids.put(sc.nextInt(), i);
         pops[i] = sc.nextInt();
      }
      for (int i = 0; i < roads*2; i+=2){
         int a = sc.nextInt();
         int b = sc.nextInt();
         int c = sc.nextInt();
         r[i] = new Edge(a, b, c);
         r[i+1] = new Edge(b, a, c);
      }
      int start = sc.nextInt();
      int[] distances = new int[shops];
      HashMap<Integer, Integer> num = new HashMap<Integer, Integer>();
      for (int i = 0; i < shops; i++) distances[i] = Integer.MAX_VALUE;
      for (int i : ids.keySet()) num.put(i, pops[ids.get(start)]);
      distances[ids.get(start)]=0;
      for (int i = 1; i < shops; ++i) { 
      
         for (int j = 0; j < roads; ++j) { 
             int u = r[j].src; 
             int v = r[j].dest; 
             int weight = r[j].cost; 
             if (distances[ids.get(u)] != Integer.MAX_VALUE && distances[ids.get(u)] + weight < distances[ids.get(v)]) {
                 distances[ids.get(v)] = distances[ids.get(u)] + weight; 
            }
         } 
      }
      int min_id = 0;
      double max_rat = 0;
      for (int i : ids.keySet()){
         int numPop = num.get(i);
         int d = distances[ids.get(i)];
         if ((double)numPop/d > max_rat) {
            min_id = i;
            max_rat = (double)numPop/d;
         }
      }
      System.out.println(min_id);
   }
   public static class Edge {
      public int src;
      public int dest;
      public int cost;
      public Edge (int s, int d, int c){
         src = s;
         dest = d;
         cost = c;
      }
      public String toString() {
         return src + " " + dest + " " + cost; 
      }
   }
}