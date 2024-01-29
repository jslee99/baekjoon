import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Node{
    int r;
    int c;
    int L;

    public Node(int r, int c, int l) {
        this.r = r;
        this.c = c;
        L = l;
    }
}

class Solution{
    static int T;
    static int n;
    static int m;
    static int sr;
    static int sc;
    static int L;
    static int[][] map = new int[55][55];
    static int[][] visit = new int[55][55];
    static int ans;
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};
    static Queue<Node> q = new LinkedList<>();
    //dr, dc array
    static int[] getDir(int x){
        int[] dir;
        switch (x){
            case 1:
                dir = new int[]{0, 1, 2, 3};
                break;
            case 2:
                dir = new int[]{0, 2};
                break;
            case 3:
                dir = new int[]{1, 3};
                break;
            case 4:
                dir = new int[]{0, 1};
                break;
            case 5:
                dir = new int[]{1, 2};
                break;
            case 6:
                dir = new int[]{2, 3};
                break;
            case 7:
                dir = new int[]{0, 3};
                break;
            default:
                dir =null;
        }
        return dir;
    }

    static boolean isIn(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    static Boolean canGo(int dir, int dest){
        if(dest == 0)
            return false;

        switch (dir){
            case 0:
                if(dest == 1 || dest == 2 || dest == 5 || dest == 6)
                    return true;
                else
                    return false;
            case 1:
                if(dest == 1 || dest == 3 || dest == 6 || dest == 7)
                    return true;
                else
                    return false;
            case 2:
                if(dest == 1 || dest == 2 || dest == 4 || dest == 7)
                    return true;
                else
                    return false;
            case 3:
                if(dest == 1 || dest == 3 || dest == 4 || dest == 5)
                    return true;
                else
                    return false;
            default:
                return null;
        }
    }
    static void dfs(int r, int c, int t){
        visit[r][c] = t;
        int[] dir = getDir(map[r][c]);
        for(int d : dir){
            int new_r = r + dr[d], new_c = c + dc[d];
            if(isIn(new_r, new_c) && canGo(d, map[new_r][new_c]) && visit[new_r][new_c] == -1){
                dfs(new_r, new_c, t + 1);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken()); sr = Integer.parseInt(st.nextToken()); sc = Integer.parseInt(st.nextToken()); L = Integer.parseInt(st.nextToken());
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine(), " ");
                for(int j = 0; j < m; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                    visit[i][j] = -1;
                }
            }
            ans = 0;

            q.add(new Node(sr, sc, 1));
            while(!q.isEmpty()){
                Node x = q.poll();
                if(visit[x.r][x.c] != -1)
                    continue;

                visit[x.r][x.c] = x.L;
                int[] dir = getDir(map[x.r][x.c]);
                for(int d : dir){
                    int new_r = x.r + dr[d], new_c = x.c + dc[d];
                    if(isIn(new_r, new_c) && canGo(d, map[new_r][new_c]) && visit[new_r][new_c] == -1){
                        q.add(new Node(new_r, new_c, x.L + 1));
                    }
                }
            }

            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(visit[i][j] != -1 && visit[i][j] <= L)
                        ans++;
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }
}