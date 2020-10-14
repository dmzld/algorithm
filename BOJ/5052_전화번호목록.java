import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Main {

	static int T, N;
	static String num[];

	static boolean cmp() {
		for (int i = 0; i < N - 1; i++) {
			String s1 = num[i], s2 = num[i + 1];

			if (s1.length() < s2.length())
				if (s2.startsWith(s1))
					return false;
		}

		return true;
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().trim();

		T = Integer.parseInt(str);
		for (int t = 0; t < T; t++) {
			str = br.readLine().trim();
			N = Integer.parseInt(str);

			num = new String[N];

			for (int i = 0; i < N; i++) {
				str = br.readLine().trim();
				num[i] = str;
			}

			Arrays.sort(num);
			
			if (cmp())
				System.out.println("YES");
			else
				System.out.println("NO");
		}

	}
}
