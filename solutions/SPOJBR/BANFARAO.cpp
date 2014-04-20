#include <stdio.h>

#define INF 1000020000

struct intervalo {
    int val;
    int num;
    
    intervalo(int a=0, int b=0) : val(a), num(b) {}
    
    intervalo operator+(intervalo b) {
        return intervalo(val+b.val, num+b.num);
    }
};

struct data {
	intervalo lf, mf, rf;
	int soma;
	int tam;
};

int values[100000];
data tree[400001];

data null;
intervalo nulint;

intervalo max(intervalo a, intervalo b) {
    if (a.val > b.val) return a;
    else if (a.val == b.val && a.num > b.num) return a;
    return b;
}

data join(data left, data right, int e, int d) {
	data res;
		
	int sep = (e+d)/2;	
	int left_size = sep-e+1;
	int right_size = d-sep;
		
	if (left.soma + right.lf.val >= left.lf.val) {
        res.lf.val = left.soma + right.lf.val;
        res.lf.num = left.tam + right.lf.num;
    }	
    else res.lf = left.lf;
	
	if (right.soma + left.rf.val >= right.rf.val) {
        res.rf.val = right.soma + left.rf.val;
        res.rf.num = right.tam + left.rf.num;
    }	
    else res.rf = right.rf;
		
	res.mf = max(left.mf, right.mf);
	res.mf = max(res.mf, left.rf+right.lf);
		
	res.soma = left.soma + right.soma;
	res.tam = left.tam + right.tam;
	//printf("maxleft (%d,%d) = %d\n",e,d,left.mf.val);
    //printf("max (%d,%d) = %d\n",e,d,res.mf.val);
    	
	return res;
}

data get (int i, int a, int b, int e, int d) {
	if (b < e || a > d) return null;
	if (e >= a && d <= b) return tree[i];
	
	else {
		data left = get(2*i, a, b, e, (e+d)/2);
		data right = get(2*i+1, a, b, (e+d)/2+1, d);
		
		data ret = join(left, right, e, d);
		return ret;
    }
}

void create_tree (int i, int e, int d) {
	if (e == d) {
        tree[i].tam = 1;
        
        //if (values[e] >= 0) {
		  tree[i].soma = tree[i].lf.val = tree[i].mf.val = tree[i].rf.val = values[e];
		  tree[i].lf.num = tree[i].mf.num = tree[i].rf.num = 1;
        //}
        
        /*else {
            tree[i].soma = values[e];
            tree[i].lf.val = tree[i].mf.val = tree[i].rf.val = 0;
		    tree[i].lf.num = tree[i].mf.num = tree[i].rf.num = 0;
        }*/
	}
	
	else {
		create_tree(2*i, e, (e+d)/2);
		create_tree(2*i+1, (e+d)/2 + 1, d);
		
		tree[i] = join(tree[2*i], tree[2*i+1], e, d);
	}
}

int main () {
	int T;
	scanf("%d", &T);
	
	nulint.num=0;
	nulint.val = -INF;
    null.rf=null.lf=null.mf=nulint;
	null.soma = 0;
	
	for (int t = 0; t < T; t++) {
		int N,Q;
        scanf("%d", &N);
		
		int i;
		for (i=0; i<N; i++) {
			scanf("%d", values+i);
		}
		
		create_tree(1, 0, N-1);
		
		scanf("%d", &Q);
		
		for (i=0; i<Q; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
            
			intervalo res = get(1, a-1, b-1, 0, N-1).mf;
			if (res.num == 0) printf("0 0\n");
            else printf("%d %d\n", res.val, res.num);
        }
	}
	
	return 0;
}
