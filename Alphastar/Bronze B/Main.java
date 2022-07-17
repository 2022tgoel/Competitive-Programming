import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int F = scan.nextInt(); // cows
        int K = scan.nextInt(); // tasks
        
        int[][] tasks = new int[K][2];
        
        for (int i = 0; i < K; i++) {
            tasks[i][0] = scan.nextInt(); // start
            tasks[i][1] = scan.nextInt(); // increment
        }
        
        int counter = 0;
        for (int j = 0; j < F; j++) { // 1 5  (0%5) = 1 
            boolean hasTask = false;
            for (int k = 0; k < K; k++) {
                if ((j+1) % tasks[k][1] == tasks[k][0] % tasks[k][1]) {
                    hasTask = true;
                }
            }
            if (hasTask == false) {
                counter++;
            }
        }
        
        System.out.println(counter);
    
    }
}