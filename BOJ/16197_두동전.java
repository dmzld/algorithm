import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static class Info {
		int y1, x1, y2, x2;

		public Info(int y1, int x1, int y2, int x2) {
			this.y1 = y1;
			this.x1 = x1;
			this.y2 = y2;
			this.x2 = x2;
		}
	}

	static int N, M, map[][], check[][][][];
	static int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
	static Queue<Info> q = new LinkedList<>();

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		check = new int[N][M][N][M];
		Info sp = new Info(-1, -1, -1, -1);

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == 'o') {
					if (sp.y1 == -1) {
						sp.y1 = i;
						sp.x1 = j;
					} else {
						sp.y2 = i;
						sp.x2 = j;
					}
				}
			}
		}

		q.offer(sp);
		check[sp.y1][sp.x1][sp.y2][sp.x2]++;

		for (int i = 0; i < 10; i++) {
			int qSize = q.size();

			for (int j = 0; j < qSize; j++) {
				int y1 = q.peek().y1, x1 = q.peek().x1, y2 = q.peek().y2, x2 = q.peek().x2;
				q.poll();

				for (int k = 0; k < 4; k++) {
					int ny1 = y1 + dy[k], nx1 = x1 + dx[k], ny2 = y2 + dy[k], nx2 = x2 + dx[k];

					if (ny1 >= 0 && ny1 < N && nx1 >= 0 && nx1 < M && map[ny1][nx1] == '#') {
						ny1 = y1;
						nx1 = x1;
					}
					if (ny2 >= 0 && ny2 < N && nx2 >= 0 && nx2 < M && map[ny2][nx2] == '#') {
						ny2 = y2;
						nx2 = x2;
					}

					if (((ny1 < 0 || ny1 >= N || nx1 < 0 || nx1 >= M) && (ny2 >= 0 && ny2 < N && nx2 >= 0 && nx2 < M))
							|| ((ny1 >= 0 && ny1 < N && nx1 >= 0 && nx1 < M)
									&& (ny2 < 0 || ny2 >= N || nx2 < 0 || nx2 >= M))) {
						System.out.println(i + 1);
						return;
					}

					if ((ny1 >= 0 && ny1 < N && nx1 >= 0 && nx1 < M) && (ny2 >= 0 && ny2 < N && nx2 >= 0 && nx2 < M)
							&& check[ny1][nx1][ny2][nx2] == 0) {
						q.offer(new Info(ny1, nx1, ny2, nx2));
						check[ny1][nx1][ny2][nx2]++;
					}
				}
			}
		}

		System.out.println(-1);
	}
}
