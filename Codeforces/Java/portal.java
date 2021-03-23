import java.util.*;
import java.io.*;
import java.lang.*;
public class portal
{
   public static void main(String[] args)   {
        Scanner scan = new Scanner(System.in); 
        String[] inputs = scan.nextLine().split(" ");
        int x= Integer.parseInt(inputs[0]);
        double[] distances = new double[x];
        String[] points = new String[x];
        for (int i= 0; i<distances.length; i++){
         String in = scan.nextLine();
 //        points[i] = in;
         String[] point = in.split(" ");
         distances[i] = Math.sqrt(Math.pow(Integer.parseInt(point[0]),2)+Math.pow(Integer.parseInt(point[1]),2));
         points[i]=point[0]+" "+point[1];
        }
        for(int i = 0; i<Integer.parseInt(inputs[1]); i++){
         System.out.println(points[closest(distances, Double.parseDouble(scan.nextLine()))]);
        }
        
   }
   public static int closest(double[] values, double value){
      int index = 0;
      double space = Math.abs(values[0] -value);
      for (int i = 1; i<values.length; i++){
         if (Math.abs(values[i] -value)< space){
            index=i;
         }
      }
      return index;
   }
}