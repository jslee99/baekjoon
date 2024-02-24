    import java.io.BufferedReader;
    import java.io.InputStreamReader;
    import java.util.ArrayList;
    import java.util.Comparator;
    import java.util.List;
    import java.util.StringTokenizer;

    class Main{
        static class Shark{
            int r;
            int c;
            int s;
            int d;
            int z;

            public Shark( int s, int d, int z) {
                this.s = s;
                this.d = d;
                this.z = z;
            }

            @Override
            public String toString() {
                return "" + s + d + z;
            }
        }
        static int myC, R, C, M, ans;
        static List<Shark>[][] grid;
        static int[] dr = {-1, 1, 0, 0}, dc = {0, 0, 1, -1};

        public static void main(String[] args) throws Exception {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st;
            st = new StringTokenizer(br.readLine(), " ");
            R = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
            grid = new List[R + 1][C + 1]; for(int i = 1; i <= R; i++) for(int j = 1; j <= C; j++) grid[i][j] = new ArrayList<>();
            ans = 0;
            for(int q = 0; q < M; q++){
                st = new StringTokenizer(br.readLine(), " ");
                int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
                Shark s = new Shark(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                s.d--;
                grid[r][c].add(s);
            }
            //sovle
            for(myC = 1; myC <= C; myC++){
                //낚시하기
                int aa = 1;
                for(int r = 1; r <= R; r++){
                    if(!grid[r][myC].isEmpty()){
                        Shark s = grid[r][myC].get(0);
                        ans += s.z;
                        grid[r][myC].remove(s);
                        break;
                    }
                }

                aa = 1;
                //이동
                List<Shark> tmp = new ArrayList<>();
                for(int r = 1; r <= R; r++){
                    for(int c = 1; c <= C; c++){
                        if (!grid[r][c].isEmpty()) {
                            Shark s = grid[r][c].get(0);
                            grid[r][c].remove(s);
                            int move = s.s;
                            int dir = s.d;
                            int nr = r;
                            int nc = c;
                            if(dir == 0){
                                int dist = nr - 1;
                                if(move < dist){
                                    nr -= move;
                                }else{
                                    move -= dist;
                                    dir = 1;
                                    nr = 1;
                                    int quo = move / (R - 1);
                                    int rem = move % (R - 1);
                                    if(quo % 2 == 0){
                                        dir = 1;
                                        nr = 1 + rem;
                                    }else{
                                        dir = 0;
                                        nr = R - rem;
                                    }
                                }
                            } else if (dir == 1) {
                                int dist = R - nr;
                                if(move < dist){
                                    nr += move;
                                }else{
                                    move -= dist;
                                    nr = R;
                                    dir = 0;
                                    int quo = move / (R - 1);
                                    int rem = move % (R - 1);
                                    if(quo % 2 == 0){
                                        dir = 0;
                                        nr = R - rem;
                                    }else{
                                        dir = 1;
                                        nr = 1 + rem;
                                    }
                                }
                            }else if(dir == 2){
                                int dist = C - nc;
                                if(move < dist){
                                    nc += move;
                                }else{
                                    move -= dist;
                                    nc = C;
                                    dir = 3;
                                    int quo = move / (C - 1);
                                    int rem = move % (C - 1);
                                    if(quo % 2 == 0){
                                        dir = 3;
                                        nc = C - rem;
                                    }else{
                                        dir = 2;
                                        nc = 1 + rem;
                                    }
                                }
                            }else {//dir == 3
                                int dist = nc - 1;
                                if (move < dist) {
                                    nc -= move;
                                } else {
                                    move -= dist;
                                    dir = 2;
                                    nc = 1;
                                    int quo = move / (C - 1);
                                    int rem = move % (C - 1);
                                    if (quo % 2 == 0) {
                                        dir = 2;
                                        nc = 1 + rem;
                                    } else {
                                        dir = 3;
                                        nc = C - rem;
                                    }
                                }
                            }
                            s.r = nr;
                            s.c = nc;
                            s.d = dir;
                            tmp.add(s);
                        }
                    }
                }
                for(Shark s : tmp){
                    grid[s.r][s.c].add(s);
                }

                aa = 1;
                //상어 제거
                for(int r = 1; r <= R; r++){
                    for(int c = 1; c <= C; c++){
                        if(grid[r][c].size() > 1){
                            grid[r][c].sort(new Comparator<Shark>() {
                                @Override
                                public int compare(Shark o1, Shark o2) {
                                    return -Integer.compare(o1.z, o2.z);
                                }
                            });
                            while(grid[r][c].size() > 1){
                                grid[r][c].remove(grid[r][c].size() - 1);
                            }
                        }
                    }
                }
                aa = 1;
            }
            System.out.println(ans);
        }

    }