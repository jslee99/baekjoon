import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Hashtable;
import java.util.Map;
import java.util.StringTokenizer;

class Solution{
    static class Pos{
        int r;
        int c;

        @Override
        public int hashCode() {
            return 1;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj instanceof Pos){
                Pos pos = (Pos)obj;
                return this.r == pos.r && this.c == pos.c;
            }
            throw new IllegalStateException();
        }

        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static class Microbe{
        int n;
        int d;
        int sum;

        public Microbe(int n, int d, int sum) {
            this.n = n;
            this.d = d;
            this.sum = sum;
        }
    }

    static boolean isIn(int r, int c){
        return r > 0 && r < N - 1 && c > 0 && c < N - 1;
    }

    static int T, N, M, K, ans;
    static int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
    static Map<Pos, Microbe> map;

    static int reverse(int d){
        switch (d){
            case 0:
                return 1;
            case 1:
                return 0;
            case 2:
                return 3;
            case 3:
                return 2;
            default:
                throw new IllegalStateException();
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            map = new Hashtable<>();
            st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
            for(int q = 0; q < K; q++){
                st = new StringTokenizer(br.readLine(), " ");
                Pos pos = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
                Microbe m  = new Microbe(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);
                m.d--;
                map.put(pos, m);
            }
            ans = 0;

            for(int time = 1; time <= M; time++){
                Map<Pos, Microbe> nextMap = new Hashtable<>();
                for (Map.Entry<Pos, Microbe> entry : map.entrySet()) {
                    Pos pos = entry.getKey();
                    Microbe microbe = entry.getValue();
                    pos.r += dr[microbe.d];
                    pos.c += dc[microbe.d];
                    if(!isIn(pos.r, pos.c)){
                        //충돌 불가능, 해당 상황 가정 x
                        //가장 자리에서는 충돌이 발생 할 수 없다.
                        microbe.d = reverse(microbe.d);
                        microbe.n = microbe.n / 2;
                        if(microbe.n > 0){
                            nextMap.computeIfPresent(pos, (pos1, microbe1) -> {throw new IllegalStateException();});
                            nextMap.put(pos, microbe);
                            microbe.sum = microbe.n;
                        }
                    }else{
                        nextMap.computeIfPresent(pos, (existsPos, existsMicrobe) -> {
                            if(microbe.n > existsMicrobe.n){
                                existsMicrobe.d = microbe.d;
                                existsMicrobe.n = microbe.n;
                            }else{
                                //continue;
                            }
                            existsMicrobe.sum += microbe.n;
                            return existsMicrobe;
                        });
                        nextMap.computeIfAbsent(pos, existsPos -> {
                            microbe.sum = microbe.n;
                            return microbe;
                        });
                    }
                }

                for(Map.Entry<Pos, Microbe> entry :nextMap.entrySet()){
                    Microbe microbe = entry.getValue();
                    if (microbe.sum > 0) {
                        microbe.n = microbe.sum;
                        microbe.sum = 0;
                    }
                }

                map = nextMap;
            }

            for (Map.Entry<Pos, Microbe> entry : map.entrySet())
                ans += entry.getValue().n;
            sb.append("#").append(tc).append(" ").append(ans).append("\n");

        }
        System.out.println(sb);
        br.close();
    }
}