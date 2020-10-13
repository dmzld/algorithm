import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static class Wood {
		int y1, y2, y3, x1, x2, x3;

		public Wood(int y1, int y2, int y3, int x1, int x2, int x3) {
			this.y1 = y1;
			this.y2 = y2;
			this.y3 = y3;
			this.x1 = x1;
			this.x2 = x2;
			this.x3 = x3;
		}
	}

	public static class Pos {
		int y, x;

		public Pos(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	static int N;
	static List<Pos> B = new ArrayList<>();
	static char map[][] = new char[50][50];
	static int check[][][] = new int[50][50][2]; // [2] : horizon or vertical
	static int dy[] = { 0, 0, -1, 1 }, dx[] = { -1, 1, 0, 0 };

	static int bfs() {

		int ans = 0;
		Queue<Wood> q = new LinkedList<Wood>();

		q.offer(new Wood(B.get(0).y, B.get(1).y, B.get(2).y, B.get(0).x, B.get(1).x, B.get(2).x));
		if (B.get(0).y == B.get(1).y) // horizon
			check[B.get(1).y][B.get(1).x][1]++;
		else // vertical
			check[B.get(1).y][B.get(1).x][0]++;

		while (!q.isEmpty()) {
			int qSize = q.size();

			for (int i = 0; i < qSize; i++) {
				Wood w = q.poll();
				int y1 = w.y1, y2 = w.y2, y3 = w.y3;
				int x1 = w.x1, x2 = w.x2, x3 = w.x3;

				if (map[y1][x1] == 'E' && map[y2][x2] == 'E' && map[y3][x3] == 'E')
					return ans;

				int hv = y1 == y2 ? 1 : 0; // horizon or vertical

				// U, D, R, L
				for (int j = 0; j < 4; j++) {
					int ny1 = y1 + dy[j], ny2 = y2 + dy[j], ny3 = y3 + dy[j];
					int nx1 = x1 + dx[j], nx2 = x2 + dx[j], nx3 = x3 + dx[j];

					if (ny1 < 0 || ny1 >= N || ny2 < 0 || ny2 >= N || ny3 < 0 || ny3 >= N || nx1 < 0 || nx1 >= N
							|| nx2 < 0 || nx2 >= N || nx3 < 0 || nx3 >= N)
						continue;
					if (map[ny1][nx1] == '1' || map[ny2][nx2] == '1' || map[ny3][nx3] == '1')
						continue;
					if (check[ny2][nx2][hv] == 1)
						continue;

					q.offer(new Wood(ny1, ny2, ny3, nx1, nx2, nx3));
					check[ny2][nx2][hv]++;
				}

				// Rotate
				if (y2 >= 1 && y2 < N - 1 && x2 >= 1 && x2 < N - 1) { // check range
					boolean avail = true;
					
					// check map
					for (int j = y2 - 1; j <= y2 + 1; j++)
						for (int k = x2 - 1; k <= x2 + 1; k++)
							if (map[j][k] == '1')
								avail = false;
					
					if(!avail)
						continue;

					int ny1, ny2 = y2, ny3, nx1, nx2 = x2, nx3;

					if (hv == 1) { // change h to v
						ny1 = ny2 - 1;
						ny3 = ny2 + 1;
						nx1 = nx2;
						nx3 = nx2;
					} else { // change v to h
						ny1 = ny2;
						ny3 = ny2;
						nx1 = nx2 - 1;
						nx3 = nx2 + 1;
					}

					hv = hv == 1 ? 0 : 1;

					if (check[ny2][nx2][hv] == 0) {
						q.offer(new Wood(ny1, ny2, ny3, nx1, nx2, nx3));
						check[ny2][nx2][hv]++;
					}
				}
			}
			ans++;
		}

		// can't be arrived
		return 0;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());

		for (int i = 0; i < N; i++) {
			str = br.readLine();

			for (int j = 0; j < N; j++) {
				map[i][j] = str.charAt(j);

				if (map[i][j] == 'B') {
					B.add(new Pos(i, j));
				}
			}
		}
		
		System.out.println(bfs());
	}
}
