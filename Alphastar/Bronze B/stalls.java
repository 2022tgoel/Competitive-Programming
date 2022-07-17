import java.util.*;
import java.io.*;
public class Stalls {
	public static void main(String[] args) throws IOException{
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(f.readLine());
		Integer[] cows = new Integer[N];
		for (int i=0; i<N; i++) {
			cows[i] = Integer.parseInt(st.nextToken());
		}
		Integer[] reqs = new Integer[N];
		st = new StringTokenizer(f.readLine());
		for (int i=0; i<N; i++) {
			reqs[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(cows, new comp());
		Arrays.sort(reqs, new comp());
		int p = 0;
		int ans = 1;
		for (int i=0; i<N; i++) {
			if (p == i && cows[i] > reqs[p]) ans = 0;
			while (p<N && cows[i] <= reqs[p]) {
				p++;
			}
			ans *= p-i;
		}
		System.out.println(ans);
	}
	static class comp implements Comparator<Integer>{
		@Override
		public int compare(Integer o1, Integer o2) {
			return o2-o1;
		}
	}
}
