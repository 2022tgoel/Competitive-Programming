import java.util.*;
import java.io.*;

public class More_Smarter {
   static int M;
   static int N;
   static int Q;
   static HashSet<String> dictionary = new HashSet<String>();
   static ArrayList<Streak> streaks = new ArrayList<Streak>();
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      M = sc.nextInt();
      N = sc.nextInt();
      Q = sc.nextInt();
      for (int i = 0; i<M; i++) dictionary.add(sc.next());
      Streak cur = null;
      for (int i = 0; i<N; i++) {
         String s = sc.next();
         if (dictionary.contains(s)) {
            if (cur == null) cur = new Streak();
            cur.add(s);
         }
         else if (!(cur == null)) {
            if (cur.length >= Q) {
               streaks.add(cur);
               cur.mostCommon();
            }
            cur = null;
         }  
      }
      Collections.sort(streaks);
      for (Streak s : streaks) System.out.println(s);
   }

}

class Streak implements Comparable<Streak>{
   int length = 0;
   HashMap<String, Integer> words = new HashMap<String, Integer>();
   String mostCommon = "";
   public void add(String s) {
      if (!words.containsKey(s)) words.put(s, 1);
      else words.replace(s, words.get(s) + 1);
      length++;
   }
   public void mostCommon() {
      for (String key : words.keySet()) {
         if (mostCommon.equals("")) mostCommon = key;
         else if (words.get(key) > words.get(mostCommon) || (words.get(key) == words.get(mostCommon)  && key.compareTo(mostCommon) < 0)) mostCommon = key;
      }
   } 
   public int compareTo (Streak s) {
      if (length == s.length) return mostCommon.compareTo(s.mostCommon);
      return s.length - length;
   } 
   public String toString() {
      return length + " " + mostCommon;
   }
}