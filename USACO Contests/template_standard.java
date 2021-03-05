import java.util.*;
import java.io.*;
public class template_standard
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		System.out.println(x);	  
	}
	public static void printArray(Object[] arr, int index){
		System.out.print('[');
		for (int i = 0; i < index; i++) System.out.print(arr[i] + " ");
		System.out.println(']');
	}
	public static void printArray(int[] arr, int index){
		System.out.print('[');
		for (int i = 0; i < index; i++) System.out.print(arr[i] + " ");
		System.out.println(']');
	}
}