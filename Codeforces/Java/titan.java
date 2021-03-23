import java.util.*;
import java.io.*;
public class titan
{
   public static void main(String[] args)   {
        Scanner scan = new Scanner(System.in); 
        int g = Integer.parseInt(scan.nextLine());
        int[][] cells = new int[g][g];
        String breach = scan.nextLine();
        String[] bre = breach.split(" ");
        int[] first = new int[2];
        int ans = 1;
        for (int i = 0; i<g; i++){
         String line = scan.nextLine();
         String[] vals = line.split(" ");
         for(int j = 0; j<vals.length; j++){
            cells[i][j] = Integer.parseInt(vals[j]);
         }
        }
        for(int k = 0; k<2; k++){
         first[k] = Integer.parseInt(bre[k]);
        }
        ArrayList<Integer> check = new ArrayList<Integer>();
        check.add(cells[first[0]][first[1]])
        //
        ArrayList<Integer> connects = new ArrayList<Integer>();
        if (1000 && Integer.toBinaryString(check.get(check.size()-1))){
         connects.add()
        }
        //
   }
   
}
   