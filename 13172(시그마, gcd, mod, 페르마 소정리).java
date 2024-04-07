import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    static int M;
    static long[][] dice;
    static final long mod = 1000000007;
//    static final long mod = 11;
    static long ans;

    static long gcd(long a, long b){
        if(b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    static long pow(long base, long p){
        if(p == 1)
            return base % mod;

        long half = pow(base, p / 2);
        if(p % 2 == 1){
            return ((half * half) % mod) * (base % mod) % mod;
        }else{
            return (half * half) % mod;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        M = Integer.parseInt(br.readLine()); dice = new long[M][2]; ans = 0;
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine(), " ");
            dice[i][0] = Long.parseLong(st.nextToken());
            dice[i][1] = Long.parseLong(st.nextToken());
        }

        for(int i = 0; i < M; i++){
            long n = dice[i][0];
            long s = dice[i][1];
            //s * n^-1 % mod
            //s * n^(mod - 2) % mod
            long g = gcd(Math.max(n, s), Math.min(n, s));
            s /= g;
            n /= g;
            ans += ((s % mod) * pow(n, mod - 2)) % mod;
            ans %= mod;
        }
        System.out.println(ans);
        br.close();
    }
}

//7 * 3()