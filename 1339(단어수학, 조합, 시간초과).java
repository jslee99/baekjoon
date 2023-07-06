import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int ans = 0;
    static ArrayList<String> strings = new ArrayList<String>();
    static ArrayList<Character> chars = new ArrayList<Character>();
    static int[] mapping_char_to_num = new int[26];
    static boolean[] visited = new boolean[10];

    public static int idx_of(final char ch){
        return (int)(ch - 'A');
    }

    public static Integer str_to_num(final String str){
        Integer num = 0;
        for(int i = 0; i < str.length(); i++){
            num += mapping_char_to_num[idx_of(str.charAt(i))] * (int)Math.pow(10, str.length() - i - 1);
        }
        return num;
    }

    public static void calc(){
        ArrayList<Integer> nums = new ArrayList<>();
        for(int i = 0; i < strings.size(); i++){
            nums.add(str_to_num(strings.get(i)));
        }
        Integer res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += nums.get(i);
        }

        if(res > ans){
            ans = res;
        }
    }

    public static void comb(int selected_num, int max_selected_num){
        if(selected_num == max_selected_num){
            calc();
            return;
        }

        for(int i = 0; i <= 9; i++){
            if(!visited[i]){
                visited[i] = true;
                mapping_char_to_num[idx_of(chars.get(selected_num))] = i;
                comb(selected_num + 1, max_selected_num);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            strings.add(br.readLine());
        }

        for(int i = 0; i < strings.size(); i++){
            String str = strings.get(i);
            for(int j = 0; j < str.length(); j++){
                if(!chars.contains(str.charAt(j))){
                    chars.add(str.charAt(j));
                }
            }
        }

        comb(0, chars.size());

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.flush();
        br.close();
        bw.close();

        return;
    }
}
