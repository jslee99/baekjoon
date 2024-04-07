import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main{
    static int[] A, B;
    static boolean[] V;
    static int N, M;
    static StringBuilder sb = new StringBuilder();

    static void perm(int idx){
        if(idx >= M){
            for(int i = 0; i < M; i++)
                sb.append(B[i]).append(' ');
            sb.append('\n');
            return;
        }

        for(int i = 0; i < N; i++){
            if(V[i])
                continue;
            V[i] = true;
            B[idx] = A[i];
            perm(idx + 1);
            V[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); A = new int[N]; B = new int[N]; V = new boolean[N];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(A);

        perm(0);

        System.out.print(sb);
        br.close();

    }
}