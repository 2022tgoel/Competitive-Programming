/*
import java.util.*;
import java.io.*;
public class problem2 {
   static int N;
   static Point[] A;
   static HashMap<Integer, ArrayList<Point>> x_coords = new HashMap<>();
   static HashMap<Integer, ArrayList<Point>> y_coords = new HashMap<>();
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("triangles.in"));
      N = Integer.parseInt(f.readLine());
      A = new Point[N];
      for (int i = 0; i< N; i++) {
         StringTokenizer st = new StringTokenizer(f.readLine());
         Point P = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
 //        System.out.println(P.x + P.y);
         A[i] = P;
         if (!x_coords.containsKey(P.x))
            x_coords.put(P.x, new ArrayList<Point>());
         if (!y_coords.containsKey(P.y))
            y_coords.put(P.y, new ArrayList<Point>()); 
         x_coords.get(P.x).add(P);
         y_coords.get(P.y).add(P);  
      }
      long area = 0;
      for (Point P : A) {
         for (Point X : x_coords.get(P.x)) {
            for (Point Y : y_coords.get(P.y)) {
               area+= Math.abs((P.x-Y.x) * (P.y-X.y));
            }
         }
         area = area % 1000000007;
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));
      out.println(area);
      out.close();   
   }
}

class Point {
   int x;
   int y;
   Point(int a, int b) {
      x = a;
      y = b;
   }
}
*/

import java.util.*;
import java.io.*;
public class problem2 {
   static int N;
   static Point[] A;
   static HashMap<Integer, ArrayList<Point>> x_coords = new HashMap<>(100000);
   static HashMap<Integer, ArrayList<Point>> y_coords = new HashMap<>(100000);
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("triangles.in"));
      N = Integer.parseInt(f.readLine());
      A = new Point[N];
      for (int i = 0; i< N; i++) {
         StringTokenizer st = new StringTokenizer(f.readLine());
         Point P = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
 //        System.out.println(P.x + P.y);
         A[i] = P;
         if (!x_coords.containsKey(P.x))
            x_coords.put(P.x, new ArrayList<Point>(10));
         if (!y_coords.containsKey(P.y))
            y_coords.put(P.y, new ArrayList<Point>(10));
         x_coords.get(P.x).add(P);
         y_coords.get(P.y).add(P);  
      }
      long area = 0;
      for (Point P : A) {
         for (Point X : x_coords.get(P.x)) {
            for (Point Y : y_coords.get(P.y)) {
               if (P!=X && P!=Y)
                  area+= Math.abs((P.x-Y.x) * (P.y-X.y));
            }
         }
         area = area % 1000000007;
      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));
      out.println(area);
      out.close();  
   }
}

class Point {
   int x;
   int y;
   Point(int a, int b) {
      x = a;
      y = b;
   }
}
