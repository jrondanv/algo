import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.DataInputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
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
		Manutencao solver = new Manutencao();
		solver.solve(1, in, out);
		out.close();
	}
}

class Manutencao {
    static boolean[][] a;
    static int n, m, k;
    static int[] num, low;
    static ArrayList<Integer>[] children;

    public void solve(int testNumber, Parser in, PrintWriter out)
    {
        try {
        int teste = 1;
        while((n = in.nextInt()) != 0)
        {
            out.println("Teste " + (teste++));
            a = new boolean[n][n]; //Adjacency matrix
            HashSet<Integer> roots = new HashSet<Integer>(); //Set of all roots

            m = in.nextInt();

            for (int i = 0; i < m; i++) {
                int v1 = in.nextInt();
                int v2 = in.nextInt();
                v1--; v2--;
                a[v1][v2] = a[v2][v1] = true;
            }

            num = new int[n];
            low = new int[n];
            children = new ArrayList[n];
            k = 0;
            Arrays.fill(num, -1);
            Arrays.fill(low, 999999999);

            for(int i=0;i < n;i++)
                children[i] = new ArrayList<Integer>();

            for(int i=0;i < n;i++)
            {
                if(num[i] == -1)
                {
                    getNumLow(i);
                    roots.add(i);
                }
            }

            ArrayList<Integer> rtn = new ArrayList<Integer>();

            //Check roots separately
            for(int v : roots)
            {
                if(children[v].size() > 1)
                    rtn.add(v);
            }

            //Check other vertices
            for(int i=0;i < n;i++)
            {
                if(roots.contains(i))
                    continue;

                for(int j=0;j < children[i].size();j++)
                {
                    int v = children[i].get(j);
                    if(low[v] >= num[i])
                    {
                        rtn.add(i);
                        break;
                    }
                }
            }

            if (rtn.isEmpty()) out.println("nenhum");
            else {
                for (int x: rtn) {
                    out.print((x+1) + " ");
                }
                out.println();
            }
            out.println();
        }
        } catch (Exception e) {   }
    }



    public static int getNumLow(int v)
    {
        num[v] = k++;
        low[v] = num[v];

        for(int i=0;i < n;i++) //Note: This is not sparse! Replace with edge array for sparseness
        {
            if(a[v][i] && num[i] >= 0)
            {
                low[v] = Math.min(low[v], num[i]);
            }
            if(a[v][i] && num[i] == -1)
            {
                low[v] = Math.min(low[v], getNumLow(i));
                children[v].add(i);
            }
        }

        return low[v];
    }

}

class Parser
{
    final private int BUFFER_SIZE = 1 << 16;

    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Parser(InputStream in)
    {
        din = new DataInputStream(in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public int nextInt() throws Exception
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ') c = read();
        boolean neg = c == '-';
        if (neg) c = read();
        do
        {
            ret = ret * 10 + c - '0';
            c = read();
        } while (c > ' ');
        if (neg) return -ret;
        return ret;
    }

    private void fillBuffer() throws Exception
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) buffer[0] = -1;
    }

    private byte read() throws Exception
    {
        if (bufferPointer == bytesRead) fillBuffer();
        return buffer[bufferPointer++];
    }
}
