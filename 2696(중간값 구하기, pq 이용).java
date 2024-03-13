import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main{
    static int T,M;
    static PriorityQueue<Long> leftMaxQ;
    static PriorityQueue<Long> rightMinQ;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = null;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            leftMaxQ = new PriorityQueue<>(Comparator.reverseOrder());
            leftMaxQ.offer((long)Integer.MIN_VALUE - 1);
            rightMinQ = new PriorityQueue<>();
            rightMinQ.offer((long)Integer.MAX_VALUE + 1);
            M = Integer.parseInt(br.readLine());
            int cnt = 1;
            int printCnt = 1;
            sb.append(M / 2 + 1).append('\n');
            for(int c = 0; c < M; c++){
                if(cnt == 11){
                    cnt = 1;
                }
                if(cnt == 1){
                    st = new StringTokenizer(br.readLine(), " ");
                }
                cnt++;
                Long x = (long)Integer.parseInt(st.nextToken());
                if(x.compareTo(leftMaxQ.peek()) < 0){
                    if(leftMaxQ.size() > rightMinQ.size()){
                        rightMinQ.offer(leftMaxQ.poll());
                        leftMaxQ.offer(x);
                    }else{
                        leftMaxQ.offer(x);
                    }
                }else if(x.compareTo(leftMaxQ.peek()) >= 0 && x.compareTo(rightMinQ.peek()) < 0){
                    if(leftMaxQ.size() > rightMinQ.size())
                        rightMinQ.offer(x);
                    else
                        leftMaxQ.offer(x);
                }else{
                    if(leftMaxQ.size() > rightMinQ.size()){
                        rightMinQ.offer(x);
                    }else {
                        leftMaxQ.offer(rightMinQ.poll());
                        rightMinQ.offer(x);
                    }
                }
                if(c % 2 == 0){
                    if(printCnt == 11){
                        printCnt = 1;
                        sb.append('\n');
                    }
                    sb.append(leftMaxQ.peek()).append(' ');
                    printCnt++;
                }
            }
            sb.append('\n');
        }
        System.out.println(sb);
        br.close();
    }
}