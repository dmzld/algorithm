import java.io.*;
import java.util.*;

public class Main {

	static int N, M, check[];
	static List<Integer> map[];

	static int dfs(int n, int cnt) {
		if (cnt >= 4)
			return 5;

		int res = cnt;

		for (int i = 0; i < map[n].size(); i++) {
			int nn = map[n].get(i);
			if (check[nn] == 0) {
				check[nn]++;
				res = Math.max(res, dfs(nn, cnt + 1));
				check[nn]--;
			}
		}

		return res;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		map = new List[N];
		for (int i = 0; i < N; i++)
			map[i] = new ArrayList<Integer>();
		check = new int[N];

		int a = 0, b = 0;
		for (int i = 0; i < M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			map[a].add(b);
			map[b].add(a);
		}

		for (int i = 0; i < N; i++) {
			check[i]++;
			if(dfs(i, 0) >= 5) {
				System.out.println(1);
				return;
			}
			check[i]--;
		}

		System.out.println(0);
	}
}
