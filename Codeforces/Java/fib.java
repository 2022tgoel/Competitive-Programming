import java.util.*;
import java.io.*;
public class fib
{
   public static void main(String[] args) throws IOException
   {
        Scanner scan = new Scanner(System.in); 
        int length = Integer.parseInt(scan.nextLine());
        double time = 0;
        boolean f = true;
        for(int i =0; i<length; i++){
         String student = scan.nextLine();
         String[] s = student.split(" ");
         time += Double.parseDouble(s[0]);
         if(Integer.parseInt(s[1])==1){
            System.out.println("YES");
            f= false;
            break;
         }
         
        }
        if(f){
        if (time>120){
            System.out.println("NO");
         }
         if (time<=120){
            System.out.println("YES");
         }}
   }}
