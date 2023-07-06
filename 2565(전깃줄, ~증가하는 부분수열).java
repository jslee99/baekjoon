import java.io.*;
import java.util.*;

public class Main {
    int n;
    TreeMap<Integer, Integer> treeMap = new TreeMap<>();
    ArrayList<Integer> after_seq = new ArrayList<>();
    class DP{
        public int left_end;
        public int right_end;
        public int[] store = new int[101];

        public void bi_search(int key){
            if(key > store[right_end]){
                store[++right_end] = key;
                return;
            }else if(key < store[left_end]) {
                store[left_end] = key;
                return;
            }

            int left = left_end;
            int right = right_end;
            int mid;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (key < store[mid]) {
                    right = mid;
                }else{
                    left = mid;
                }
            }

            store[right] = key;
        }
    }

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());

        DP dp = new DP();

        for(int i = 0; i <= n; i++) dp.store[i] = -1;

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            treeMap.put(a, b);
        }

        for (Map.Entry<Integer, Integer> entry : treeMap.entrySet()) {
            after_seq.add(entry.getValue());
        }
        dp.store[1] = after_seq.get(0);
        dp.left_end = 1; dp.right_end = 1;

        for(int i = 1; i < n; i++){
            dp.bi_search(after_seq.get(i));
        }

        int ans = n - dp.right_end;
        bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();



    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
        return;
    }
}
