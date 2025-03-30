
### 


general tree

binary tree



### Heap/Priority que

A _heap_ or more precisely a _max heap_ is a (binary) tree such that for every node the key of the parent node is greater than or equal to the key of the node.

```c++
vector<int> heap; // max heap

void insert(int x) { // sift up
	heap.push_back(x)
	int node = heap.size() - 1;
	int parent = node / 2;
	while (node > 1) {
		if (heap[parent] < heap[node])
			swap(heap[parent], heap[node]),
			node = parent;
		else break;
	}
}

void siftDown(int node) {
	int left = 2 * node, right = 2 * node + 1;
	while (left <= heap.size() - 1)
		if (left == heap.size() - 1)
			if (heap[node] < heap[left])
				swap(heap[node], heap[left]),
				node = left;
			else break;
		else
			if(heap[node] < heap[left] || heap[node] < heap[right])
				if(heap[left] > heap[right])
					swap(heap[node], heap[left]),
					node = left;
				else
					swap(heap[node], heap[right]),
					node = right;
			else break;
}

void pop(){
	heap[1] = heap.back(), heap.pop_back();
	siftDown(1);
}

void heapify(vector<int>& arr){ // sift down, O(n)
	heap.clear(), heap.push_back(-1);
	for(int i = 0; i < arr.size(); i++)
		heap.push_back(arr[i]);
	for(int i = heap.size() - 1; i > 0; i--)
		siftDown(i);
}
```




### Binary search tree
AVL

```c++
class Node {
public:
	int key;
	Node* left;
	Node* right;
	Node(int key) {
		this.key = key;
		left = NULL;
		right = NULL;
	}
};

void rotateLeft(Node** node){
	return;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	rotateLeft(&root);
}

```

### Game tree



### Segment tree


```c++
class SegTree {
public:
	vector<int> seg;
	int n;

	SegTree(const vector<int>& arr){
		n = arr.size();
		init(arr);
	}
	int init(const vector<int>& arr, int a=0, int b=n-1, int node=1){
		if(a==b) return seg[node] = arr[a];
		int m=(a+b)/2;
		return seg[node] = init(arr,a,m,node*2)+init(arr,m+1,b,node*2+1);
	}
	int query(int l, int r, int a=0, int b=n-1, int node=1){
		if(b<l || r<a) return 0;
		if(l<=a && b<=r) return seg(node);
		int m=(a+b)/2;
		return query(l,r,a,m,node*2)+query(l,r,m+1,b,node*2+1);
	}
}
```




### Trie

