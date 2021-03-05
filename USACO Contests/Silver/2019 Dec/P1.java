import java.util.*;
import java.io.*;
public class P1 {
   public static void main (String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("moobuzz.in"));
      long num = Integer.parseInt(f.readLine());
      long ans = (long) (num*1.75);
      long orig = calc(ans);
      while (orig!=num) {
         ans += (long) ((num-orig) * 1.75);
         orig = calc(ans);
      }
      while (ans%3 == 0 || ans%5 == 0) ans--;
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("moobuzz.out")));
      out.println(ans);
      out.close();
   }
   static long calc(long num) {
      return num - (num/3) - (num/5) + (num/15);
   }
}
      
      