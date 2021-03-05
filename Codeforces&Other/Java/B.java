import java.io.*;
import java.util.*;

public class B {
   public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      int numWords = sc.nextInt();
      Stack<String> words = new Stack<>();
      for (int i = 0; i < numWords; i++){
         String word = sc.next();
   //      if (words.size()>0) System.out.println(words.size() + " " + words.peek() + " " + word);
         if (words.size()>0 && words.peek().equals(word)) words.pop();
         else words.push(word);
      }
      System.out.println(words.size());
   }
}