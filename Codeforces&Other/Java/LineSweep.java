import java.io.*;
import java.util.*;

public class LineSweep {
   static int NUM_LINES;
   public static void main (String[] args) throws Exception{
      BufferedReader f = new BufferedReader(new FileReader("cowjump.in"));
      NUM_LINES = Integer.parseInt(f.readLine());
      Point[] points = new Point[NUM_LINES*2];
      for (int i = 0; i < NUM_LINES*2; i+=2) {
         StringTokenizer st = new StringTokenizer(f.readLine());
         Point a= new Point(Long.valueOf(st.nextToken()), Long.valueOf(st.nextToken()), (i/2) + 1);
         Point b= new Point(Long.valueOf(st.nextToken()), Long.valueOf(st.nextToken()), (i/2) + 1);
         a.setOpposite(b);
         b.setOpposite(a);
         points[i] = a;
         points[i+1] = b;
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowjump.out")));
      out.println(countIntersections(points));
      out.close();
   }
   public static int countIntersections(Point[] points) {
      //Get the points and sort them
      Arrays.sort(points, HORIZONTAL_COMPARATOR);
      ArrayList<Integer> intersections = new ArrayList<Integer>();
       //Vertically sorted set of candidates
       TreeSet<Point> lines = new TreeSet<Point>(VERTICAL_COMPARATOR);

       //For each point from left to right
       for (int i = 0; i < points.length; i++) {
           Point current = points[i];
           Point a = lines.lower(current);
           Point b = lines.higher(current);
           if (current.x < current.oppositePoint.x || (current.x == current.oppositePoint.x && current.y < current.oppositePoint.y)) {
           //is left
               lines.add(current);
               if (a!=null && current.intersects(a)) {
                  intersections.add(current.n);
                  intersections.add(a.n);
               }
               if (b!=null && current.intersects(b)) {
                  intersections.add(current.n);
                  intersections.add(b.n);
               }
           }
           else {
               lines.remove(current.oppositePoint);
               if (a!=null && b!=null && a.intersects(b)) {
                  intersections.add(a.n);
                  intersections.add(b.n);
               }             
            }
            if (intersections.size() ==4){
               if (intersections.get(0) == intersections.get(2) || intersections.get(0) == intersections.get(3)) return intersections.get(0);
               else return intersections.get(1);
            }
       }
      return Collections.min(intersections);
   }
   private static final Comparator<Point> VERTICAL_COMPARATOR = new Comparator<Point>() {
       @Override
       public int compare(Point a, Point b) {
           return (int) (a.y-b.y);
       }
   };
   private static final Comparator<Point> HORIZONTAL_COMPARATOR = new Comparator<Point>() {
       @Override
       public int compare(Point a, Point b) {
           return (int) (a.x-b.x);
       }
   };
}
class Point{
   long x; 
   long y;
   int n;
   Point oppositePoint;
   public Point(long a, long b, int c){
      x = a;
      y = b;
      n = c;
   }
   public void setOpposite(Point y) {
      oppositePoint = y;
   }
   public boolean intersects(Point p){
      return (ccw(this,p,p.oppositePoint) != ccw(this.oppositePoint,p,p.oppositePoint)) && (ccw(this,this.oppositePoint,p) != ccw(this,this.oppositePoint,p.oppositePoint));
   }
   private boolean ccw(Point A, Point B, Point C) {
      return (C.y-A.y) * (B.x-A.x) > (B.y-A.y) * (C.x-A.x);
   }

    
}