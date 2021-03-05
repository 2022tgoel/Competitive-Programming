/*
Tarushii Goel
Thomas Jefferson High School for Science and Technology
Junior-5 Division
Contest #1 2018-19
Digit Reassembly
*/

import java.util.*;
import java.io.*;
import java.lang.*;
public class digit
{
   public static void main(String[] args) throws IOException    {
       BufferedReader f = new BufferedReader(new FileReader("1jr-test-input.txt"));
       //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("test.out")));
       for(int i = 1; i<=5; i++){
          String input = f.readLine();
          String[] arrput = input.split("");
          if (i==1){
            System.out.println(input.length());
          }
          if (i==2){
            System.out.println(getSum(arrput));
          }
          if (i==3){
            System.out.println(getOddSum(arrput));
          }
          if (i==4){
            System.out.println(fourSum(arrput));
          }
          if (i==5){
            double d = Math.ceil(0.5*arrput.length)-1.0;
            System.out.println(arrput[(int) d]);
          }
       }
   }
   static int getSum(String[] n) {     
      int s = 0; 
      for (int i = 0; i<n.length; i+=1){
         s+=Integer.parseInt(n[i]);
      }
      return s;
    } 
    static int getOddSum(String[] n) {   
      int s = 0; 
      for (int i = 0; i<n.length; i+=2){
         s+=Integer.parseInt(n[i]);
      }
      return s;
    } 
    static int fourSum(String[] n) {   
      int s = 0; 
      for (int i = 0; i<n.length; i++){
         if (Integer.parseInt(n[i])==4){
            s++;
         }
      }
      return s;
    } 
}
