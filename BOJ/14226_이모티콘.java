import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static class Info {
		int cnt, clip;

		Info(int cnt, int clip) {
			this.cnt = cnt;
			this.clip = clip;
		}
	}

	static int S, check[][] = new int[1001][1001], ans = 0;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();

		S = Integer.parseInt(str);

		Queue<Info> q = new LinkedList<Info>();
		q.add(new Info(1, 0));
		check[1][0]++;

		while (!q.isEmpty()) {
			int qSize = q.size();
			for (int i = 0; i < qSize; i++) {
				int cnt = q.peek().cnt, clip = q.peek().clip;
				q.poll();

				if (cnt == S) {
					System.out.println(ans);
					return;
				}

				if (clip > 0 && cnt+clip <= 1000 && check[cnt + clip][clip] == 0) {
					q.add(new Info(cnt + clip, clip));
					check[cnt + clip][clip]++;
				}

				if (check[cnt][cnt] == 0) {
					q.add(new Info(cnt, cnt));
					check[cnt][cnt]++;
				}

				if (cnt > 0 && check[cnt - 1][clip] == 0) {
					q.add(new Info(cnt - 1, clip));
					check[cnt - 1][clip]++;
				}

			}
			ans++;
		}
	}
}
