/**
IMPORTANT:
- add lines in this order: smallest a first, break ties by smallest b first

Tested on CF 91E - Igloo Skyscraper 
*/

class ConvexHullTrick {
    struct CHTPoint {
        double x, y;
        int idx;
        double lim;
    };

    vector<CHTPoint> pilha;

    inline double get_intersection(CHTPoint a, CHTPoint b) {
        double denom = ( double(b.x) - a.x);
        double num = ( double(b.y) - a.y);
        
        return - num / denom;
    }

    bool ccw(CHTPoint p0, CHTPoint p1, CHTPoint p2) {
        return ((p1.y-p0.y)*(p2.x-p0.x) > (p2.y-p0.y)*(p1.x-p0.x));
    }

    public:

    void add_line(double a, double b, int idx) {
        CHTPoint novo = {a, b, idx, 0};
        int tam = pilha.size();
        while (tam >= 2 && !ccw(pilha[tam-2], pilha[tam-1], novo)) {
            pilha.pop_back();
            tam--;
        }
        while (tam >= 1 && fabs(pilha[tam-1].x - a) < 1e-8) {
            pilha.pop_back();
            tam--;
        }

        pilha.push_back(novo);
        if (tam >= 1) pilha[tam-1].lim = get_intersection(pilha[tam-1], pilha[tam]);
    }

    pair<int, double> get_maximum(double x) {
        int st = 0, ed = pilha.size() - 1;
        while (st < ed) {
            int mid = (st+ed)/2;
            if (pilha[mid].lim < x) st = mid+1;
            else ed = mid;
        }

        return make_pair(pilha[st].idx, pilha[st].x * x + pilha[st].y);
    }
};