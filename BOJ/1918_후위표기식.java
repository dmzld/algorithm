import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Main {

	static int priority(char c) {
		switch (c) {
		case '+':
		case '-':
			return 1;
		case '/':
		case '*':
			return 2;
		default:
			return 0;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine().trim();

		String ans = "";
		Stack<Character> tmp = new Stack<>();

		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			int p = priority(c);

			if (c >= 'A' && c <= 'Z') {
				ans += c;
			}
			else if (c == '*' || c == '/' || c == '+' || c == '-') {
				while (!tmp.empty() && priority(tmp.peek()) >= p)
					ans += tmp.pop();

				tmp.add(c);
			}
			else if (c == '(') {
				tmp.add(c);
			}
			else if (c == ')') {
				while (!tmp.empty() && tmp.peek() != '(')
					ans += tmp.pop();

				if (!tmp.empty())
					tmp.pop(); // remove '('
			}
		}

		while (!tmp.empty())
			ans += tmp.pop();

		System.out.println(ans);
	}
}
