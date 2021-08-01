import java.util.*;
import java.io.*;
import java.lang.Math;
public class problem2 {
   static long N;
   static long K;
   static long M;
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("loan.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Long.parseLong(st.nextToken());
      K = Long.parseLong(st.nextToken());
      M = Long.parseLong(st.nextToken());
      double s = Double.POSITIVE_INFINITY;
      int X = 2;
      while (s > 1) {
         s = calc_s(X);
         System.out.println(X);
//         System.out.println(s);
         X = X*2;
      }
      X = X/2;
      int XL = X/2;
      System.out.println(X);
//            System.out.println(s);
      while (X-XL>1) {
         if (calc_s(XL+(X-XL)/2)<1) {
            X=XL+(X-XL)/2;
            } 
         else {
            XL = XL+(X-XL)/2;
            System.out.println(X);
//            System.out.println(s);
         }
      }
     X-=1;
      // System.out.println(X);
      while (!tot(X)) {
        System.out.println(X);
         X--;
      }
      while (tot(X)) {
         System.out.println(X);
         X++;
      }
      X-=1;
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("loan.out")));
      out.println(X);
      out.close();   
   
   }
   static double calc_p(long X) {
      return (Math.log(M) - Math.log((double) N/X))/ Math.log((double)(X-1)/X);
   }
   static double calc_s(long X) {
      double p = calc_p(X);
      return 1-Math.pow((double)(X-1)/X, p) + (K-p)*((double) M/N);
   }
   static boolean tot(int X){
      long G = 0;
      long D = K;
     // System.out.println(X + " " + G + " " + D + " " + M);
      while (G + D*M < N && (N-G)/X > M) {
         D--;
         G+= (N-G)/X;
       //  System.out.println(X + " " + G + " " + D + " " + M);
      }
     // System.out.println(G + D*M );
      if (G + D*M >= N) return true;
      else return false;
      
   }
}