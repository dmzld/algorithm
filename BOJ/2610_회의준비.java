import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M, a, b, check[], res[];
	static int dis[][];
	static List<Integer> ans = new ArrayList<>();

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());

		check = new int[N + 1];
		res = new int[N + 1];
		dis = new int[N + 1][N + 1];

		str = br.readLine();
		st = new StringTokenizer(str);
		M = Integer.parseInt(st.nextToken());

		for (int i = 0; i < M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			dis[a][b] = 1;
			dis[b][a] = 1;
		}

    // Floyd Warshall
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i != j && dis[i][k] != 0 && dis[k][j] != 0
							&& (dis[i][j] == 0 || dis[i][j] > dis[i][k] + dis[k][j]))
						dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				res[i] = Math.max(res[i], dis[i][j]);

		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {
				check[i]++;
				int num = i;
				for (int j = 1; j <= N; j++) {
					if (dis[i][j] > 0) {
						check[j]++;
						if (res[num] > res[j])
							num = j;
					}
				}
				ans.add(num);
			}
		}

		Collections.sort(ans);

		System.out.println(ans.size());
		for (int i = 0; i < ans.size(); i++)
			System.out.println(ans.get(i));

	}
}
