/*

Notes: 
- works only with lowercase ascii letters, 
use as sa.extend(c-'a'), sa.st[cur].next[c - 'a'] etc.
- size of string limited to 10^6

Tested on:
- CF 235C - Cyclical Quest
*/

struct SAState {
	int len, link, next[30];
	bool end, is_clon;
	vector<int> inv_link;
};

class SuffixAutomaton {
public:
	static const int MAXLEN = 1000010;
	SAState st[MAXLEN*2];
	int sz, last, len;

	SuffixAutomaton() {
		clear();
	}

	void clear() {
		sz = last = 0;
		st[0].len = 0;
		st[0].link = -1;
		memset(st[0].next, -1, sizeof(st[0].next));
		++sz;
	}

	void extend(int c) {
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		memset(st[cur].next, -1, sizeof(st[cur].next));
		
		int p;
		for (p = last; p != -1 && st[p].next[c] == -1; p = st[p].link) {
			st[p].next[c] = cur;
		}

		if (p == -1) 
			st[cur].link = 0;
		else {
			int q = st[p].next[c];
			if (st[p].len + 1 == st[q].len) 
				st[cur].link = q;
			else {
				int clone = sz++;
				st[clone].is_clon = true;
				st[clone].len = st[p].len + 1;
				memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
				st[clone].link = st[q].link;
				for (; p != -1 && st[p].next[c] == q; p = st[p].link) 
					st[p].next[c] = clone;
				st[q].link = st[cur].link = clone;
			}
		}

		last = cur;
	}

	void postprocess() {
		for (int v = 1; v < sz; v++)
			st[st[v].link].inv_link.push_back(v);
		for (int p = last; p != -1; p = st[p].link)
			st[p].end = true;
	}
};