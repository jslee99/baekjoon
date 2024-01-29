import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

class Injection{
    int depth;
    int v;

    public Injection(int depth, int v) {
        this.depth = depth;
        this.v = v;
    }
}

class Solution{
    static int T, d, w, k, ans;
    static int[][] film = new int[25][25];

    static boolean simulation(Stack<Injection> injections) {
        int[][] temp = new int[13][20];
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < w; j++) {
                temp[i][j] = film[i][j];
            }
        }
        for (Injection injection : injections) {
            for(int j = 0; j < w; j++){
                temp[injection.depth][j] = injection.v;
            }
        }

        for(int j = 0; j < w; j++){
            int max0 = 0;
            int max1 = 0;
            int cur0 = 0;
            int cur1 = 0;
            for(int i = 0; i < d; i++){
                if(temp[i][j] == 0){
                    cur0++;
                    cur1 = 0;
                }else{
                    cur1++;
                    cur0 = 0;
                }
                max0 = Math.max(max0, cur0);
                max1 = Math.max(max1, cur1);
            }
            if (Math.max(max0, max1) < k) {
                return false;
            }
        }
        return true;
    }

    static boolean combination(Stack<Injection> injections , int beforeIdx, int maxSelectNum) {
        if (injections.size() >= maxSelectNum) {
            if(simulation(injections)){
                return true;
            }else{
                return false;
            }
        }

        for(int i = beforeIdx + 1; i < d; i++){
            for(int v = 0; v < 2; v++){
                injections.push(new Injection(i, v));
                if(combination(injections, injections.peek().depth ,maxSelectNum)){
                    return true;
                }
                injections.pop();
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine(), " ");
            d = Integer.parseInt(st.nextToken()); w = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
            ans = -1;
            for(int i = 0; i < d; i++){
                st = new StringTokenizer(br.readLine(), " ");
                for(int j = 0; j < w; j++){
                    film[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            for(int maxSelectNum = 0; maxSelectNum < d; maxSelectNum++){
                Stack<Injection> injections = new Stack<>();
                if(combination(injections, -1, maxSelectNum)){
                    ans = maxSelectNum;
                    break;
                }
            }
            if(ans == -1){
                ans = d;
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }
}