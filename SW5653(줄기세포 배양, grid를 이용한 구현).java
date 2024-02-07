
import java.util.*;
import java.io.*;

public class Solution {
    static Cell[][] grid;
    static int sr, sc;
    static int T, N, M, K;
    static List<Cell> liveCells;
    static int[] dr = {-1, 0, 1, 0}, dc = {0, -1, 0, 1};

    static enum State{
        noActive,
        active,
        die
    }

    static class Cell{
        int r;
        int c;
        int life;
        int remainTime;
        State state;
        boolean create;
        public Cell(int r, int c, int life) {
            super();
            this.r = r;
            this.c = c;
            this.life = life;
            this.remainTime = life;
            this.state = State.noActive;
            create = true;
        }

    }

    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream("res/sample_input (4).txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int TC = 1; TC <= T; TC++) {
            grid = new Cell[1500][1500];
            sr = 700;
            sc = 700;
            st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
            liveCells = new ArrayList<>();
            for(int i = sr; i < sr + N; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for(int j = sc; j < sc + M; j++) {
                    int life = Integer.parseInt(st.nextToken());
                    if(life > 0) {
                        grid[i][j] = new Cell(i,j, life);
                        liveCells.add(grid[i][j]);
                    }
                }
            }

            for(int k = 1; k <= K; k++) {
                List<Cell> updateLiveCells = new ArrayList<>();
                for(Cell cell : liveCells){
                    cell.create = false;
                }
                //cell.create를 먼저 처리해주어야함.
                //단순히 remainTime == life로 create된 세포인지 식별하면 liveCells에서의 순서에 따라 결과가 달라 질 수 있음
                //좀더 풀어서 말하면 만약 이전 for문에서 만들어지 before cell이 liveCelss에서 맨뒤에 있다고 치자. 그러면 현재 for문에서 liveCells의 앞에서 다른 cell이 before cell에 대한 판단을 remainTIme == life로 해버리면 현재 for문에서 그 cell이 만들어졌다고 잘못 판단 하는 경우가 생긴다. 그렇기 때문에 create멤버 변수를 통해 현재 for문에서 생성된 cell인지 판단하는 로직이 필요하다.
                for(Cell cell : liveCells) {
                    if(cell.state == State.noActive) {
                        if(--cell.remainTime <= 0) {
                            cell.remainTime = cell.life;
                            cell.state = State.active;
                        }
                        updateLiveCells.add(cell);
                    }else if(cell.state == State.active) {
                        for(int d = 0; d < 4; d++) {
                            int nr = cell.r + dr[d], nc = cell.c + dc[d];
                            if(grid[nr][nc] == null) {
                                grid[nr][nc] = new Cell(nr, nc, cell.life);
                                updateLiveCells.add(grid[nr][nc]);
                            }else {
                                Cell existsCell = grid[nr][nc];
                                if(existsCell.create) {
                                    existsCell.life = Math.max(existsCell.life, cell.life);
                                    existsCell.remainTime = existsCell.life;
                                }
                            }
                        }
                        if(--cell.remainTime <= 0) {
                            cell.state = State.die;
                        }else {
                            updateLiveCells.add(cell);
                        }
                    }else {
                        throw new IllegalStateException();
                    }
                }
                liveCells = updateLiveCells;
            }
            sb.append("#").append(TC).append(" ").append(liveCells.size()).append("\n");
        }
        System.out.println(sb);
        br.close();
    }
}

