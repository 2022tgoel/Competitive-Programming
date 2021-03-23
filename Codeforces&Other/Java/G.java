import java.util.*;

public class G {
   static long[] panics;
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int ppl = sc.nextInt();
      panics = new long[ppl];
      for (int i = 0; i < ppl; i++) panics[i] = sc.nextLong();
      Arrays.sort(panics);
      print(0);

   }
   public static void print(int ind){
      if (ind >= panics.length) return;
      System.out.print(panics[ind]+ " ");
      print(ind+2);
      if (ind!=panics.length-1) System.out.print(panics[ind+1]+" ");
   }
}