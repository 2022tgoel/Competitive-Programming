import java.util.*;
import java.io.*;
public class template_file
{
	public static void main(String[] args) throws IOException{
	  BufferedReader f = new BufferedReader(new FileReader("filename.in"));
	  StringTokenizer st = new StringTokenizer(f.readLine());
	  Integer.parseInt(st.nextToken());

	  PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
	  out.println();
	  out.close();   
	}
	public static void printArray(Object[] arr, int index){
		System.out.print('[');
		for (int i = 0; i < index; i++) System.out.print(arr[index] + " ");
		System.out.println(']');
	}
	public static void printArray(int[] arr, int index){
		System.out.print('[');
		for (int i = 0; i < index; i++) System.out.print(arr[index] + " ");
		System.out.println(']');
	}
}