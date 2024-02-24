import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
    static class Hitter{
        int[] hit = new int[51];
    }
    static int N, ans;
    static Hitter[] hitters = new Hitter[10];
    static boolean[] used = new boolean[10];
    static int[] order = new int[10];

    static void perm(int cnt){
        if(cnt == 9){
            //simulation
            int score = 0;
            int idx = 0;
            for(int i = 1; i <= N; i++){
                boolean[] base = new boolean[4];
                int out = 0;
                while(out < 3){
                    Hitter hitter = hitters[order[idx++]];
                    if(idx >= 9)
                        idx = 0;

                    int hit = hitter.hit[i];
                    switch(hit){
                        case 0:
                            out++;
                            break;
                        case 1:
                            if(base[3])
                                score++;
                            for(int b = 3; b >= 2; b--)
                                base[b] = base[b - 1];
                            base[1] = true;
                            break;
                        case 2:
                            if(base[3])
                                score++;
                            if(base[2])
                                score++;
                            base[3] = base[1];
                            base[2] = true;
                            base[1] = false;
                            break;
                        case 3:
                            if(base[3])
                                score++;
                            if(base[2])
                                score++;
                            if(base[1])
                                score++;
                            base[3] = true;
                            base[2] = false;
                            base[1] = false;
                            break;
                        case 4:
                            score++;
                            for(int b = 1; b <= 3; b++){
                                if(base[b])
                                    score++;
                                base[b] = false;
                            }
                            break;
                    }
                }
            }
            if(score == 48){
                int aa = 1;
            }

            ans = Math.max(ans, score);
            return;
        }

        if(cnt == 3){
            perm(cnt + 1);
        }else{
            for(int i = 1; i <= 9; i++){
                if(used[i])
                    continue;
                order[cnt] = i;
                used[i] = true;
                perm(cnt + 1);
                used[i] = false;
            }
        }


    }


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        for(int i = 1; i <= 9; i++){
            hitters[i] = new Hitter();
        }
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 1; j <= 9; j++) {
                hitters[j].hit[i] = Integer.parseInt(st.nextToken());
            }
        }

        order[3] = 1;
        used[1] = true;
        perm(0);

        System.out.println(ans);
    }
}