import java.util.*;
import java.io.*;
public class P2 {
   static int cows;
   static int b1 = 0;
   static int b2;
   static ArrayList<Cow> arr = new ArrayList<Cow>();
   public static void main (String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("meetings.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      cows = Integer.parseInt(st.nextToken());
      b2 = Integer.parseInt(st.nextToken());
      int sum_weights = 0;
      for (int i = 0; i < cows; i++) {
         st = new StringTokenizer(f.readLine());
         int x = Integer.parseInt(st.nextToken());
         sum_weights += x;
         arr.add(new Cow(x, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0));
      }
      Collections.sort(arr);
      PriorityQueue<Event> events= new PriorityQueue<Event>();
      for (int i = 0; i < arr.size(); i++) {
         Cow cur = arr.get(i);
         Cow right =null;
         if (i<arr.size()-1) right = arr.get(i+1);
         if (right!=null && cur.d == 1 && right.d == -1) events.add(new Event(i, (right.x-cur.x)/2.0, 1));
         if (cur.d == -1) {
            events.add(new Event(i, (cur.x-b1)/1.0, 0));
         }
         else if (cur.d == 1 && cur.x <= b2) {
            events.add(new Event(i, (b2-cur.x)/1.0, 0));
         }
      }
      int w = 0;
      int m = 0;
      while (w/1.0 < sum_weights/2.0) {
         Event e = events.poll();
         if (e.type == 0) w+=arr.get(e.c).w;
         if (e.type == 1) {
            int temp = arr.get(e.c).w;
            arr.get(e.c).w = arr.get(e.c + 1).w;
            arr.get(e.c + 1).w = temp;
            Cow tem = arr.get(e.c);
            arr.set(e.c, arr.get(e.c + 1));
            arr.set(e.c+1, tem);
            temp = arr.get(e.c).x;
            arr.get(e.c).x= arr.get(e.c + 1).x;
            arr.get(e.c + 1).x = temp;
            arr.get(e.c).t += e.t;
            arr.get(e.c+1).t += e.t;
            if (e.c>0 && arr.get(e.c-1).d == 1) events.add(new Event(e.c-1, e.t + (arr.get(e.c).x-arr.get(e.c-1).x)/2.0, 1));
            if (e.c+1<arr.size() -1 && arr.get(e.c+2).d == -1) events.add(new Event(e.c+1, e.t + (arr.get(e.c+2).x-arr.get(e.c+1).x)/2.0, 1));
            m++;
         }
      }
    //  System.out.println(events);
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("meetings.out")));
      out.println(m);
      out.close();
   }
   static class Cow implements Comparable<Cow> {
      int w;
      int x;
      int d;
      double t;
      public Cow(int weight, int pos, int dir, double time) {
         w = weight;
         x = pos;
         d = dir;
         t = time;
      }
      public int compareTo(Cow c) {
         return x - c.x;
      }
   }
   public static class Event implements Comparable<Event> {
      int c;
      double t;
      int type; //0 is barn and 1 is hit anouther cow
      public Event(int inv, double time, int ty) {
         c = inv;
         t = time;
         type = ty;
      }
      public int compareTo(Event e) {
         return (int) (t - e.t);
      }
      public String toString() {
         return t + " " + type; 
      }
   }
}