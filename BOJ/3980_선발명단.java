package temp;

import java.io.*;
import java.util.*;

public class Main {

	static int T, map[][], check[], ans;

	static void assign(int idx, int res) {
		if (idx >= 11) {
			ans = Math.max(ans, res);
			return;
		}

		for (int i = 0; i < 11; i++) {
			if (check[i] < 1 && map[idx][i] != 0) {
				check[i]++;
				assign(idx + 1, res + map[idx][i]);
				check[i]--;
			}
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();

		T = Integer.parseInt(str);

		for (int t = 0; t < T; t++) {

			ans = 0;
			map = new int[11][11];
			check = new int[11];

			for (int i = 0; i < 11; i++) {
				str = br.readLine();
				StringTokenizer st = new StringTokenizer(str);
				for (int j = 0; j < 11; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			assign(0, 0);
			
			System.out.println(ans);
		}
	}
}
