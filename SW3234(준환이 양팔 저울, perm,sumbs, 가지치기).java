import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution{
    static int T;
    static int N, ans;
    static int[] choo;
    static int[] orderChoo;
    static boolean[] used;

    static void subs(int cnt, int leftSum, int rightSum){
        if(cnt == N){
            ans++;
            return;
        }

        //isLeft[cnt] = true;
        subs(cnt + 1, leftSum + orderChoo[cnt], rightSum);

        //isLeft[cnt] = false;
        if(leftSum >= rightSum + orderChoo[cnt]){
            subs(cnt + 1, leftSum, rightSum + orderChoo[cnt]);
        }

    }
    static void perm(int cnt){
        if(cnt == N){
            subs(0, 0, 0);
            return;
        }

        for(int i = 0; i < N; i++){
            if(used[i])
                continue;
            used[i] = true;
            orderChoo[cnt] = choo[i];
            perm(cnt + 1);
            used[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            N = Integer.parseInt(br.readLine());
            choo = new int[N];
            orderChoo = new int[N];
            used = new boolean[N];
            ans = 0;
            st = new StringTokenizer(br.readLine(), " ");
            for(int i = 0; i < N; i++)
                choo[i] = Integer.parseInt(st.nextToken());
            perm(0);
            sb.append('#').append(tc).append(' ').append(ans).append('\n');
        }
        System.out.println(sb);
        br.close();
    }
}