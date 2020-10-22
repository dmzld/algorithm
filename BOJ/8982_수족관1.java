import java.io.*;
import java.util.*;

public class Main {

	static class Info {
		int h, l;

		public Info(int h, int l) {
			super();
			this.h = h;
			this.l = l;
		}
	}

	static int N, K, y1, y2, x1, x2, mx, h, ans;
	static Info water[] = new Info[40001];

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st;

		N = Integer.parseInt(str);

		str = br.readLine(); // 0, 0

		for (int i = 0; i < (N - 2) / 2; i++) {
			str = br.readLine(); // x1, y1
			st = new StringTokenizer(str);
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());

			str = br.readLine(); // x2, y2
			st = new StringTokenizer(str);
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());

			for (int j = x1; j < x2; j++)
				water[j] = new Info(y1, 0); // y1 == y2
		}
		str = br.readLine(); // x, 0
		st = new StringTokenizer(str);
		mx = Integer.parseInt(st.nextToken());

		str = br.readLine();
		K = Integer.parseInt(str);

		for (int i = 0; i < K; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());

			int h = y1;

			for (int j = x1; j >= 0; j--) {
				h = Math.min(water[j].h, h); // 높이 조정
				water[j].l = Math.max(h, water[j].l); // 물 빠짐
			}

			h = y1;
			for (int j = x1 + 1; j < mx; j++) {
				h = Math.min(water[j].h, h); // 높이 조정
				water[j].l = Math.max(h, water[j].l); // 물 빠짐
			}
		}

		ans = 0;
		for (int i = 0; i < mx; i++) {
			ans += (water[i].h - water[i].l);
		}
			
		System.out.println(ans);
	}
}
