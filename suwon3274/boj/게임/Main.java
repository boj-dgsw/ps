import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int answer = Integer.MAX_VALUE;
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        int z = (int) (y * 100.0 / x);
        int l = 1;
        int r = x;
        while(l<=r) {
            int m = (l + r) / 2;
            int newZ = (int) ((y + m) * 100.0 / (x + m));

            if(newZ > z) {
                answer = Math.min(answer, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
    }

}