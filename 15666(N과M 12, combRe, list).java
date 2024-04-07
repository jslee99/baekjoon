import java.io.BufferedReader;
import java.io.InputStreamReader;
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
    static List<Seq> set;

    static void combRe(int start, int idx){
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

        for(int i = start; i < N; i++){
            B[idx] = A[i];
            combRe(i, idx + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st=new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
        A = new int[N]; B = new int[M]; set = new ArrayList<>();

        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(A);

        combRe(0, 0);

        System.out.println(sb);
        br.close();
    }
}