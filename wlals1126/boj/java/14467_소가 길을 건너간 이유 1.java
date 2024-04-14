import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[11];
        Arrays.fill(arr, -1);
        StringTokenizer st;
        int cnt = 0;

        while (N-- > 0) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            if (arr[i] != -1 && arr[i] != j)
                cnt++;
            arr[i] = j;
        }

        System.out.print(cnt);
    }
}