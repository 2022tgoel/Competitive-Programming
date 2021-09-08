import java.util.*;
import java.io.*;
public class problem1
 {
   static int N;
   static int M;
   static Interval[] grass = new Interval[100000];
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("socdist.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      for (int i = 0; i < M; i++ ) {
         st = new StringTokenizer(f.readLine());
         grass[i] = new Interval(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
      }
      Arrays.sort(grass, 0, M);
      int high = grass[M-1].y - grass[0].x + 1;
      int low = 0;
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("socdist.out")));
      while (high - low > 1) {
         int mid = ((high+low)/2);
         int cowsPlaced = 0;
         int minimumPlace = grass[0].x;
         for (int i = 0; i < M; i++){
            minimumPlace = Math.max(minimumPlace, grass[i].x);
            int c = 0;
            if (grass[i].y >= minimumPlace && minimumPlace >= grass[i].x) { 
               c = ((grass[i].y - minimumPlace)/mid) + 1; //place at min place and as many more
            }
         //   System.out.println(minimumPlace + " " + c);
            minimumPlace += c*mid;
            cowsPlaced+=c;
         }
    //     System.out.println(mid + " final " + cowsPlaced);
         if (cowsPlaced >=N) { 
            low = mid;
         }
         else high = mid;
      }
      out.println(low);
      out.close();   
   }
}

class Interval implements Comparable<Interval>{
   int x;
   int y;
   public Interval (int a, int b) {
      x = a;
      y = b;
   }
   public int compareTo(Interval i) {
      return x - i.x;
   }
}