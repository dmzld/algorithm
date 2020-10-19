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

	static int W, H, D, map[][], check[][][], ans;
	static Queue<Info> q;
	static int dy[] = { 0, 0, -1, 1 }, dx[] = { -1, 1, 0, 0 };

	static int bfs() {
		check = new int[H][W][(int) Math.pow(2, D)];
		check[q.peek().y][q.peek().x][0]++;
		int res = 0;

		while (!q.isEmpty()) {
			int qSize = q.size();

			for (int i = 0; i < qSize; i++) {
				int y = q.peek().y, x = q.peek().x, cnt = q.peek().cnt;
				q.poll();

				if (cnt == Math.pow(2, D) - 1)
					return res;

				for (int j = 0; j < 4; j++) {
					int ny = y + dy[j], nx = x + dx[j], ncnt = cnt;

					if (ny < 0 || ny >= H || nx < 0 || nx >= W || map[ny][nx] == 'x' || check[ny][nx][cnt] > 0)
						continue;

					if (map[ny][nx] >= '1' && map[ny][nx] <= (char) (D + '0'))
						ncnt = cnt | 1 << (int) (map[ny][nx] - '1');

					check[ny][nx][ncnt]++;
					q.offer(new Info(ny, nx, ncnt));
				}
			}
			res++;
		}

		return -1;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str;
		StringTokenizer st;

		while (true) {
			str = br.readLine();
			st = new StringTokenizer(str);

			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());

			if (W == 0 && H == 0)
				break;

			// init with input
			map = new int[H][W];
			q = new LinkedList<>();
			D = 0; // 먼지 개수
			ans = 0;

			for (int i = 0; i < H; i++) {
				str = br.readLine().trim();
				for (int j = 0; j < W; j++) {
					map[i][j] = str.charAt(j);

					if (map[i][j] == 'o') {
						q.offer(new Info(i, j, 0));
					} else if (map[i][j] == '*') {
						D++;
						map[i][j] = (char) (D + '0');
					}
				}
			}

			if (D == 0)
				System.out.println(0);
			else
				System.out.println(bfs());
		}

	}
}
