import java.io.*;
import java.util.*;

public class Main {

	static class Info {
		int y, x, d, cnt;

		public Info(int y, int x, int d, int cnt) {
			super();
			this.y = y;
			this.x = x;
			this.d = d;
			this.cnt = cnt;
		}
	}

	static int N, sy, sx, sd, ty, tx;
	static char map[][];
	static int D, G, check[][][][];
	static int dy[] = { 1, 0, -1, 0 }, dx[] = { 0, 1, 0, -1 };

	static Queue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
		@Override
		public int compare(Info a, Info b) {
			if (a.cnt < b.cnt)
				return -1;
			else if (a.cnt > b.cnt)
				return 1;
			else
				return 0;
		}
	});

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st;

		N = Integer.parseInt(str);
		map = new char[N][N];

		for (int i = 0; i < N; i++) {
			str = br.readLine();

			for (int j = 0; j < N; j++) {
				map[i][j] = str.charAt(j);
				if (map[i][j] == '!')
					G++;

				if (map[i][j] == '#') {
					if (D == 0) {
						D++;
						sy = i;
						sx = j;
					} else {
						ty = i;
						tx = j;
					}
				}
			}
		}

		check = new int[N][N][G + 1][4];
		for (int i = 0; i < 4; i++) {
			pq.offer(new Info(sy, sx, i, 0));
			check[sy][sx][0][i]++;
		}

		while (!pq.isEmpty()) {
			int y = pq.peek().y, x = pq.peek().x, cnt = pq.peek().cnt, d = pq.peek().d;
			pq.poll();

			if (y == ty && x == tx) {
				System.out.println(cnt);
				return;
			}

			if (map[y][x] == '!') {
				if (cnt + 1 > G)
					continue;
				int nd = (d + 3) % 4;
				int ny = y + dy[nd];
				int nx = x + dx[nd];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] != '*' && check[ny][nx][cnt + 1][nd] == 0) {
					pq.offer(new Info(ny, nx, nd, cnt + 1));
					check[ny][nx][cnt + 1][nd]++;
				}

				nd = (d + 1) % 4;
				ny = y + dy[nd];
				nx = x + dx[nd];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] != '*' && check[ny][nx][cnt + 1][nd] == 0) {
					pq.offer(new Info(ny, nx, nd, cnt + 1));
					check[ny][nx][cnt + 1][nd]++;
				}
			}

			int ny = y + dy[d], nx = x + dx[d];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] != '*' && check[ny][nx][cnt][d] == 0) {
				pq.offer(new Info(ny, nx, d, cnt));
				check[ny][nx][cnt][d]++;
			}
		}
	}
}
