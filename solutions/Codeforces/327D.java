//Problem Name : 327D - Block Tower
//Execution Time : 1843 ms
//Memory : 192700 KB
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    boolean[][] visited = new boolean[500][500];
    String[] board;
    int n, m;

    PrintWriter out;
    ArrayList<String> ans = new ArrayList<String>();

    public void dfs(int x, int y, boolean st) {
        if (board[x].charAt(y) == '#') return;
        if (visited[x][y]) return;
        visited[x][y] = true;

        ans.add("B " + (x+1) + " " + (y+1));

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx*dy != 0 || dx+dy == 0) continue;

                int nx = x+dx;
                int ny = y+dy;
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= m) continue;

                dfs(nx, ny, false);
            }
        }

        if (!st) {
            ans.add("D " + (x + 1) + " " + (y + 1));
            ans.add("R " + (x + 1) + " " + (y + 1));
        }
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        this.out = out;
        n = in.nextInt();
        m = in.nextInt();
        board = new String[n];
        for (int i = 0; i < n; i++) board[i] = in.next();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    dfs(i, j, true);
                }
            }
        }

        out.println(ans.size());
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < ans.size(); i++) {
            s.append(ans.get(i));
            s.append('\n');
        }
        out.print(s.toString());
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
