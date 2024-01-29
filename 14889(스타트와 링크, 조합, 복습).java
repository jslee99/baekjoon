import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main{
    static int n;
    static int[][] score = new int[26][26];
    static boolean[] isStart = new boolean[26];
    static int ans = Integer.MAX_VALUE;

    static void calcScore(){
        int startScore = 0;
        int linkStore = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(isStart[i] && isStart[j]){
                    startScore += score[i][j] + score[j][i];
                }

                if(!isStart[i] && !isStart[j]){
                    linkStore += score[i][j] + score[j][i];
                }
            }
        }
        ans = Math.min(ans, Math.abs(startScore - linkStore));
    }
    static void selectStartTeam(int beforeIdx, int selectCnt){
        if(selectCnt >= n / 2){
            calcScore();
            return;
        }

        for(int i = beforeIdx + 1; i <= n; i++){
            isStart[i] = true;
            selectStartTeam(i, selectCnt + 1);
            isStart[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j = 1; j <= n; j++){
                score[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        selectStartTeam(0, 0);
        System.out.println(ans);
    }
}
