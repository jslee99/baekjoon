import java.util.Comparator;
import java.util.PriorityQueue;

class UserSolution {
    static class Player implements Comparable<Player>{
        int id;
        int ability;
        int ver;

        public Player(int id, int ability, int ver) {
            this.id = id;
            this.ability = ability;
            this.ver = ver;
        }

        @Override
        public int compareTo(Player o) {
            return this.ability != o.ability ? Integer.compare(this.ability, o.ability) : -Integer.compare(this.id, o.id);
        }

        @Override
        public String toString() {
            return "" + id + " " + ability + " " + ver;
        }
    }
    static class League{
        PriorityQueue<Player> maxQ;
        PriorityQueue<Player> minQ;

        PriorityQueue<Player> leftMaxQ;//max
        PriorityQueue<Player> rightMinQ;//min

    }
    static int N, L, playerCntEachLeague;
    static League[] leagues;
    static Player[] players;
    static Player[][] swaps;
    void init(int n, int l, int mAbility[]) {
        N = n; L = l; playerCntEachLeague = N / L;
        swaps = new Player[L - 1][2];//idx : 0의 의미 -> league 0과 league 1의 swap
        leagues = new League[L];
        for(int i = 0; i < L; i++){
            leagues[i] = new League();
            League league = leagues[i];
            league.maxQ = new PriorityQueue<>(Comparator.reverseOrder());
            league.minQ = new PriorityQueue<>();
            league.leftMaxQ = new PriorityQueue<>(Comparator.reverseOrder());
            league.rightMinQ = new PriorityQueue<>();
            //leftQ와 rightQ에 dummy 추가
            league.leftMaxQ.offer(new Player(Integer.MAX_VALUE, -1, -1));
            league.rightMinQ.offer(new Player(-1, Integer.MAX_VALUE, -1));
        }
        players = new Player[N];
        int id = 0;
        for(int i = 0; i < L; i++){
            for(int j = 0; j < playerCntEachLeague; j++){
                int ability = mAbility[id];
                players[id] = new Player(id, ability, 0);
                League league = leagues[i];
                league.maxQ.offer(new Player(id, ability, 0));
                league.minQ.offer(new Player(id, ability, 0));
                //중간 pq 관리
                if(players[id].compareTo(league.leftMaxQ.peek()) < 0){
                    if(league.leftMaxQ.size() > league.rightMinQ.size()){
                        league.rightMinQ.offer(league.leftMaxQ.poll());
                        league.leftMaxQ.offer(new Player(id, ability, 0));
                    }else{
                        league.leftMaxQ.offer(new Player(id, ability, 0));
                    }
                }else if(players[id].compareTo(league.leftMaxQ.peek()) > 0 && players[id].compareTo(league.rightMinQ.peek()) < 0){
                    if(league.leftMaxQ.size() > league.rightMinQ.size()){
                        league.rightMinQ.offer(new Player(id, ability, 0));
                    }else{
                        league.leftMaxQ.offer(new Player(id, ability, 0));
                    }
                }else{
                    if(league.leftMaxQ.size() > league.rightMinQ.size()){
                        league.rightMinQ.offer(new Player(id, ability, 0));
                    }else{
                        league.leftMaxQ.offer(league.rightMinQ.poll());
                        league.rightMinQ.offer(new Player(id, ability, 0));
                    }
                }
                id++;
            }
        }
    }

    static void clean(PriorityQueue<Player> pq){
        //ver이 -1이나 MAX_VALUE가 나올 수 있는 경우가 있나?
        while (pq.peek().ver != -1 && pq.peek().ver != Integer.MAX_VALUE && pq.peek().ver < players[pq.peek().id].ver)
            pq.poll();
    }
    int move() {
//        for(int i = 0; i < L; i++){
//            League l = leagues[i];
//            clean(l.maxQ);
//            clean(l.minQ);
//            clean(l.leftMaxQ);
//            clean(l.rightMinQ);
//        }

        int res = 0;
        //빼내기, 버전 up
        for(int i = 0; i < L - 1; i++){
            League leftLeague = leagues[i];
            League rightLeague = leagues[i + 1];
            clean(leftLeague.minQ);
            Player leftPlayer = leftLeague.minQ.poll();
            clean(rightLeague.maxQ);
            Player rightPlayer = rightLeague.maxQ.poll();

            players[leftPlayer.id].ver = ++leftPlayer.ver;
            players[rightPlayer.id].ver = ++rightPlayer.ver;

            swaps[i][0] = leftPlayer;
            res += leftPlayer.id;
            swaps[i][1] = rightPlayer;
            res += rightPlayer.id;
        }

        //이동시키기 other words 넣기
        for(int i = 0; i < L - 1; i++){

            {
                Player leftPlayer = swaps[i][0];
                League rightLeague = leagues[i + 1];

                //from left to right
                rightLeague.maxQ.offer(leftPlayer);
                rightLeague.minQ.offer(leftPlayer);
                clean(rightLeague.leftMaxQ);
                clean(rightLeague.rightMinQ);
                if(i >= L - 2){
                    //차이가 2이므로 균형을 맞춰줌
                    rightLeague.rightMinQ.offer(rightLeague.leftMaxQ.poll());
                    clean(rightLeague.leftMaxQ);
                    //차이가 0이됨
                    if(leftPlayer.compareTo(rightLeague.rightMinQ.peek()) < 0){
                        rightLeague.leftMaxQ.offer(leftPlayer);
                    }else{
                        rightLeague.leftMaxQ.offer(rightLeague.rightMinQ.poll());
                        rightLeague.rightMinQ.offer(leftPlayer);
                    }
                }else{
                    //일단 leftQ rightQ 차이가 1임
                    if(leftPlayer.compareTo(rightLeague.leftMaxQ.peek()) < 0){
                        rightLeague.rightMinQ.offer(rightLeague.leftMaxQ.poll());
                        rightLeague.leftMaxQ.offer(leftPlayer);
                    }else{
                        rightLeague.rightMinQ.offer(leftPlayer);
                    }
                }
            }

            //from right to left
            {
                League leftLeague = leagues[i];
                Player rightPlayer = swaps[i][1];
                leftLeague.minQ.offer(rightPlayer);
                leftLeague.maxQ.offer(rightPlayer);
                clean(leftLeague.rightMinQ);
                clean(leftLeague.leftMaxQ);
                if(i == 0){
                    //차이가 없음
                    if(rightPlayer.compareTo(leftLeague.rightMinQ.peek()) < 0){
                        leftLeague.leftMaxQ.offer(rightPlayer);
                    }else{
                        leftLeague.leftMaxQ.offer(leftLeague.rightMinQ.poll());
                        leftLeague.rightMinQ.offer(rightPlayer);
                    }
                }else{
                    //차이가 0임
                    if(rightPlayer.compareTo(leftLeague.rightMinQ.peek()) < 0){
                        leftLeague.leftMaxQ.offer(rightPlayer);
                    }else{
                        leftLeague.leftMaxQ.offer(leftLeague.rightMinQ.poll());
                        leftLeague.rightMinQ.offer(rightPlayer);
                    }
                }
            }
        }
        return res;
    }

    int trade(){
        return 0;
    }

}