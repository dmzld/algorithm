import java.io.*;
import java.util.*;

public class Main {

	static class Info {
		int y, x, d;

		public Info(int y, int x, int d) {
			super();
			this.y = y;
			this.x = x;
			this.d = d;
		}

	}

	static int N, K, map[][];
	static Info O[];
	static int dy[] = { 0, 0, -1, 1 }, dx[] = { 1, -1, 0, 0 }; // 위아래왼쪽오른쪽
	static List<Integer> state[][];

	static int game() {
		for (int t = 1; t <= 1000; t++) {

			for (int i = 1; i <= K; i++) { // horse
				int y = O[i].y, x = O[i].x, d = O[i].d;

				if (state[y][x].get(0) != i) // 가장 아래에 있는 말만 이동 가능
					continue;

				int ny = y + dy[d], nx = x + dx[d];

				// 범위 밖, 파란칸
				if (ny < 1 || ny > N || nx < 1 || nx > N || map[ny][nx] == 2) {
					int nd = d % 2 == 0 ? d + 1 : d - 1; // reverse
					ny = y + dy[nd];
					nx = x + dx[nd];

					// 범위 밖, 파란칸
					if (ny < 1 || ny > N || nx < 1 || nx > N || map[ny][nx] == 2) {
						// 방향만 바꾼다
						O[i].d = nd;
						continue;
					}

					// 하얀칸
					else if (map[ny][nx] == 0) {
						// 순서대로
						for (int j = 0; j < state[y][x].size(); j++) {
							int n = state[y][x].get(j);
							state[ny][nx].add(n);
							O[n].y = ny;
							O[n].x = nx;
							if (j == 0)
								O[n].d = nd; // 바뀐 방향 저장
						}
						state[y][x].clear();
					}
					// 빨간칸
					else if (map[ny][nx] == 1) {
						// 위에서부터
						for (int j = state[y][x].size() - 1; j >= 0; j--) {
							int n = state[y][x].get(j);
							state[ny][nx].add(n);
							O[n].y = ny;
							O[n].x = nx;
							if (j == 0)
								O[n].d = nd; // 바뀐 방향 저장
						}
						state[y][x].clear();
					}
				}
				// 하얀칸
				else if (map[ny][nx] == 0) {
					// 순서대로
					for (int j = 0; j < state[y][x].size(); j++) {
						int n = state[y][x].get(j);
						state[ny][nx].add(n);
						O[n].y = ny;
						O[n].x = nx;
					}
					state[y][x].clear();
				}
				// 빨간칸
				else if (map[ny][nx] == 1) {
					// 위에서부터
					for (int j = state[y][x].size() - 1; j >= 0; j--) {
						int n = state[y][x].get(j);
						state[ny][nx].add(n);
						O[n].y = ny;
						O[n].x = nx;
					}
					state[y][x].clear();
				}

				if (state[ny][nx].size() >= 4)
					return t;
			} // i

		} // t

		return -1;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		// init
		map = new int[N + 1][N + 1];
		O = new Info[K + 1];
		state = new List[N + 1][N + 1];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				state[i][j] = new ArrayList<>();

		// input
		for (int i = 1; i <= N; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// input & init
		for (int i = 1; i <= K; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			int y = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken()),
					d = Integer.parseInt(st.nextToken());
			O[i] = new Info(y, x, d - 1);

			state[y][x].add(i);
		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (state[i][j].size() >= 4) {
					System.out.print(0);
				}

		System.out.println(game());
	}
}
