import java.util.*;
import java.io.*;
public class lunch
{
   public static void main(String[] args)
   {
        Scanner scan = new Scanner(System.in); 
        String input = scan.nextLine();
        ArrayList<Integer> arrli = new ArrayList<Integer>();
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for (int i = 0; i < input.length(); i++) {
         Integer count = map.get(input.charAt(i));
           if (count == null)
               map.put(input.charAt(i), 1);
           else
               map.put(input.charAt(i), count + 1);
         }
         for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            int value = entry.getValue();
            arrli.add(value);
         }
         Collections.sort(arrli);
         int[] f= new int[]{1,1,2,3,5,8,13,21,34,55,89};
         boolean fib = true;
         for(int k=0; k<arrli.size(); k++){
            if (f[k] != arrli.get(k)){
               fib=false;
               System.out.println("NO");
               break;
            }
         }
         if (fib){
            System.out.println("YES");
         }
   }

}
