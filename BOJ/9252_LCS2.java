import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static String s1, s2;
	static int check[][] = new int[1001][1001];

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);

		s1 = st.nextToken();
		str = br.readLine();
		st = new StringTokenizer(str);
		s2 = st.nextToken();

		int l1 = s1.length(), l2 = s2.length();

		for (int i = 1; i <= l1; i++) {
			for (int j = 1; j <= l2; j++) {
				if (s1.charAt(i - 1) == s2.charAt(j - 1))
					check[i][j] = check[i - 1][j - 1] + 1;
				else
					check[i][j] = Math.max(check[i - 1][j], check[i][j - 1]);
			}
		}

		System.out.println(check[l1][l2]);

		List<Character> ans = new ArrayList<Character>();
		int i = l1, j = l2;

		while (i > 0 && j > 0) {
			if (check[i][j] == check[i - 1][j])
				i--;
			else if (check[i][j] == check[i][j - 1])
				j--;
			else {
				ans.add(s1.charAt(i - 1));
				i--;
				j--;
			}
		}

		for (int k = ans.size() - 1; k >= 0; k--) {
			System.out.print(ans.get(k));
		}
	}
}
