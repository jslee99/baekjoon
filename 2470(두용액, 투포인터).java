import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main{
    static int[] ans = new int[3];
    static List<Integer> minus = new ArrayList<>();
    static List<Integer> plus = new ArrayList<>();
    static int N;

    static void setAns(int a, int b){
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }

        if(ans[2] > Math.abs(a + b)){
            ans[0] = a;
            ans[1] = b;
            ans[2] = Math.abs(a + b);
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/sol.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        ans[2] = Integer.MAX_VALUE;
        int a;
        for(int i = 0; i < N; i++)
            if((a = Integer.parseInt(st.nextToken())) < 0)
                minus.add(a);
            else
                plus.add(a);

        int aa = 1;

        minus.sort(Comparator.reverseOrder());
        plus.sort(Comparator.naturalOrder());

        aa = 1;

        if(minus.isEmpty()){
            setAns(plus.get(0), plus.get(1));
        }else if(plus.isEmpty()){
            setAns(minus.get(0), minus.get(1));
        }else{
            if(minus.size() > 1){
                setAns(minus.get(0), minus.get(1));
            }
            if(plus.size() > 1){
                setAns(plus.get(0), plus.get(1));
            }
            int m = 0;
            int p = 0;
            while(m < minus.size() && p < plus.size()){
                setAns(minus.get(m), plus.get(p));
                if(minus.get(m) + plus.get(p) < 0){
                    p++;
                }else{
                    m++;
                }
            }
        }
        System.out.println(ans[0] + " " + ans[1]);
        br.close();
    }
}