import java.util.*;
import java.io.*;
public class slider
{
   public static void main(String[] args)
   {
        Scanner scan = new Scanner(System.in); 
        String input = scan.nextLine();
        String[] s = input.split("");
        ArrayList<Integer> arr = new ArrayList<Integer>(8);
        for (int i =0; i<s.length; i++){
         if (!s[i].equals("_")){
            arr.add(Integer.parseInt(s[i]));
            
         }
        }
        if (getCount(arr) % 2 ==0){
         System.out.println("YES");
        }else{
         System.out.println("NO");
        }
        
   }
   public static int getCount(ArrayList<Integer> arr) { 
       int count = 0; 
       for (int i = 0; i <7; i++) { 
           for (int j = i + 1; j <8; j++) {  
               if (arr.get(i) > arr.get(j)) {
                   count++; }
           } 
       } 
       return count; 
   } 
  
}
