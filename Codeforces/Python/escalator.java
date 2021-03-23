import java.util.Scanner;
public class escalator
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        double p = input.nextDouble();
        int t = input.nextInt();
        double M[][] = new double[n+1][t+1];
        M[0][0] = 1;
        for(int i=1;i<=n;i++)
        {
            M[i][0] =  0;
        }
        for(int i=1;i<=t;i++)
        {
            M[0][i] = 1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=t;j++)
            {
                M[i][j] = p * M[i-1][j-1] + (1-p)*M[i][j-1];
                System.out.println(M[i][j]);
            }
        }
        double sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum += M[i][t];
        }
        System.out.println(sum);
    }
}