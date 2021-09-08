import java.util.*;
import java.io.*;
public class FarmPainting
 {
   static int N;
   static Edge[] edges = new Edge[100000];
   static TreeSet<Edge> set = new TreeSet<Edge>(new Y());
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("painting.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      for (int i = 0; i < N; i++) {
         st = new StringTokenizer(f.readLine());  
         int x1 = Integer.parseInt(st.nextToken());
         int y1 = Integer.parseInt(st.nextToken());
         int x2 = Integer.parseInt(st.nextToken());
         int y2 = Integer.parseInt(st.nextToken());
         edges[2*i] = new Edge(x1, y1, y2, true);
         edges[2*i+1] = new Edge(x2, y1, y2, false);
         edges[2*i].setEdge(edges[2*i+1]);
         edges[2*i+1].setEdge(edges[2*i]);
      }
      Arrays.sort(edges, 0, N*2);
      int numUnique = 0;
      for (int i = 0; i < 2*N; i++){
         Edge process = edges[i];
         if (!process.left){
            set.remove(process.e);
         }
         else {
            Edge below = set.lower(process);
            if (below == null || below.y2 < process.y2) {
               set.add(process);
               numUnique++;
            }
         }
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("painting.out")));
      out.println(numUnique);
      out.close();   
   }
}

class Y implements Comparator<Edge> 
{ 
    public int compare(Edge a, Edge b) 
    { 
        return a.y1 - b.y1; 
    } 
}

class Edge implements Comparable<Edge>{
   int x, y1, y2;    
   Edge e;
   boolean left;
   public Edge(int a, int b, int c, boolean bool) {
      x =a; y1=b; y2 = c; left = bool;
   }
   public void setEdge(Edge edge){
      e = edge;
   }
   public int compareTo(Edge b) 
    { 
        return x - b.x; 
    }
}