import java.util.*;

public class C {
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int numMole = sc.nextInt();
      int numMallet = sc.nextInt();
      long[] s = new long[numMole];
      long[] f = new long[numMallet];
      for (int i = 0; i < numMole; i++) s[i] = sc.nextLong();
      for (int i = 0; i < numMallet; i++) f[i] = sc.nextLong();  
      Arrays.sort(s);
      Arrays.sort(f);
      int ind = 0;
      int cur = 0;
      long tot = 0;
      while (ind < numMole){
         while (cur < numMallet && f[cur]<s[ind]) cur++;
         if (cur >= numMallet) {
            System.out.println(-1);
            System.exit(0);
         }
         tot += f[cur];
         cur++;
         ind++;
      }
      System.out.println(tot % 1000000007);
   }
}