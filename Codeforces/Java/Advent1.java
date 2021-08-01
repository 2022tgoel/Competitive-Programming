import java.util.*;
import java.io.*;
public class Advent1 {
   public static void main (String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("in.txt"));
      int sum = 0;
      for (int i = 0; i < 100; i++) {
         int module = (Integer.parseInt(f.readLine())/3)-2;
         int add_fuel = module;
         while (add_fuel/3 - 2 > 0) {
            add_fuel = add_fuel/3 - 2;
            module+=add_fuel;
         }
         sum+=module;
      }
      System.out.println(sum);
   }
}