import java.io.*;
import java.util.*;
public class A {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int len = sc.nextInt();
      int numQ = sc.nextInt();
      int[] prefix = new int[len];
      String st = sc.next();
      for (int i = 0; i < len; i++) {
         int x = Character.getNumericValue(st.charAt(i));
         if (i > 0) prefix[i] = prefix[i-1] + x;
         else prefix[i] = x;
         int ind = i-prefix[i];
         if (ind >=0) System.out.println(prefix[ind]);
         else System.out.println(0);
      }
   }
}
