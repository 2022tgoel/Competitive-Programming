import java.io.*;
import java.util.*;

public class Love_Rescue {
   static int l;
   static ArrayList<Integer>[] graph = new ArrayList[26];
   static Scanner sc = new Scanner(System.in);
   static boolean[] visited = new boolean[26];
   static ArrayList<Integer>[] comp = new ArrayList[26];
   public static void main(String[] args){
      l = Integer.parseInt(sc.nextLine());
      String[] s1 = sc.nextLine().split("");
      String[] s2 = sc.nextLine().split("");
      for(int i=0; i<26; i++){
         graph[i] = new ArrayList<Integer>();
         comp[i] = new ArrayList<Integer>();
      }
      for(int i=0; i<l; i++){
         if(!s1[i].equals(s2[i])){
            graph[(int)s1[i].charAt(0) - 97].add((int)s2[i].charAt(0) - 97);
            graph[(int)s2[i].charAt(0) - 97].add((int)s1[i].charAt(0) - 97);
         }
      }
      int spells = 0;
      int comp_no = 0;
      for(int i=0; i<26; i++){
         if(graph[i].size()>0 && !visited[i]){
            DFS(i, comp_no);
            spells+=comp[comp_no].size()-1;
            comp_no++;
         }
      }
      System.out.println(spells);
      for(int i=0; i<comp_no; i++){
         for(int j=0; j<comp[i].size()-1; j++){
            System.out.println((char)(comp[i].get(j)+97)+" "+(char)(comp[i].get(j+1)+97));
         }
      }
   }
   static void DFS(int cur, int comp_no) 
    { 
      visited[cur] = true;
      comp[comp_no].add(cur); 
      ArrayList<Integer> con = graph[cur];
      for (int n : con) 
         if (!visited[n]) 
            DFS(n, comp_no); 
    } 

}