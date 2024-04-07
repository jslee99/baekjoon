import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.TreeMap;

public class Main{
    static final long mod = 1000000007;
    static TreeMap<Long, Long> fibDp;
    static long fib(long n){
        Long v;
        if((v = fibDp.get(n)) != null){
            return v;
        }

        if(n % 2 == 0){
            long m = n / 2;
            v = (fib(m) * ((2L * fib(m - 1) + fib(m))) % mod) % mod;
        }else{
            long m = (n + 1) / 2;
            long tmp1 = fib(m);
            long tmp2 = fib(m - 1);
            v = (tmp1 * tmp1 % mod + tmp2 * tmp2 % mod) % mod;
        }
        fibDp.put(n, v);
        return v;
    }

    public static void main(String[] args) throws Exception {
        fibDp = new TreeMap<>();
        fibDp.put(0L, 0L); fibDp.put(1L, 1L);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(fib(Long.parseLong(br.readLine())));
        br.close();
    }
}