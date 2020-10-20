import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static class Info {
		int y, x;

		public Info(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}

	}

	static int T, N, check[];
	static Info v[];
	static double ans;

	static void dfs(int cnt, int idx) {
		if (cnt == N / 2) {
			double y = 0, x = 0;
			for (int i = 0; i < N; i++) {
				if (check[i] == 1) {
					y -= v[i].y;
					x -= v[i].x;
				} else {
					y += v[i].y;
					x += v[i].x;
				}
			}

			ans = Math.min(ans, Math.sqrt(y * y + x * x));
			return;
		}

		if (idx >= N)
			return;

		dfs(cnt, idx + 1);

		check[idx]++;
		dfs(cnt + 1, idx + 1);
		check[idx]--;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st;

		T = Integer.parseInt(str);

		for (int t = 0; t < T; t++) {
			str = br.readLine();
			N = Integer.parseInt(str);
			v = new Info[N];
			check = new int[N];
			ans = Double.MAX_VALUE;

			for (int i = 0; i < N; i++) {
				str = br.readLine();
				st = new StringTokenizer(str);
				v[i] = new Info(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}

			dfs(0, 0);

			System.out.println(ans);
		}
	}
}
