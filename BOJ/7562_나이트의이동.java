import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static class Info{
		int y, x;
		
		public Info(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}
	
	static int T, I, map[][], check[][], sy, sx, ty, tx, ans;
	final static int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	final static int dy[] = { 2, 1, -1, -2, -2, -1, 1 , 2 };
	
	static void bfs() {
		
		Info cp = null;
		int ny, nx;
		
		Queue<Info> q = new LinkedList<Info>();
		q.offer(new Info(sy, sx));
		check[sy][sx] = 1;
		
		while(!q.isEmpty()) {
			int qSize = q.size();
			
			for(int i=0; i<qSize; i++) {
				cp = q.poll();
				
				if(cp.y == ty && cp.x == tx)
					return;
				
				for(int j=0; j<8; j++) {
					ny = cp.y + dy[j];
					nx = cp.x + dx[j];
					
					if(ny<0 || ny>=I || nx<0 || nx>=I || check[ny][nx] == 1)
						continue;
					
					q.offer(new Info(ny,nx));
					check[ny][nx] = 1;
				}
			}
			ans++;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine().trim());
		
		for(int t=0; t<T; t++) {
			String str = br.readLine();
			StringTokenizer st = new StringTokenizer(str);
			I = Integer.parseInt(st.nextToken());
			
			ans = 0;
			map = new int[I][I];
			check = new int[I][I];
			
			str = br.readLine();
			st = new StringTokenizer(str);
			sy = Integer.parseInt(st.nextToken());
			sx = Integer.parseInt(st.nextToken());
			
			str = br.readLine();
			st = new StringTokenizer(str);
			ty = Integer.parseInt(st.nextToken());
			tx = Integer.parseInt(st.nextToken());
			
			bfs();
			System.out.println(ans);
		}
		
	}

}
