import java.util.*;
import java.io.*;
public class candy
{
   public static void main(String[] args)   {
        Scanner scan = new Scanner(System.in);
        int numb = Integer.parseInt(scan.nextLine());
        Map<String, Integer> map = new HashMap<String, Integer>();
        for(int i =0; i<numb; i++){
            String[] s= scan.nextLine().split(" ");
            map.put(s[0], Integer.parseInt(s[1]));
        }
        int sol = 0;
        int beg= 0;
        int length = 1;
        String inst = scan.nextLine();
        while (beg<inst.length()){
            String l = inst.substring(beg, beg+length);
            if(map.containsKey(l)){
               sol+= map.get(l);
               beg+=length;
               length =1;
            }
            else{
               length++;
            }
        }
        
        
        scan.close();
       /*while (c<inst.length()){
         
           for (Map.Entry<String, Integer> entry : map.entrySet()) {
               String key = entry.getKey();
               if (key.equals(inst.substring(c, (c+key.length())))){
                  sol+=map.get(key);
                  c+=key.length(); 
                 //System.out.println(sol);
                 break;
          }
         }}*/
         System.out.println(sol);        
}
}
