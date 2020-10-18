import java.io.*;
import java.util.*;

/*
 * 1. R, G 배양액 조합을 DFS로 구한다 : choice()
 * 2. 조합에 따라 BFS로 최대 꽃이 피는 개수를 구한다 : bfs()
 * 3. 배양액이 도달할 수 없는 경우은
 * 	호수 : map[][] == 0
 * 	이전 phase에 탐색된 공간(현재 phase에 탐색된 공간은 가능) : bCheck[][] > 0 && cCheck[][] == 0
 * 	꽃이 핀 공간 : bCheck[][] == 5
 * 
 * 조합 부분과 확산 부분을 개선하면 성능 개선 가능할 듯
 */

public class Main {

	static class Info {
		int y, x, color; // 3 == Green, 4 == Red

		public Info(int y, int x, int color) {
			this.y = y;
			this.x = x;
			this.color = color;
		}
	}

	static int N, M, G, R, ans = 0;
	static int map[][], check[][], bCheck[][], cCheck[][];
	static List<Info> sp = new ArrayList<>();
	static Queue<Info> q = new LinkedList<>();
	static int dy[] = { 0, 0, -1, 1 };
	static int dx[] = { -1, 1, 0, 0 };

	// 배양의 위치를 정한다
	static void choice(int n, int g, int r) {

		if (g + r == G + R) { // 모든 배양액 자리 선정 끝
			bfs();
			return;
		}

		int y = sp.get(n).y, x = sp.get(n).x;

		if (sp.size() - (n + 1) >= (G + R) - (g + r)) {
			choice(n + 1, g, r);
		}
		if (g < G) {
			check[y][x] = 3;
			choice(n + 1, g + 1, r);
		}
		if (r < R) {
			check[y][x] = 4;
			choice(n + 1, g, r + 1);
		}

		check[y][x] = 0;
	}

	// 정해진 배양액 시작점에 따른 BFS
	static void bfs() {
		int res = 0;
		bCheck = new int[N][M]; // check in bfs, 0 == nothing, over 0 == visited
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				bCheck[i][j] = check[i][j]; // value is color
				if (check[i][j] > 0) {
					q.add(new Info(i, j, check[i][j])); // sp
				}
			}

		int cnt = 0;
		while (!q.isEmpty()) {
			// init cCheck in current phase
			for (int i = 0; i < N; i++)
				Arrays.fill(cCheck[i], 0);
			// one phase
			int qSize = q.size();

			for (int i = 0; i < qSize; i++) {
				int y = q.peek().y, x = q.peek().x, color = q.peek().color;
				q.poll();

				if (bCheck[y][x] == 5) // 전 단계에서 꽃이 핀 곳이면 배양액은 사라진다
					continue;

				for (int j = 0; j < 4; j++) {
					int cy = y + dy[j], cx = x + dx[j];

					if (cy < 0 || cy >= N || cx < 0 || cx >= M || map[cy][cx] == 0 // 범위 밖, 호수
							|| (bCheck[cy][cx] > 0 && cCheck[cy][cx] == 0) // 이전 phase에 탐색된 위치
							|| cCheck[cy][cx] == color) // 이미 같은 배양액 도달
						continue;

					if ((color == 3 && cCheck[cy][cx] == 4) || (color == 4 && cCheck[cy][cx] == 3)) { // 꽃이 필 때
						res++;
						bCheck[cy][cx] = 5; // flower
						cCheck[cy][cx] = 0; // 이번 phase에서 다시 접근할 수 없게
						continue;
					}

					bCheck[cy][cx]++; // 탐색한 공간
					cCheck[cy][cx] = color; // 현재 phase에서 color 배양액 도달
					q.add(new Info(cy, cx, color));
				}
			}
			cnt++;
		}

		if (ans < res)
			ans = res;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		map = new int[N][M];
		check = new int[N][M];
		cCheck = new int[N][M];

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 2)
					sp.add(new Info(i, j, 0));
			}
		}

		choice(0, 0, 0);

		System.out.println(ans);
	}
}
