import java.util.*;
import java.io.*;
public class problem2
 {
   static int N;
   static int M;
   static int[][] cereal = new int[100001][3]; //0th is state, 1st is second-choice cereal if state 1, 2nd is cowNum
   static int[][] cows = new int[100001][2]; // first and second choices
   static int[] solution = new int [100001];
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("cereal.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());
      for (int i = 0; i < N; i++) {
         st = new StringTokenizer(f.readLine());
         cows[i][0] = Integer.parseInt(st.nextToken());
         cows[i][1] = Integer.parseInt(st.nextToken());
      }

      solution[N] = 0;
      for (int i = N-1; i >=0; i--) {
         solution[i] = solution[i+1];
         int first = cows[i][0];
         int second = cows[i][1];

         if (cereal[first][0] == 2) {
            cereal[first][0] = 1;
            cereal[first][1] = second;
            cereal[first][2] = i;
         }
         else if (cereal[first][0] == 1) {
            int cowSecond = cereal[first][1];
            int cowNum  = cereal[first][2];
            cereal[first][1] = second;
            cereal[first][2] = i;
            boolean cont = true;
            do {
               if (cereal[cowSecond][0] == 0 || (cereal[cowSecond][0]==2 && cowNum < cereal[cowSecond][2])) {
                  if (cereal[cowSecond][0] == 0) solution[i]++;
                  cereal[cowSecond][0] = 2;
                  cereal[cowSecond][2] = cowNum;
                  cont = false;
               }
               else if (cereal[cowSecond][0] == 1 && cowNum > cereal[cowSecond][2]) {
                  cont = false;
               }
               else if (cereal[cowSecond][0] == 1 && cowNum < cereal[cowSecond][2]) {
                  int tempNum = cereal[cowSecond][2];
                  cereal[cowSecond][0] = 2;
                  cereal[cowSecond][2] = cowNum;
                  cowSecond = cereal[cowSecond][1];
                  cowNum = tempNum;
               } 
               else {
                  cont = false;
               }
            } while (cont);

         }
         else {
            cereal[first][0] = 1;
            cereal[first][1] = second;
            solution[i]++;
            cereal[first][2] = i;
         }

      }
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cereal.out")));
      for (int i = 0; i< N; i++) out.println(solution[i]);
      out.close();
   }
}
