//Problem Name : 296B - Yaroslav and Two Strings
//Execution Time : 186 ms
//Memory : 0 KB
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, OutputWriter out) {
        long a = in.nextLong();
        long b = in.nextLong();

        long cnt = 0;
        while (a != 0 && b != 0) {
            if (a > b) {
                cnt += a / b;
                a %= b;
            }
            else {
                cnt += b / a;
                b = b % a;