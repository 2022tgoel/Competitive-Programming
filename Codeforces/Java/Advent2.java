import java.util.*;
import java.io.*;
public class Advent2 {
   public static void main (String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("in.txt"));
      String[] inp = f.readLine().split(",");
      int[] input = new int[inp.length];
      for (int i = 0; i < inp.length; i++) {
         input[i] = Integer.parseInt(inp[i]);
      }

      for (int a = 0; a < 100; a ++) {
         for (int b = 0; b < 100; b++) {
            int[] in = new int[input.length];
            for (int i = 0; i < input.length; i++) in[i] = input[i];
            in[1] = a;
            in[2] = b;
            int ind = 0;
            while (in[ind] != 99) {
               if (in[ind] == 1) in[in[ind+3]] = in[in[ind+2]] + in[in[ind+1]];
               else if (in[ind] == 2) in[in[ind+3]] = in[in[ind+2]] * in[in[ind+1]];
               ind +=4;
            }
            if (in[0] == 19690720) {
               System.out.println(100*a+b);
               System.exit(0);
            }
         }
      }
   }  
}