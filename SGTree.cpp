class SegTree {
public:
	int len;
	vector<long long int> t;

	SegTree() {}
	SegTree(int l) {
		len = l;
		t.resize(4 * len);
	}

	void build(vector<long long int>& a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(a, 2 * v, tl, tm);
		build(a, 2 * v + 1, tm + 1, tr);
		t[v] = t[2 * v] + t[2 * v + 1];
	}

	long long int query(int v, int tl, int tr, int l, int r) {
		if (tl > r || tr < l) return 0;
		if (l <= tl && tr <= r) return t[v];

		int tm = (tl + tr) / 2;
		long long int leftAns = query(2 * v, tl, tm, l, r);
		long long int rightAns = query(2 * v + 1, tm + 1, tr, l, r);
		return leftAns + rightAns;
	}

	void update(int v, int tl, int tr, int id, long long int val) {
		if (tl == id && tr == id) {
			t[v] = val;
			return;
		}
		if (id > tr || id < tl) return;

		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, id, val);
		update(2 * v + 1, tm + 1, tr, id, val);
		t[v] = t[2 * v] + t[2 * v + 1];
	}

	void build(vector<long long int>& a) {
		build(a, 1, 0, len - 1);
	}

	long long int query(int l, int r) {
		return query(1, 0, len - 1, l, r);
	}

	void update(int id, long long int val) {
		update(1, 0, len - 1, id, val);
	}
};
