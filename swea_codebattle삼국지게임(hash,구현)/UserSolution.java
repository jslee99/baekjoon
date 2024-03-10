import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

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
        Set<Integer> hostileUnionIdList = new HashSet<>();
    }
    static Map<String, Monarch> monarchs;
    static Union[] unions;
    static String[][] gridMonarch;
    static int N;
    static int[] dr = {-1, -1, -1, 0, 1, 1, 1, 0}, dc = {-1, 0, 1, 1, 1, 0, -1, -1};
    static boolean isIn(int r, int c){
        return r >= 0 && r < N && c >= 0 && c < N;
    }
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
        if(from.unionId > to.unionId){
            Monarch tmp = from;
            from = to;
            to = tmp;
        }

        if(from.unionId == to.unionId){
            res = -1;
        }else{
            Union fromUnion = unions[from.unionId];
            Union toUnion = unions[to.unionId];
            if(fromUnion.hostileUnionIdList.contains(to.unionId)){
                res = -2;
            }else{
                //동맹 맺기
                unions[to.unionId] = null;
                for(int hostileUnionIdOfToUnion : toUnion.hostileUnionIdList){
                    fromUnion.hostileUnionIdList.add(hostileUnionIdOfToUnion);
                    unions[hostileUnionIdOfToUnion].hostileUnionIdList.remove(to.unionId);
                    unions[hostileUnionIdOfToUnion].hostileUnionIdList.add(from.unionId);
                }
                for(Map.Entry<String, Monarch> entry : toUnion.monarchs.entrySet()){
                    entry.getValue().unionId = from.unionId;
                    fromUnion.monarchs.put(entry.getKey(), entry.getValue());
                }
                res = 1;
            }
        }
        return res;
    }
    int attack(char mMonarchA[], char mMonarchB[], char mGeneral[]) {
        int res = Integer.MAX_VALUE;
        String attackerName = new String(mMonarchA).trim();
        String defenderName = new String(mMonarchB).trim();
        Monarch attacker = monarchs.get(attackerName);
        Monarch defender = monarchs.get(defenderName);
        if(unions[attacker.unionId].monarchs.containsKey(defenderName)){
            res = -1;
        }else{
            boolean go = false;
            for(int d = 0; d < 8; d++){
                int newR = defender.r + dr[d], newC = defender.c + dc[d];
                if(!isIn(newR, newC))
                    continue;
                if(monarchs.get(gridMonarch[newR][newC]).unionId == attacker.unionId){
                    go = true;
                    break;
                }
            }
            if(!go){
                res = -2;
            }else{
                //공격 발생
                Union attackerUnion = unions[attacker.unionId];
                Union defenderUnion = unions[defender.unionId];
                attackerUnion.hostileUnionIdList.add(defender.unionId);
                defenderUnion.hostileUnionIdList.add(attacker.unionId);
                int supportSoldierSumInDefenderUnion = 0;
//                for(Monarch monarchInDefenderUnion : defenderUnion.monarchs.values()){
//                    if(monarchInDefenderUnion == defender)
//                        continue;
//                    else{
//                        supportSoldierSumInDefenderUnion += monarchInDefenderUnion.soldier / 2;
//                        monarchInDefenderUnion.soldier -= monarchInDefenderUnion.soldier / 2;
//                    }
//                }
                for(int d = 0; d < 8; d++){
                    int newR = defender.r + dr[d], newC = defender.c + dc[d];
                    if(!isIn(newR, newC))
                        continue;
                    Monarch adjMonarch = monarchs.get(gridMonarch[newR][newC]);
                    if(defender.unionId == adjMonarch.unionId){
                        supportSoldierSumInDefenderUnion += adjMonarch.soldier / 2;
                        adjMonarch.soldier -= adjMonarch.soldier / 2;
                    }
                }
                defender.soldier += supportSoldierSumInDefenderUnion;

                int soldierSumInAttackerUnion = 0;
                for(int d = 0; d < 8; d++){
                    int newR = defender.r + dr[d], newC = defender.c + dc[d];
                    if(!isIn(newR, newC))
                        continue;;
                    String adjMonarchName = gridMonarch[newR][newC];
                    Monarch adjMonarch = monarchs.get(adjMonarchName);
                    if(adjMonarch.unionId == attacker.unionId){
                        soldierSumInAttackerUnion += adjMonarch.soldier / 2;
                        adjMonarch.soldier -= adjMonarch.soldier / 2;
                    }
                }

                if(soldierSumInAttackerUnion > defender.soldier){
                    //공격 성공
                    res = 1;
                    //일단 전임자 제거
                    monarchs.remove(defenderName);
                    unions[defender.unionId].monarchs.remove(defenderName);
                    if(unions[defender.unionId].monarchs.isEmpty()){
                        unions[defender.unionId] = null;
                        for(int hostileUnionId : defenderUnion.hostileUnionIdList){
                            unions[hostileUnionId].hostileUnionIdList.remove(defender.unionId);
                        }
                    }
                    //새롭게 땅 세우기
                    String generalName = new String(mGeneral).trim();
                    gridMonarch[defender.r][defender.c] = generalName;
                    Monarch generalMonarch = new Monarch(defender.r, defender.c, soldierSumInAttackerUnion - defender.soldier, attacker.unionId);
                    monarchs.put(generalName, generalMonarch);
                    unions[attacker.unionId].monarchs.put(generalName, generalMonarch);
                }else{
                    //방어 성공
                    res = 0;
                    defender.soldier -= soldierSumInAttackerUnion;
                }
            }
        }
        return res;
    }
    int recruit(char mMonarch[], int mNum, int mOption) {
        int soldierSum = 0;
        String monarchName = new String(mMonarch).trim();
        Monarch monarch = monarchs.get(monarchName);
        if(mOption == 0){
            //자신만
            monarch.soldier += mNum;
            soldierSum += monarch.soldier;
        }else{
            Union union = unions[monarch.unionId];
            for (Monarch m : union.monarchs.values()) {
                m.soldier += mNum;
                soldierSum += m.soldier;
            }
        }
        return soldierSum;
    }
}