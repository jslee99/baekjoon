import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    int r;
    int c;

    public Node(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

class Solution{
    static int[][] map = new int[25][25];
    static int T, n, ans;
    static List<Node> nodes;
    static int[] dr = {-1, 1, 1, -1};
    static int[] dc = {-1, -1, 1, 1};

    static boolean isIn(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    static void markMap(Node n, boolean[][] visit) {
        for(int d = 0; d < 4; d++){
            int r = n.r, c = n.c;
            while (isIn(r, c)) {
                visit[r][c] = true;
                r += dr[d];
                c += dc[d];
            }
        }
    }
    static List<Node> getOtherNodes(Node n1, Node n3) {
        List<Node> otherNodes = new ArrayList<>();

        if(Math.abs(n1.r - n3.r) == Math.abs(n1.c - n3.c)){
            return otherNodes;
        }

        boolean[][] visit1 = new boolean[25][25];
        markMap(n1, visit1);
        visit1[n1.r][n1.c] = false;
        boolean[][] visit3 = new boolean[25][25];
        markMap(n3, visit3);
        visit3[n3.r][n3.c] = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(visit1[i][j] && visit3[i][j])
                    otherNodes.add(new Node(i, j));
        return otherNodes;
    }

    static int findDir(Node n1, Node n2) {
        for(int d = 0; d < 4; d++){
            int r = n1.r, c = n1.c;
            while(isIn(r, c)){
                if (r == n2.r && c == n2.c) {
                    return d;
                }
                r += dr[d]; c += dc[d];
            }
        }
        return -1;
    }
    static void addSet(Node n1, Node n2, Set<Integer> desertSet) {
        int d = findDir(n1, n2);
        if(d == -1){
            int aa=1;
        }
        int r = n1.r, c = n1.c;
        while(!(r == n2.r && c == n2.c)){
            desertSet.add(map[r][c]);
            r += dr[d]; c += dc[d];
        }
    }

    static void calcDesertNum(Node n1, Node n2, Node n3, Node n4){
        Set<Integer> desertSet = new HashSet<>();
        int desertSetNum = Math.abs(n1.r - n2.r) + Math.abs(n1.r - n4.r) + Math.abs(n2.r - n3.r) + Math.abs(n3.r - n4.r);
        addSet(n1, n2, desertSet);
        addSet(n2, n3, desertSet);
        addSet(n3, n4, desertSet);
        addSet(n4, n1, desertSet);

        if (desertSetNum == desertSet.size()) {
            ans = Math.max(ans, desertSet.size());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            ans = -1;
            n = Integer.parseInt(br.readLine());
            nodes = new ArrayList<>();
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    nodes.add(new Node(i, j));
                }
            }

            for (int i = 0; i < nodes.size(); i++) {
                for(int j = i + 1; j < nodes.size(); j++){
                    Node n1 = nodes.get(i);
                    Node n3 = nodes.get(j);
                    List<Node> otherNodes = getOtherNodes(n1, n3);
                    if(otherNodes.size() != 2)
                        continue;
                    calcDesertNum(n1, otherNodes.get(0), n3, otherNodes.get(1));
                }
            }
            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }
}