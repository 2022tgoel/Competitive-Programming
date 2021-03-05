import java.util.*;
import java.io.*;

public class PieRules {
   public static void main(String[] args)
   {
      Scanner sc = new Scanner(System.in);
      int numP = sc.nextInt();
      int[] pies = new int[numP];
      for (int i = 0; i < numP; i++){
         int p = sc.nextInt();
         pies[i] = p;
      }
      int tot = 0;
      int cur = 0;
      for (int i = numP -1; i>=0; i--){
         if (i == numP-1) {
            cur = pies[i];
         }
         else{
            int give = cur;
            int take = pies[i] + tot - cur;
            if (take>give) {
               cur = take;
        //       cur = tot-cur;
            }
         }
         tot+=pies[i];
      }
      System.out.println(tot-cur + " " + cur);
   }
}