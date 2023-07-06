import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    int N, M, D;
    int[][] init_map = new int[15][15];
    int[][] map = new int[16][15];
    int ans = 0;

    class pair{
        public int first;
        public int second;
        public pair(int x, int y){
            this.first = x;
            this.second = y;
        }
    }

    boolean is_end(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 1) return false;
            }
        }
        return true;
    }

    void simulation(){
        int kill_cnt = 0;
        while(!is_end()){//one round
            ArrayList<pair> enemy_location_lst = new ArrayList<>();
            for(int k = 0; k < M; k++){// at one turret N, k
                if(map[N][k] == 0) continue;

                int my_j = -1, my_i = -1;
                int min_dist = Integer.MAX_VALUE;
                for(int j = 0; j < M; j++){
                    for(int i = 0; i < N; i++){
                        if(map[i][j] == 0) continue;

                        int cur_dist = Math.abs(j - k) + Math.abs(i - N);
                        if(cur_dist <= D && cur_dist < min_dist){
                            min_dist = cur_dist;
                            my_j = j;
                            my_i = i;
                        }
                    }
                }
                if(my_j != -1){
                    enemy_location_lst.add(new pair(my_i, my_j));
                }
            }

            for (int i = 0; i < enemy_location_lst.size(); i++) {
                if(map[enemy_location_lst.get(i).first][enemy_location_lst.get(i).second] == 1){
                    map[enemy_location_lst.get(i).first][enemy_location_lst.get(i).second] = 0;
                    kill_cnt++;
                }
            }

            for(int i = N - 1; i > 0; i--){
                for(int j = 0; j < M; j++){
                    if(map[i - 1][j] == 1){
                        map[i - 1][j] = 0;
                        map[i][j] = 1;
                    }else{
                        map[i - 1][j] = 0;
                        map[i][j] = 0;
                    }
                }
            }
        }

        ans = Math.max(kill_cnt, ans);
    }

    void comb(int selected_num, int selected_idx){
        if(selected_num == 3){
            for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) map[i][j] = init_map[i][j];
            simulation();
            return;
        }

        for(int j = selected_idx + 1; j < M; j++){
            map[N][j] = 2;
            comb(selected_num + 1, j);
            map[N][j] = 0;
        }
    }

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                init_map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        comb(0, -1);

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
