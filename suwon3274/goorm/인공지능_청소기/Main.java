import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        while(t-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            int shortest = Math.abs(x) + Math.abs(y);
            if(shortest > n) {
                sb.append("NO");
            } else {
                sb.append((n - shortest) % 2 == 0 ? "YES" : "NO");
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }

}
