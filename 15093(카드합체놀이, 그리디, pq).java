import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static PriorityQueue<Long> pq = new PriorityQueue<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            long a = sc.nextInt();
            pq.add(a);
        }

        for (int i = 0; i < m; i++) {
            long a = pq.poll();
            long b = pq.poll();
            long c = a + b;
            pq.add(c);
            pq.add(c);
        }

        while (!pq.isEmpty()) {
            ans += pq.poll();
        }

        System.out.println(ans);
    }
}