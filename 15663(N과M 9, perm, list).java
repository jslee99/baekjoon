import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.*;

public class Main{
    static class Seq{
        int[] tmp;

        public Seq(int[] tmp) {
            this.tmp = tmp;
        }

        @Override
        public int hashCode() {
            return 0;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj instanceof Seq){
                Seq o = (Seq)obj;
                for(int i = 0; i < M; i++)
                    if(tmp[i] != o.tmp[i])
                        return false;
                return true;
            }else{
                return false;
            }
        }
    }
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static int[] A, B;
    static boolean[] V;
    static List<Seq> set;

    static void perm(int idx){
        if(idx >= M){
            int[] tmp = new int[M];
            for(int i = 0; i < M; i++) tmp[i] = B[i];
            Seq seq = new Seq(tmp);
            if(set.contains(seq))
                return;

            set.add(seq);

            for (int i = 0; i < M; i++) {
                sb.append(tmp[i]).append(' ');
            }

            sb.append('\n');
            return;
        }

        for(int i = 0; i < N; i++){
            if(V[i]) continue;
            V[i] = true;
            B[idx] = A[i];
            perm(idx + 1);
            V[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st=new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
        A = new int[N]; B = new int[M]; V = new boolean[N]; set = new ArrayList<>();

        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(A);

        perm(0);

        System.out.println(sb);
        br.close();
    }
}