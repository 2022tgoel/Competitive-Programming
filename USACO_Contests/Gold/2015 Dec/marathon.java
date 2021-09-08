import java.util.*;
import java.io.*;
public class marathon 
{
  static int N;
  static int Q;
  static int[][] points = new int[100001][2];
  static int[] tree;
  static int N_2;
  public static void main(String[] args) throws IOException{
    BufferedReader f = new BufferedReader(new FileReader("filename.in"));
    StringTokenizer st = new StringTokenizer(f.readLine());
    N = Integer.parseInt(st.nextToken());
    N_2 = nextPowerOf2(N);
    Q = Integer.parseInt(st.nextToken());
    for (int i=0; i<N; i++){
      st = new StringTokenizer(f.readLine());
      points[N] = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())}
    }

    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("filename.out")));
    out.println();
    out.close();   
  }
  static void build(int[][] arr)  
  {  
    tree = new int[N_2*2]; 
    // insert leaf nodes in tree 
    for (int i = 0; i < N_2; i++) {
        if (i < arr.length) tree[N + i] = i; // index of point
        else tree[N_2+i] = 100000;
     }
    // build the tree by calculating 
    // parents 
    for (int i = N_2-1; i >= N_2/2; i--) {
      tree[i] = dist(tree[i << 1], tree[i << 1 | 1])
    }
    for (int i = N_2/2-1; i > 0; i--)  {
        tree[i] = tree[i << 1] + tree[i << 1 | 1]  
    }  
  } 

  // function to get sum on 
  // interval [l, r) 
  static int query(int l, int r)  
  {  
    int res = 0; 
      
    // loop to find the sum in the range 
    for (l += N_2, r += N_2; l < r; l >>= 1, r >>= 1) 
    { 
        if ((l & 1) > 0)  
            res += tree[l++]; 
      
        if ((r & 1) > 0)  
            res += tree[--r];
    } 
    return res; 
  } 

  static int nextPowerOf2(int n) 
  { 
      int count = 0; 

      // First n in the below  
      // condition is for the  
      // case where n is 0 
      if (n > 0 && (n & (n - 1)) == 0) 
          return n; 

      while(n != 0) 
      { 
          n >>= 1; 
          count += 1; 
      } 

      return 1 << count; 
  }

  static int dist(int i, int j){
    return Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1]- points[j][1]);
  } 
}