import java.util.HashMap;
import java.util.Map;

class UserSolution {
    static class Monarch{
        int r;
        int c;
        int soldier;
        int unionId;

        public Monarch(int r, int c, int soldier, int unionId) {
            this.r = r;
            this.c = c;
            this.soldier = soldier;
            this.unionId = unionId;
        }

        @Override
        public String toString() {
            return "" + r + " " + c + " " + soldier + " " + unionId;
        }
    }
    static class Union{
        Map<String, Monarch> monarchs = new HashMap<>();
        Map<Integer, Union> hostileUnions = new HashMap<>();
    }
    static Map<String, Monarch> monarchs;
    static Union[] unions;
    static String[][] gridMonarch;
    static int N;
    void init(int n, int mSoldier[][], char mMonarch[][][]) {
        N = n;
        monarchs = new HashMap<>();
        unions = new Union[N * N];
        gridMonarch = new String[N][N];
        int unionId = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                gridMonarch[i][j] = new String(mMonarch[i][j]).trim();
                Monarch m = new Monarch(i, j, mSoldier[i][j], unionId++);
                monarchs.put(gridMonarch[i][j], m);
                Union u = new Union();
                u.monarchs.put(gridMonarch[i][j], m);
                unions[m.unionId] = u;
            }
        }
        int aa = 1;
    }
    void destroy()
    {

    }
    int ally(char mMonarchA[], char mMonarchB[]) {
        int res = Integer.MAX_VALUE;
        String fromName = new String(mMonarchA).trim();
        String toName = new String(mMonarchB).trim();
        Monarch from = monarchs.get(fromName);
        Monarch to = monarchs.get(toName);
        if(from.unionId == to.unionId){
            res = -1;
        }else{
            Union fromUnion = unions[from.unionId];
            Union toUnion = unions[to.unionId];
            if(fromUnion.hostileUnions.containsKey(to.unionId)){
                res = -2;
            }else{
                //동맹 맺기
                unions[to.unionId] = null;
                for(Map.Entry<String, Monarch> entry : toUnion.monarchs.entrySet()){
                    entry.getValue().unionId = from.unionId;
                    fromUnion.monarchs.put(entry.getKey(), entry.getValue());
                }
                for(Map.Entry<Integer, Union> entry: toUnion.hostileUnions.entrySet()){
                    fromUnion.hostileUnions.put(entry.getKey(), entry.getValue());
                }
                res = 1;
            }
        }
        return res;
    }
    int attack(char mMonarchA[], char mMonarchB[], char mGeneral[])
    {
        return -3;
    }
    int recruit(char mMonarch[], int mNum, int mOption)
    {
        return -1;
    }
}