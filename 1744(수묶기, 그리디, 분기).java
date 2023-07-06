import java.io.*;
import java.util.*;

public class Main {
    int N;
    int ans = 0;

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<Integer> positive_pq = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> negative_pq = new PriorityQueue<>();
        boolean exists_zero = false;

        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            int a = Integer.parseInt(br.readLine());
            if(a > 0){
                positive_pq.add(a);
            }else if(a < 0){
                negative_pq.add(a);
            }else{
                exists_zero = true;
            }
        }

        //nengative pq
        while (!negative_pq.isEmpty()) {
            if(negative_pq.size() == 1){
                if(!exists_zero){
                    ans += negative_pq.poll();
                }else{
                    negative_pq.poll();
                }
            }else{
                int a, b;
                a = negative_pq.poll();
                b = negative_pq.poll();
                ans += a * b;
            }
        }

        //positive pq
        while (!positive_pq.isEmpty()) {
            if(positive_pq.size() == 1){
                ans += positive_pq.poll();
            }else{
                int a, b;
                a = positive_pq.poll();
                b = positive_pq.poll();
                if(a == 1 || b == 1){
                    ans += a + b;
                }else{
                    ans += a * b;
                }
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
        return;
    }
}
