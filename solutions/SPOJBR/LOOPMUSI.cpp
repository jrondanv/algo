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
		LoopMusical solver = new LoopMusical();
		solver.solve(1, in, out);
		out.close();
	}
}

class LoopMusical {

    private boolean ok(int a, int b, int c) {
        return (b > a && b > c) || (b < a && b < c);
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        try {
            int size = in.nextInt();
            do {
                int[] ourNumbers = new int[size];

                int ans = 0;
                for (int i = 0; i < ourNumbers.length; i++) {
                    ourNumbers[i] = in.nextInt();
                }

                if (size <= 2) {
                    out.println(size);
                }
                else {
                    if (ok(ourNumbers[size-1], ourNumbers[0], ourNumbers[1])) ans++;
                    if (ok(ourNumbers[size-2], ourNumbers[size-1], ourNumbers[0])) ans++;

                    for (int i = 1; i < ourNumbers.length-1; i++) {
                        if (ok(ourNumbers[i-1], ourNumbers[i], ourNumbers[i+1])) ans++;
                    }

                    out.println(ans);
                }

                size = in.nextInt();
            } while (size != 0);
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