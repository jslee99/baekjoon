import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

class UserSolution {
    static class player implements Comparable<player>{
        int id;
        int ability;

        public player(int id, int ability) {
            this.id = id;
            this.ability = ability;
        }

        @Override
        public int compareTo(player o) {
            int aRes = -Integer.compare(this.ability, o.ability);
            return aRes == 0 ? Integer.compare(this.id, o.id) : aRes;
        }

        @Override
        public String toString() {
            return "" + id + " " + ability;
        }
    }
    static class league{
        TreeMap<player, Object> players;
    }

    static int eachLeaguePlayerCnt, playerCnt, leagueCnt;
    static league[] leagues;
    static player[][] swaps;
    void init(int N, int L, int mAbility[]) {
        playerCnt = N;
        leagueCnt = L;
        eachLeaguePlayerCnt = N / L;
        leagues = new league[L];
        int playerId = 0;
        for(int i = 0; i < L; i++){
            leagues[i] = new league();
            leagues[i].players = new TreeMap<>();
            for(int j = 0; j < eachLeaguePlayerCnt; j++){
                leagues[i].players.put(new player(playerId, mAbility[playerId++]), null);
            }
        }
        swaps = new player[leagueCnt - 1][2];

        int aa = 1;
    }

    int move() {
        int res = 0;
         // i, i + 1 league에서 바꿀 놈들 저장, 0이 left, 1이 right
        for(int i = 0; i < leagueCnt - 1; i++){
            league leftLeague = leagues[i];
            league rightLeague = leagues[i + 1];
            player leftPlayer = leftLeague.players.lastKey();
            player rightPlayer = rightLeague.players.firstKey();
            //swap을 바로하지말고 일단 저장
            swaps[i][0] = leftPlayer;
            swaps[i][1] = rightPlayer;
        }
        for(int i = 0; i < leagueCnt - 1; i++){
            leagues[i].players.remove(swaps[i][0]);
            leagues[i + 1].players.remove(swaps[i][1]);
            leagues[i].players.put(swaps[i][1], null);
            leagues[i + 1].players.put(swaps[i][0], null);
            res += swaps[i][0].id;
            res += swaps[i][1].id;
        }
        return res;
    }

    int trade() {
        int res = 0;
        for(int i = 0; i < leagueCnt - 1; i++){
            league leftLeague = leagues[i];
            league rightLeague = leagues[i + 1];
            int idx = 0;
            int middleIdx = eachLeaguePlayerCnt / 2;
            for(player p : leftLeague.players.keySet()){
                if(idx++ >= middleIdx){
                    swaps[i][0] = p;
                    break;
                }
            }
            swaps[i][1] = rightLeague.players.firstKey();
        }
        for(int i = 0; i < leagueCnt - 1; i++){
            leagues[i].players.remove(swaps[i][0]);
            leagues[i + 1].players.remove(swaps[i][1]);
            leagues[i].players.put(swaps[i][1], null);
            leagues[i + 1].players.put(swaps[i][0], null);
            res += swaps[i][0].id;
            res += swaps[i][1].id;
        }
        return res;
    }

}