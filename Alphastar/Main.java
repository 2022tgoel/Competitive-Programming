import java.util.*;

public class runner{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();
        
        char[][] arr = new char[r+2][c+2];
        
        for(int i = 1; i <= r; i++)
        {
            char[] arra = new char[c];
            arra = sc.next().toCharArray();
            for(int j = 1; j <= c; j++)
            {
                arr[i][j] = arra[j-1];
            }
        }
        
        int count = 0;
        
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                if(arr[i][j] == '#' && arr[i-1][j] != '#' && arr[i][j-1] != '#')
                {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}