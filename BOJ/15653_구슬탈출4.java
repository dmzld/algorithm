import java.io.*;
import java.util.*;

public class Main {

	static class State {
		int ry, rx, by, bx;

		public State(int ry, int rx, int by, int bx) {
			super();
			this.ry = ry;
			this.rx = rx;
			this.by = by;
			this.bx = bx;
		}
	}

	static class Pos {
		int y, x;

		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}

	static int N, M, check[][][][], sry, srx, sby, sbx, ans;
	static char map[][];
	static Queue<State> q = new LinkedList<>();
	static int dy[] = { 0, 0, -1, 1 }, dx[] = { -1, 1, 0, 0 };

	static Pos rolling(Pos p, int d) {
		while (map[p.y][p.x] != '#') {
			// 굴리다가 빠졌을 때
			if (map[p.y][p.x] == 'O')
				return new Pos(-1, -1);
			p.y += dy[d];
			p.x += dx[d];
		}
		p.y -= dy[d];
		p.x -= dx[d];

		return p;
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new char[N][M];
		check = new int[N][M][N][M];

		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = str.charAt(j);

				if (map[i][j] == 'R') {
					sry = i;
					srx = j;
				} else if (map[i][j] == 'B') {
					sby = i;
					sbx = j;
				}
			}
		}

		q.offer(new State(sry, srx, sby, sbx));
		check[sry][srx][sby][sbx]++;
		ans = 0;

		while (!q.isEmpty()) {
			int qSize = q.size();
			ans++;
			for (int i = 0; i < qSize; i++) {
				int ry = q.peek().ry, rx = q.peek().rx, by = q.peek().by, bx = q.peek().bx;
				q.poll();

				for (int j = 0; j < 4; j++) {
					Pos nr = rolling(new Pos(ry, rx), j);
					Pos nb = rolling(new Pos(by, bx), j);

					// 파란 구슬이 빠졌을 때
					if (nb.y == -1 & nb.x == -1)
						continue;
					// 빨간 구슬만 빠졌을 때
					else if (nr.y == -1 && nr.x == -1 && nb.y != -1 & nb.x != -1) {
						System.out.println(ans);
						return;
					}
					// 둘 다 안빠지고 같은 위치 일때
					else if (nr.y == nb.y && nr.x == nb.x) {
						// 방향과 첫 위치에 따라 선후가 달라짐
						int dry = ry * dy[j], drx = rx * dx[j], dby = by * dy[j], dbx = bx * dx[j];

						// 방향에 대해 뒤에 있던 공을 한칸 뒤로 후퇴시킨다
						if (dry < dby || drx < dbx) {
							nr.y -= dy[j];
							nr.x -= dx[j];
						} else {
							nb.y -= dy[j];
							nb.x -= dx[j];
						}
					}

					// 이미 확인한 위치관계
					if (check[nr.y][nr.x][nb.y][nb.x] > 0)
						continue;

					q.offer(new State(nr.y, nr.x, nb.y, nb.x));
					check[nr.y][nr.x][nb.y][nb.x]++;

				}
			}
		}

		System.out.println(-1);
	}
}
