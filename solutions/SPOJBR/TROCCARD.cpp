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
		TROCCARD solver = new TROCCARD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TROCCARD {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        try {
        int A, B;
        while ((A = in.nextInt()) != 0) {
            B = in.nextInt();

            boolean [] alice = new boolean[100001];
            boolean [] bcard = new boolean[100001];
            boolean [] common = new boolean[100001];

            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < A; i++) {
                int th = in.nextInt();
                if (!alice[th]) {
                    alice[th]=true;
                    cnt1++;
                }
            }

            for (int i = 0; i < B; i++) {
                int th = in.nextInt();
                if (alice[th]) {
                    if (!common[th]) {
                        common[th] = true;
                        cnt1--;
                    }
                    if (!bcard[th]) cnt2--;
                }

                if (!bcard[th]) {
                    bcard[th] = true;
                    cnt2++;
                }
            }

            out.println(Math.min(cnt1, cnt2));
        }

        } catch (Exception e) {}
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
