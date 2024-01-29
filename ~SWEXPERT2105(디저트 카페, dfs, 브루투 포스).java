import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Solution{
    static int T;
    static int n, ans;
    static int[][] map = new int[25][25];
    static int[] dr = {1, 1, -1, -1};
    static int[] dc = {1, -1, -1, 1};

    static boolean isIn(int r, int c){
        return  r >= 0 && r < n && c >= 0 && c < n;
    }

    static void dfs(final int sr, final int sc, int r, int c, int d, Set<Integer> set) {
        if(!isIn(r, c)){
            return;
        }

        if(set.contains(map[r][c])){
            return;
        }else{
            set.add(map[r][c]);
        }

        if(sr == r && sc == c){
            if(set.size() == 6){
                int aaa = 1;
            }
            ans = Math.max(ans, set.size());
            set.remove(Integer.valueOf(map[r][c]));
            return;
        }

        for (int k = 0; k < 2; k++) {
            int new_d = (d + k) % 4;
            if(k == 1 && new_d == 0)
                continue;
            int new_r = r + dr[new_d], new_c = c + dc[new_d];
            dfs(sr, sc, new_r, new_c, new_d, set);
        }
        set.remove(Integer.valueOf(map[r][c]));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            n = Integer.parseInt(br.readLine());
            ans = -1;
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    Set<Integer> set = new HashSet<>();
//                    List<Integer> set = new ArrayList<>();
                    dfs(i, j, i + dr[0], j + dc[0], 0, set);
                }
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }
}