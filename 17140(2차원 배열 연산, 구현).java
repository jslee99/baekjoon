import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main{
    static int r, c ,k, t ,n = 100;
    static int row;
    static int col;
    static int[][] arr = new int[101][101];

    static boolean isK(){
        return arr[r][c] == k;
    }

    static List<Integer> sorting(int x, boolean isRow) {
        Map<Integer, Integer> map = new HashMap<>();
        if(isRow){
            for(int j = 1; j <= col; j++){
                int key = arr[x][j];
                map.computeIfAbsent(key, k -> 0);
                map.computeIfPresent(key, (k, v) -> v + 1);
            }
        }else{
            for(int i = 1; i <= row; i++){
                int key = arr[i][x];
                map.computeIfAbsent(key, k -> 0);
                map.computeIfPresent(key, (k, v) -> v + 1);
            }
        }
        map.remove(0);
        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>();
        map.entrySet().stream().forEach(e -> entryList.add(e));
        entryList.sort((Map.Entry<Integer, Integer> e1, Map.Entry<Integer, Integer> e2) -> {
            if(e1.getValue() < e2.getValue()){
                return -1;
            }else if(e1.getValue() > e2.getValue()){
                return 1;
            }else{
                if(e1.getKey() < e2.getKey())
                    return -1;
                else
                    return 1;
            }
        });

        List<Integer> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : entryList) {
            if(list.size() > n)
                break;
            list.add(e.getKey());
            list.add(e.getValue());
        }
        return list;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        r = Integer.parseInt(st.nextToken()); c = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
        row = 3;
        col = 3;
        for(int i = 1; i <= row; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= col; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        t = 0;

        while(!isK() && t <= 100){
            if(row >= col){
                List<Integer>[] eachRow = new List[row + 1];
                int maxColLen = 0;
                for(int i = 1; i <= row; i++){
                    List<Integer> sorting = sorting(i, true);
                    eachRow[i] = sorting;
                    maxColLen = Math.max(maxColLen, sorting.size());
                }
                col = maxColLen;
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= n; j++)
                        arr[i][j] = 0;
                for(int i = 1; i <= row; i++){
                    for(int j = 1; j <= eachRow[i].size(); j++){
                        arr[i][j] = eachRow[i].get(j - 1);
                    }
                }
            }else{
                List<Integer>[] eachCol = new List[col + 1];
                int maxRowLen = 0;
                for(int j = 1; j <= col; j++){
                    List<Integer> sorting = sorting(j, false);
                    eachCol[j] = sorting;
                    maxRowLen = Math.max(maxRowLen, sorting.size());
                }
                row = maxRowLen;
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= n; j++)
                        arr[i][j] = 0;
                for(int j = 1; j <= col; j++){
                    for(int i = 1; i <= eachCol[j].size(); i++){
                        arr[i][j] = eachCol[j].get(i - 1);
                    }
                }
            }
            t++;
        }

        System.out.println(t > 100 ? -1 : t);
    }
}