import java.io.*;
import java.util.*;

public class Main {

	static class Info {
		int y, x, cnt;

		public Info(int y, int x, int cnt) {
			this.y = y;
			this.x = x;
			this.cnt = cnt;
		}
	}

	static int N, M, K, dp[][][]; // memoization
	static char map[][];
	static String words;
	static int dy[] = { 0, 0, -1, 1 }, dx[] = { -1, 1, 0, 0 };
	static int ans;

	static int dfs(int y, int x, int idx) {
		if (idx >= words.length())
			return 1;
		
		if (dp[y][x][idx] != -1)
			return dp[y][x][idx];


		dp[y][x][idx] = 0;
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k <= K; k++) {
				int ny = y + dy[i] * k, nx = x + dx[i] * k;

				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;

				if (map[ny][nx] == words.charAt(idx)) {
					dp[y][x][idx] += dfs(ny, nx, idx + 1);
				}
			}
		}
		return dp[y][x][idx];
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new char[N][M];

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = str.charAt(j);
			}
		}

		words = br.readLine();
		dp = new int[N][M][words.length()];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				Arrays.fill(dp[i][j], -1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == words.charAt(0)) {
					ans += dfs(i, j, 1);
				}
			}
		}

		System.out.println(ans);
	}
}
