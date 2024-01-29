import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
    static int n, m, r, c, d;
    //북 동 남 서
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};
    // 0 no clean, 1 wall, 2 clean
    static int[][] map = new int[60][60];

    static boolean isAllClean(int r, int c){
        for(int d = 0; d < 4; d++){
            int new_r = r + dr[d], new_c = c + dc[d];
            if(map[new_r][new_c] == 1)
                continue;
            if(map[new_r][new_c] == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken()); c = Integer.parseInt(st.nextToken()); d = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j = 0; j < m; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        label:while(true){
            map[r][c] = 2;

            if(isAllClean(r, c)){
                int revDir = (d + 2) % 4;
                int new_r = r + dr[revDir], new_c = c + dc[revDir];
                if(map[new_r][new_c] == 1)
                    break;
                else{
                    r = new_r; c = new_c;
                }
            }else{
                for(int k = 3; k >= 0; k--){
                    int new_d = (d + k) % 4;
                    int new_r = r + dr[new_d], new_c = c + dc[new_d];
                    if(map[new_r][new_c] == 0){
                        r = new_r; c = new_c; d = new_d;
                        continue label;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(map[i][j] == 2)
                    ans++;
        System.out.println(ans);

    }
}