import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main{
    static int n, m, minDistSum;
    static int[][] city = new int[55][55];
    static class Chicken{
        int r;
        int c;
        boolean open;

        public Chicken(int r, int c, boolean open) {
            this.r = r;
            this.c = c;
            this.open = open;
        }
    }
    static List<Chicken> chickens;
    static List<int[]> homes;

    static void calcDist() {
        int distSum = 0;
        for (int[] h : homes) {
            int r = h[0];
            int c = h[1];
            int minDist = Integer.MAX_VALUE;
            for (Chicken chicken : chickens) {
                if(chicken.open){
                    minDist = Math.min(minDist, Math.abs(r - chicken.r) + Math.abs(c - chicken.c));
                }
            }
            distSum += minDist;
        }
        minDistSum = Math.min(minDistSum, distSum);
    }
    static void combOpenChicken(int cnt, int start) {
        if (cnt == m) {
            calcDist();
            return;
        }

        for (int i = start; i < chickens.size(); i++) {
            Chicken chicken = chickens.get(i);
            chicken.open = true;
            combOpenChicken(cnt + 1, i + 1);
            chicken.open = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        chickens = new ArrayList<>();
        homes = new ArrayList<>();
        minDistSum = Integer.MAX_VALUE;
        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 1; j <= n; j++) {
                city[i][j] = Integer.parseInt(st.nextToken());
                if(city[i][j] == 1){
                    homes.add(new int[]{i, j});
                } else if (city[i][j] == 2) {
                    chickens.add(new Chicken(i, j, false));
                }
            }
        }

        combOpenChicken(0, 0);

        System.out.println(minDistSum);
    }
}