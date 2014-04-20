import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ffao
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Parser in = new Parser(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Cavalo solver = new Cavalo();
		try {
			int testNumber = 1;
			while (true)
				solver.solve(testNumber++, in, out);
		} catch (UnknownError e) {
			out.close();
		}
	}
}

class Cavalo {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        MaxFlow mf = new MaxFlow(n+m+2);
        int source = n+m+1;
        int sink = n+m;
        for (int i = 0; i < n; i++) {
            int r = in.nextInt();
            mf.addEdge(source, i, r);
        }

        for (int i = 0; i < k; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            mf.addEdge(u, n+v, 1);
        }

        for (int i = 0; i < m; i++) {
            mf.addEdge(n+i, sink, 1);
        }

        out.println("Instancia " + testNumber);
        out.println(mf.getFlow(source, sink));
        out.println();
    }
}

class Parser
{
    private BufferedReader din;
    private StringTokenizer tokenizer;

    public Parser(InputStream in)
    {
        din = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(din.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    }

class MaxFlow {
    int n;
    ArrayList<Edge> g[];

    public MaxFlow(int n) {
        this.n = n;

        g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList();
    }

    public void addEdge(int from, int to, int cap) {
        if (from == to) return;
        Edge forward = new Edge(from, to, cap);
        Edge backward = new Edge(to, from, 0);

        forward.setPair(backward);
        backward.setPair(forward);

        g[from].add(forward);
        g[to].add(backward);
    }

    public long augment(int s, int t) {
        Edge[] p = new Edge[n];
        int[] q = new int[n];

        p[s] = Edge.start;

        int head = 0, tail = 0;
        q[tail++] = s;
        while (head < tail) {
            int x = q[head++];
            for (Edge e : g[x]) {
                if (p[e.to] == null && e.cap > e.flow) {
                    p[e.to] = e;
                    q[tail++] = e.to;
                }
            }
        }
        if (p[t] == null) return 0;

        long flow = 0;
        for (Edge e : g[t]) {
            Edge start = e.pair;
            int bot = Constants.INF;

            for (Edge te = start; bot != 0 && te != Edge.start; te = p[te.from]) {
                if (te == null) { bot = 0; break; }
                bot = Math.min(bot, te.cap - te.flow);
            }

            if (bot == 0) continue;

            for (Edge te = start; te != Edge.start; te = p[te.from]) {
                te.flow += bot;
                te.pair.flow -= bot;
            }

            flow += bot;
        }
        return flow;
    }

    public long getFlow(int s, int t) {
        long ans = 0, flow;
        while ((flow = augment(s,t)) != 0) {
            ans += flow;
        }
        return ans;
    }
}

class Edge {
    public static Edge start = new Edge();
    int from, to, cap, flow;
    Edge pair;

    public Edge() {}
    public Edge(int from, int to, int cap) {
        this.from = from;
        this.to = to;
        this.cap = cap;
        this.flow = 0;
    }

    public void setPair(Edge ot) {
        pair = ot;
    }

    }

class Constants {
    public static int INF = 1000000010;
}
