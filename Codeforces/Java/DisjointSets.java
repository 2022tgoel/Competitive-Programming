import java.util.*;
import java.io.*;
// code for disjoint sets and methods fonud at : https://www.sanfoundry.com/java-program-implement-disjoint-set-data-structure/
 
public class DisjointSets {
    private List<Map<Integer, Set<Integer>>> disjointSet;
 
    public DisjointSets()
    {
        disjointSet = new ArrayList<Map<Integer, Set<Integer>>>();
    }
 
    public void create_set(int element)
    {
        Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>();
        Set<Integer> set = new HashSet<Integer>();
        set.add(element);
        map.put(element, set);
        disjointSet.add(map);
    }
 
    public void union(int first, int second)
    {
        int first_rep = find_set(first);
        int second_rep = find_set(second);
 
        Set<Integer> first_set = null;
        Set<Integer> second_set = null;
 
        for (int index = 0; index < disjointSet.size(); index++)
        {
            Map<Integer, Set<Integer>> map = disjointSet.get(index);
            if (map.containsKey(first_rep))
            {
                first_set = map.get(first_rep);
            } else if (map.containsKey(second_rep))
            { 
                second_set = map.get(second_rep);
            }
        }
 
        if (first_set != null && second_set != null)
        first_set.addAll(second_set);
 
        for (int index = 0; index < disjointSet.size(); index++)
        {
            Map<Integer, Set<Integer>> map = disjointSet.get(index);
            if (map.containsKey(first_rep))
            {
                map.put(first_rep, first_set);
            } else if (map.containsKey(second_rep))
            {
                map.remove(second_rep);
                disjointSet.remove(index);
            }
        }
 
        return;
    }
    public int find_set(int element)
    {
        for (int index = 0; index < disjointSet.size(); index++)
        {
            Map<Integer, Set<Integer>> map = disjointSet.get(index);
            Set<Integer> keySet = map.keySet();
            for (Integer key : keySet)
            {
                Set<Integer> set = map.get(key);
                if (set.contains(element))
                {
                    return key;
                }
            }
        }
        return -1;
    }
    public long find_best(long[][] locs)
    {
        
        long p = 400000005;
        for (int index = 0; index < disjointSet.size(); index++)
        {
          Map<Integer, Set<Integer>> map = disjointSet.get(index);
         Set<Integer> keySet = map.keySet();
         long minx = 1000000001;
         long miny = 1000000001;
         long maxx = -1;
         long maxy = -1;
         for (Integer key : keySet)
         {
            Set<Integer> set = map.get(key);
            for (Object object : set){
               int k = (int) object;
               minx = Math.min(minx,locs[k-1][0]);
               maxx = Math.max(maxx,locs[k-1][0]);
               miny = Math.min(miny,locs[k-1][1]);
               maxy = Math.max(maxy,locs[k-1][1]); 
            }
            System.out.printf("key %d",key);
         } 
         System.out.println(index);
         p = Math.min(p, (maxx-minx+maxy-miny)*2);
       }
       return p;
    }
 
    public int getNumberofDisjointSets()
    {
        return disjointSet.size();
    }
 
    public static void main(String... arg) throws IOException{
        // Use BufferedReader rather than RandomAccessFile; it's much faster
       BufferedReader f = new BufferedReader(new FileReader("fenceplan.in"));
                                                     // input file name goes above
       PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("fenceplan.out")));
       // Use StringTokenizer vs. readLine/split -- lots faster
       StringTokenizer st = new StringTokenizer(f.readLine());
   						  // Get line, break into tokens
       int sets = Integer.parseInt(st.nextToken());    // first integer
       int cons = Integer.parseInt(st.nextToken());    // second integer
       long[][] locs = new long[sets][2];
       for (int a = 0; a<sets; a++){
         StringTokenizer s = new StringTokenizer(f.readLine());;
         locs[a][0] = Integer.parseInt(s.nextToken());    // first integer
         locs[a][1] = Integer.parseInt(s.nextToken());    // second integer
       }
       DisjointSets disjointSet = new DisjointSets();
 
       for (int i = 1; i <= sets; i++)
       {
         disjointSet.create_set(i);
       }
       for (int i = 1; i<=cons; i++){
         StringTokenizer s = new StringTokenizer(f.readLine());
         int x= Integer.parseInt(s.nextToken());    // first integer
         int y = Integer.parseInt(s.nextToken());    // second integer
         disjointSet.union(x, y);
       }
       long b = disjointSet.find_best(locs);
       
       out.println(b);
       out.close();


    }
}