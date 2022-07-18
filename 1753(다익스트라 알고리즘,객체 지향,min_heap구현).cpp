#include<iostream>
#include<vector>
using namespace std;


const int INF = 98765432;
int V, E, K;

class Vertex{
public:
	int cur_w = INF;
	int v_num;
	vector<Vertex*> edge;
	vector<int> weight;
	int heap_index;
};

Vertex* vertex_arr[20001];

class Min_Heap {//key : cur_w
public:
	Vertex* heap[20001];
	int size = 0;
	//no insert method
	
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}

	void Min_Heap_ify(int i) {
		int l = this->left(i), r = this->right(i);
		int smallest = i;
		if (l < this->size && (this->heap[l])->cur_w < (this->heap[smallest])->cur_w) {
			smallest = l;
		}
		if (r < this->size && (this->heap[r])->cur_w < (this->heap[smallest])->cur_w) {
			smallest = r;
		}
		if(smallest != i){
			Vertex* temp;
			temp = this->heap[i];
			this->heap[i] = this->heap[smallest];
			this->heap[smallest] = temp;
			int temp2;
			temp2 = this->heap[i]->heap_index;
			this->heap[i]->heap_index = this->heap[smallest]->heap_index;
			this->heap[smallest]->heap_index = temp2;
			this->Min_Heap_ify(smallest);
		}			
	}

	Vertex* Extract_Min() {
		Vertex* ret = this->heap[0];
		this->size--;
		this->heap[0] = this->heap[size];
		this->heap[0]->heap_index = 0;
		this->Min_Heap_ify(0);
		return ret;
	}

	void Decrease_Key(int i, int decreased_cur_w) {
		if (this->heap[i]->cur_w <= decreased_cur_w) {
			//printf("err in Decrease key");
			return;
		}
		this->heap[i]->cur_w = decreased_cur_w;
		while (this->parent(i) >= 0 && this->heap[parent(i)]->cur_w > this->heap[i]->cur_w) {
			//swap
			Vertex* temp;
			int temp2;
			temp = this->heap[i];
			this->heap[i] = this->heap[parent(i)];
			this->heap[parent(i)] = temp;
			temp2 = this->heap[i]->heap_index;
			this->heap[i]->heap_index = this->heap[parent(i)]->heap_index;
			this->heap[parent(i)]->heap_index = temp2;
			i = parent(i);
		}
	}
};

int main(void) {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	for (int i = 1; i <= V; i++) {
		vertex_arr[i] = new Vertex();
		vertex_arr[i]->v_num = i;
	}

	while (E--) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		(vertex_arr[u]->edge).push_back(vertex_arr[v]);
		(vertex_arr[u]->weight).push_back(w);
	}

	Min_Heap h;
	vertex_arr[K]->cur_w = 0;
	vertex_arr[K]->heap_index = 0;
	h.heap[0] = vertex_arr[K];
	h.size++;
	for (int i = 1; i <= V; i++) {
		if (i != K) {
			h.heap[h.size] = vertex_arr[i];
			vertex_arr[i]->heap_index = h.size;
			h.size++;
		}
	}//insert properly

	Vertex* cur_v;
	Vertex* next_v;
	for (int i = 0; i < V; i++) {
		cur_v = h.Extract_Min();
		for (int j = 0; j < cur_v->edge.size(); j++) {
			next_v = cur_v->edge[j];
			if (next_v->cur_w > cur_v->weight[j] + cur_v->cur_w) {
				h.Decrease_Key(next_v->heap_index, cur_v->weight[j] + cur_v->cur_w);
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (vertex_arr[i]->cur_w == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", vertex_arr[i]->cur_w);
		}
	}
	



	exit(0);
}

