import java.util.*;
import java.io.*;
public class P3 {
   static ArrayList<Integer>[] adj_rev; 
   static ArrayList<Integer>[] adj;
   static int[] depth;
   static int[] types;
   static int works =0;
   public static void main (String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("milkvisits.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      int barns = Integer.parseInt(st.nextToken());
      int friends = Integer.parseInt(st.nextToken());
      char[] type = f.readLine().toCharArray();
      types = new int[barns];
      for (int i = 0; i < barns; i++) {
         if (type[i] =='G') types[i] = 0;
         else types[i] = 1;
      }
      adj_rev = new ArrayList[barns];
      adj = new ArrayList[barns];
      for(int i=0; i<barns; i++){
         adj[i] = new ArrayList<Integer>();
         adj_rev[i] = new ArrayList<Integer>();
      }
      for (int i = 0; i < barns-1; i++) {
         st = new StringTokenizer(f.readLine());
         int a = Integer.parseInt(st.nextToken())-1;
         int b = Integer.parseInt(st.nextToken())-1;
         adj_rev[b].add(a);
         adj[a].add(b);
      }
      
      int root = -1;
      for (int i = 0; i< adj_rev.length; i ++) if (adj_rev[i].size() == 0) root = i;
   //   System.out.println(root);
      depth = new int[barns];
      depth[root] = 0;
      BFS(root);
   //   for (int i : depth) System.out.println(i);
      
      String ans = "";
      for (int i = 0; i < friends; i++) {
         st = new StringTokenizer(f.readLine());
         int sb = Integer.parseInt(st.nextToken())-1;
         int eb = Integer.parseInt(st.nextToken())-1;
         String typ = st.nextToken();
         int t;
         if (typ.equals("G")) t = 0;
         else t = 1;
         boolean happy = false; 
         if (types[sb] == t || types[eb] == t) {
            happy = true;
         } 
         if (happy) {
            ans+="1";
            continue;
         }
         while (depth[sb] > depth[eb]) {
            sb = adj_rev[sb].get(0);
            if (types[sb] == t) {
               happy = true;
               break;
            } 
         }
         if (happy) {
            ans+="1";
            continue;
         }
         while (depth[sb] < depth[eb]) {
            eb = adj_rev[eb].get(0);
            if (types[eb] == t) {
               happy=true; 
               break;
            } 
         }
         if (happy) {
            ans+="1";
            continue;
         }
         while (sb!=eb) {
            eb = adj_rev[eb].get(0);
            sb = adj_rev[sb].get(0);
            if (types[eb] == t || types[sb] == t) {
               happy=true; 
               break;
            } 
         }
         if (types[sb] == t) {
            happy = true;
         }
         if (happy) ans+="1";
         else ans+="0";
      }  
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milkvisits.out")));
      out.println(ans);
      out.close();
   }
   /*
   public static int reach(int curBarn, int endBarn, int milkType) {
      if (curBarn==endBarn) {
         if (milkType == types[curBarn]) works = 1;
      //System.out.println(works);// + " " + types[curBarn] + " " + endBarn );
         return 1; 
      }
      else {
         for (int barn : adj[curBarn]) {
            if (reach(barn, endBarn, milkType) == 1) {
               if (milkType == types[curBarn]) works = 1;
            //   System.out.println("here" + curBarn + " " + works);
               return 1;
            }
         }
      }
      return 0;
   }
   */
   static void BFS(int s) 
    { 
        // Mark all the vertices as not visited(By default 
        // set as false) 
        boolean visited[] = new boolean[depth.length]; 
  
        // Create a queue for BFS 
        LinkedList<Integer> queue = new LinkedList<Integer>(); 
  
        // Mark the current node as visited and enqueue it 
        visited[s]=true; 
        queue.add(s); 
  
        while (queue.size() != 0) 
        { 
            // Dequeue a vertex from queue and print it 
            s = queue.poll();  
            for (int i : adj[s]) 
            { 
                if (!visited[i]) 
                { 
                    visited[i] = true; 
                    queue.add(i);
                    depth[i] = depth[s] + 1;
                } 
            } 
        } 
    }
}