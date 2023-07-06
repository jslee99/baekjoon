import java.io.*;
import java.util.*;

public class Main {
    class dragon_curve{
        public int r;
        public int c;
        public int dir;
        public int gen;
        dragon_curve(){};

        dragon_curve(int r, int c, int dir, int gen) {
            this.r = r;
            this.c = c;
            this.dir = dir;
            this.gen = gen;
        }
    }



    int n;
    dragon_curve[] dc_lst = new dragon_curve[20];
    int[] dr = {0, -1, 0, 1};
    int[] dc = {1, 0, -1, 0};
    boolean[][] map = new boolean[101][101];

    boolean is_dragon_square(int r, int c){
        return map[r][c] && map[r][c + 1] && map[r + 1][c] && map[r + 1][c + 1];
    }

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            dc_lst[i] = new dragon_curve();
            dc_lst[i].c = Integer.parseInt(st.nextToken());
            dc_lst[i].r = Integer.parseInt(st.nextToken());
            dc_lst[i].dir = Integer.parseInt(st.nextToken());
            dc_lst[i].gen = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < n; i++){
            ArrayList<Integer> dir_lst = new ArrayList<>();
            dir_lst.add(dc_lst[i].dir);
            for(int gen = 1; gen <= dc_lst[i].gen; gen++){
                for(int j = (int)Math.pow(2, gen - 1) - 1; j >= 0; j--){
                    int dir = (dir_lst.get(j) + 2) % 4;
                    if(--dir < 0){
                        dir = 3;
                    }
                    dir_lst.add(dir);
                }
            }

            int cur_r = dc_lst[i].r;
            int cur_c = dc_lst[i].c;
            map[cur_r][cur_c] = true;
            for(int j = 0; j < dir_lst.size(); j++){
                cur_r += dr[dir_lst.get(j)];
                cur_c += dc[dir_lst.get(j)];
                map[cur_r][cur_c] = true;
            }
        }

        int ans = 0;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++){
                if(is_dragon_square(i, j)){
                    ans++;
                }
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
        return;
    }
}
