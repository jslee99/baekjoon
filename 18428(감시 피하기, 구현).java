import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class pos {
    public pos(int r, int c) {
        this.r = r;
        this.c = c;
    }
    public int r;
    public int c;
}

public class Main {
    public static int n;
    public static char[][] map;
    public static boolean ans = false;
    public static List<pos> T = new ArrayList<>();
    public static List<pos> X = new ArrayList<>();
    public static List<pos> O = new ArrayList<>();
    public static boolean flag;

    public static void calc() {
        O.forEach(o -> map[o.r][o.c] = 'O');
        flag = true;
        T.forEach(t -> {
            for (int j = t.c - 1; j >= 0; j--) {
                if (map[t.r][j] == 'S') {
                    flag = false;
                }else if(map[t.r][j] == 'O'){
                    break;
                }
            }
            for (int j = t.c + 1; j < n; j++) {
                if (map[t.r][j] == 'S') {
                    flag = false;
                }else if(map[t.r][j] == 'O'){
                    break;
                }
            }
            for (int i = t.r - 1; i >= 0; i--) {
                if (map[i][t.c] == 'S') {
                    flag = false;
                } else if (map[i][t.c] == 'O') {
                    break;
                }
            }
            for (int i = t.r + 1; i < n; i++) {
                if (map[i][t.c] == 'S') {
                    flag = false;
                } else if (map[i][t.c] == 'O') {
                    break;
                }
            }
        });
        if (flag) {
            ans = true;
        }

        O.forEach(o -> map[o.r][o.c] = 'X');
    }

    public static void select(int beforeIdx) {
        if (O.size() == 3) {
            calc();
            return;
        }

        for (int i = beforeIdx + 1; i < X.size(); i++) {
            O.add(X.get(i));
            select(i);
            O.remove(O.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        map = new char[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] = sc.next().charAt(0);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(map[i][j] == 'T') T.add(new pos(i, j)); else if(map[i][j] == 'X') X.add(new pos(i, j));
        select(-1);

        if (ans) {
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }

        return;
    }
}