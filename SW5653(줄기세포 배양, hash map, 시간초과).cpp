#include<iostream>
#include<map>
#include<vector>
#include<utility>

using namespace std;

enum State {
    noActive,
    active,
    die
};

class Cell {
public:
    int life;
    int remainTime;
    State state;
    Cell(int life) {
        this->life = life;
        this->remainTime = life;
        this->state = noActive;
    }
};
int T, N, M, K;
map<pair<int, int>, Cell*> allMap;
map<pair<int, int>, Cell*> liveMap;
//상좌하우
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> N >> M >> K;
        allMap.clear();
        liveMap.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int life;
                cin >> life;
                Cell* cell = new Cell(life);
                if (life > 0) {
                    allMap.insert(make_pair(make_pair(i, j), cell));
                    liveMap.insert(make_pair(make_pair(i, j), cell));
                }
            }
        }

        for (int k = 1; k <= K; k++) {
            vector<pair<int, int>> dyingPos;
            map<pair<int, int>, Cell*> newCell;

            for (map<pair<int, int>, Cell*>::iterator it = liveMap.begin(); it != liveMap.end(); it++) {
                pair<int, int> pos = (*it).first;
                Cell* cell = (*it).second;
                if (cell->state == noActive) {
                    if (--cell->remainTime <= 0) {
                        cell->remainTime = cell->life;
                        cell->state = active;
                    }
                }
                else if (cell->state == active) {
                    for (int d = 0; d < 4; d++) {
                        int nr = pos.first + dr[d], nc = pos.second + dc[d];
                        if (newCell.find(make_pair(nr, nc)) != newCell.end()) {
                            //현재 경쟁관계에 있는 즉 같이 번식하려는 세포가 존재함.
                            map<pair<int, int>, Cell*>::iterator iter = newCell.find(make_pair(nr, nc));
                            pair<int, int> existsPos = (*iter).first;
                            Cell* existsCell = (*iter).second;
                            //생명력 비교
                            if (cell->life > existsCell->life) {
                                existsCell->life = cell->life;
                                existsCell->remainTime = existsCell->life;
                            }
                        }
                        else if (allMap.find(make_pair(nr, nc)) != allMap.end()) {
                            //이미 세포가 존재함. 건너뛴다.
                            continue;
                        }
                        else {
                            //비어있음, 번식
                            newCell.insert(make_pair(make_pair(nr, nc), new Cell(cell->life)));
                        }
                    }
                    if (--cell->remainTime <= 0) {
                        cell->state = die;
                        dyingPos.push_back(pos);
                    }
                }
                else {
                    return -1;
                }
            }

            for (int i = 0; i < dyingPos.size(); i++) {
                liveMap.erase(dyingPos[i]);
            }

            for (map<pair<int, int>, Cell*>::iterator iter = newCell.begin(); iter != newCell.end(); iter++) {
                allMap.insert(*iter);
                liveMap.insert(*iter);
            }
        }

        cout << "#" << TC << " " << liveMap.size() << '\n';
    }
}