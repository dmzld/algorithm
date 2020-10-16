package temp;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

/*
 * 1 < = N <= 3000
 * 인접 확인 : N^2
 * 유니온 : 모든 정점 N * 인접 리스트 탐색 E ( <= N*(N-1)/2 == N^2 ) : N^3 
 * 따라서 O(N^3) : 3000^3 == 9,000,000,000 이하 수행 시간
 * 시간 제한 : 8초
 */

public class Main {

	static int N, M, K, map[][], R, C, stk[][];

	static boolean solution() {
		for (int j = 0; j <= N - R; j++)
			for (int k = 0; k <= M - C; k++)
				if (canStick(j, k)) {
					stick(j, k);
					return true;
				}

		return false;
	}

	static boolean canStick(int si, int sj) {
		for (int i = si; i < si + R; i++) {
			for (int j = sj; j < sj + C; j++) {
				if (map[i][j] == 1 && stk[i - si][j - sj] == 1)
					return false;
			}
		}

		return true;
	}

	static void stick(int si, int sj) {
		for (int i = si; i < si + R; i++) {
			for (int j = sj; j < sj + C; j++) {
				if (stk[i - si][j - sj] == 1)
					map[i][j] = 1;
			}
		}
	}

	static void rotate() { // clcok
		int cstk[][] = new int[R][C];

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cstk[i][j] = stk[i][j];

		stk = new int[C][R];

		int tmp = C;
		C = R;
		R = tmp;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				stk[i][j] = cstk[(C - 1) - j][i];
	}

	static int countMap() {
		int ans = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (map[i][j] == 1)
					ans++;

		return ans;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		map = new int[N][M];

		for (int i = 0; i < K; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);

			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());

			stk = new int[R][C];
			for (int j = 0; j < R; j++) {
				str = br.readLine();
				st = new StringTokenizer(str);
				for (int k = 0; k < C; k++) {
					stk[j][k] = Integer.parseInt(st.nextToken());
				}
			}

			for (int r = 0; r < 4; r++) {
				if (solution())
					break;
				else {
					if (r < 3)
						rotate();
				}
			}

		}

		System.out.println(countMap());
	}
}
