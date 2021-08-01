import java.util.*;
import java.io.*;
import java.lang.*;
public class money{
   public static void main(String[] args)
   {    
      Scanner scan = new Scanner(System.in); 
       int boxes = Integer.parseInt(scan.nextLine());
       String[] vals = (scan.nextLine()).split(" ");
       int charity=Integer.parseInt(vals[0]);
       int k1 = 1;
       int k2 = boxes-1;
       int a = 0;
       int h = 0;
       int[] arvind= new int[boxes+1];
       int[] havish = new int[boxes+1];
       arvind[boxes]=0;
       havish[1]=0;
       if (charity < -2000) {
         havish[1]=charity;
         h = charity;
         charity=0;
         }
         
       
       havish[0]=0;
       for(int i =1; i<=boxes-1; i++){

         a+=Integer.parseInt(vals[k2]);
         arvind[k2]=a;
         k2--;
         int x = Integer.parseInt(vals[k1]);
         if (charity<x){
            h+=charity;
            charity=x;
          }else{
            h+=x;
          }
          havish[k1+1]=h;
          k1++;
        }
        a+=Integer.parseInt(vals[k2]);
        arvind[k2]=a;
        
        int k=1; a=arvind[1]; h=havish[1];
        int diff=Math.abs(a-h);
        for(int i =2; i<=boxes; i++){
        //System.out.println(k+" " +h+" " +a);   
         int d1 = Math.abs(arvind[i]-havish[i]);
         if (d1<diff) {
            diff = d1;
            a = arvind[i];
            h = havish[i];
            k=i;
          }
         }

         System.out.println(k+" " +h+" " +a);   
    }

}