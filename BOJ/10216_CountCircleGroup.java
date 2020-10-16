
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

/*
 * 1 < = N <= 3000
 * 인접 확인 : N^2
 * 유니온 : 모든 정점 N * 인접 리스트 탐색 E ( <= N*(N-1)/2 == N^2 ) : N^3 
 * 따라서 O(N^3) : 3000^3 == 9,000,000,000 이하 수행 시간
 * 시간 제한 : 8초
 */


public class Main {

	static class Info {
		int y, x, r;

		public Info(int y, int x, int r) {
			this.y = y;
			this.x = x;
			this.r = r;
		}
	}

	static int T, N, x, y, r, check[], ans;
	static Info map[];
	static List<Integer> adj[];

	static void dfs(int p, int n) {
		for (int i = 0; i < adj[n].size(); i++) {
			int cn = adj[n].get(i);
			if (check[cn] == 0) {
				check[cn] = n;
				dfs(n, cn);
			}
		}
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st;

		T = Integer.parseInt(str);

		for (int t = 0; t < T; t++) {
			str = br.readLine();
			N = Integer.parseInt(str);

			map = new Info[N + 1];
			adj = new List[N + 1];
			for (int i = 1; i <= N; i++)
				adj[i] = new ArrayList<>();
			check = new int[N + 1];
			ans = 0;

			for (int i = 1; i <= N; i++) {
				str = br.readLine();
				st = new StringTokenizer(str);

				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				r = Integer.parseInt(st.nextToken());

				map[i] = new Info(y, x, r);
			}

			for (int i = 1; i <= N - 1; i++) {
				for (int j = i + 1; j <= N; j++) {
					double dy = Math.pow(Math.abs(map[i].y - map[j].y), 2);
					double dx = Math.pow(Math.abs(map[i].x - map[j].x), 2);
					double dr = Math.pow((map[i].r + map[j].r), 2);

					if (dr >= dy + dx) {
						adj[i].add(j);
						adj[j].add(i);
					}
				}
			}

			for (int i = 1; i <= N; i++) {
				if (check[i] == 0) {
					check[i] = i;
					dfs(i, i);
					ans++;
				}
			}
			
			System.out.println(ans);
		}
	}
}
