import java.util.*;
import java.io.*;
public class guard 
{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("filename.in"));
      StringTokenizer st = new StringTokenizer(f.readLine());
      Integer.parseInt(st.nextToken());
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
      out.println();
      out.close();   
   }
}