import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	
	static int N, M, a, b, ans = 0, check[];
	static List<Integer> bigger[], smaller[];
	
	static int sDfs(int n) {
		int K = smaller[n].size(), res = 0;
		
		if(K == 0)
			return 1;
		
		for(int i=0; i<K; i++) {
			int nn = smaller[n].get(i);
			if(check[nn] == 0) {
				check[nn]++;
				res += sDfs(nn);
			}
		}
			
				
		return res + 1;
	}
	
	static int bDfs(int n) {
		int K = bigger[n].size(), res = 0;
		
		if(K == 0)
			return 1;
		
		for(int i=0; i<K; i++) {
			int nn = bigger[n].get(i);
			if(check[nn] == 0) {
				check[nn]++;
				res += bDfs(nn);
			}
		}
			

		return res + 1;
	}
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		bigger = new List[N + 1];
		smaller = new List[N + 1];
		
		for(int i=1; i<=N; i++) {
			bigger[i] = new ArrayList<Integer>();
			smaller[i] = new ArrayList<Integer>();
		}
			
		for(int i=0; i<M; i++) {
			str = br.readLine();
			st = new StringTokenizer(str);
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			
			bigger[a].add(b);
			smaller[b].add(a);
		}

		for(int i=1; i<=N; i++){
			int res = 0;
			
			check = new int[N + 1];
			if(smaller[i].size() > 0) {
				check[i]++;
				res += sDfs(i) - 1;
			}

			check = new int[N + 1];
			if(bigger[i].size()>0) {
				check[i]++;
				res += bDfs(i) - 1;
			}
			
			if(res == N - 1)
				ans++;
			
		}
		
		System.out.println(ans);
	}
}
