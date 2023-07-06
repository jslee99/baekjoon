import java.io.*;
import java.util.*;

public class Main {
    private int N;
    private int ans = 0;
    private ArrayList<String> strings = new ArrayList<String>();
    private int[] mapping_char_to_num = new int[92];
    private int seq = 9;

    class data implements Comparable<data>{
        public char ch;
        public int score;

        @Override
        public int compareTo(data x) {
            if(this.score < x.score){
                return 1;
            }else if(this.score > x.score){
                return -1;
            }

            return 0;
        }
    }

    private Integer str_to_num(final String str){
        Integer num = 0;
        for(int i = 0; i < str.length(); i++){
            num += mapping_char_to_num[str.charAt(i)] * (int)Math.pow(10, str.length() - i - 1);
        }
        return num;
    }

    private void mapping_char(){
        int[] score_of_char = new int[92];
        for(int i = 0; i < N; i++){
            String str = strings.get(i);
            for(int j = 0; j < str.length(); j++){
                score_of_char[str.charAt(j)] += Math.pow(10, str.length() - j - 1);
            }
        }

        PriorityQueue<data> pq = new PriorityQueue<>();

        for(int i = 65; i <= 91; i++){
            if(score_of_char[i] > 0){
                data x = new data();
                x.ch = (char)i;
                x.score = score_of_char[i];
                pq.add(x);
            }
        }

        while(!pq.isEmpty()){
            data x = pq.poll();
            mapping_char_to_num[x.ch] = seq--;
        }
    }

    public void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            strings.add(br.readLine());
        }

        mapping_char();

        for(int i = 0; i < N; i++){
            ans += str_to_num(strings.get(i));
        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        br.close();
        bw.close();
    }


    public static void main(String[] args) throws Exception {
        new Main().solution();
        return;
    }
}
