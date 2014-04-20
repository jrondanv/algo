import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;
import java.io.DataInputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Parser in = new Parser(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Subprime solver = new Subprime();
		solver.solve(1, in, out);
		out.close();
	}
}

class Subprime {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        try {
            int B,D;
            while ((B = in.nextInt()) != 0) {
                D = in.nextInt();

                int[] reservas = new int[B];
                for (int i = 0; i < B; i++) {
                    reservas[i] = in.nextInt();
                }

                for (int i = 0; i < D; i++) {
                    int d,c,v;
                    d = in.nextInt()-1;
                    c = in.nextInt()-1;
                    v = in.nextInt();

                    reservas[c] += v;
                    reservas[d] -= v;
                }

                boolean ok = true;
                for (int i = 0; i < B; i++) {
                    if (reservas[i] < 0) ok = false;
                }

                if (ok) out.println('S');
                else out.println('N');
            }
        }
        catch (Exception e) {}
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
