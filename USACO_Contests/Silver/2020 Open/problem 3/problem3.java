import java.util.*;
import java.io.*;
public class problem3
 {
   static int N;
   static Point[] points = new Point[100000];
   static TreeSet<Point> takers = new TreeSet<Point>(new Y());
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("moop.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      for (int i =0 ; i < N; i++) {
         st = new StringTokenizer(f.readLine());
         points[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
      }
      Arrays.sort(points, 0, N);
      Point upperBound = null;
      for (int i=0; i<N; i++) {
      
       //  PointsGroup g = new PointsGroup(points[i]);
         takers.add(points[i]);
         Point last = takers.pollLast();
         if (upperBound == null) upperBound = points[i];
         else if (upperBound.y < points[i].y) upperBound = points[i];
         Iterator<Point> set = (takers.tailSet(points[i], true)).iterator();
         while (set.hasNext()) {
         //   PointsGroup add = 
            set.next(); set.remove(); 
         //   g.addGroup(add);
         }
         takers.add(last);
    //     System.out.println(takers);

      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moop.out")));
      out.println(takers.size());
      out.close();   
   }
}
class Y implements Comparator<Point> 
{ 
    public int compare(Point a, Point b) 
    { 
        if (b.y == a.y) return b.x - a.x;
        return b.y - a.y; 
    } 
}


class Point implements Comparable<Point> {
   int x;
   int y;
   public Point(int a, int b) {
      x = a;
      y = b;
   }
   public int compareTo(Point p) {
      if (x == p.x) return y - p.y;
      return x - p.x;
   }
   public String toString() {
      return x + " " + y;
   }
}