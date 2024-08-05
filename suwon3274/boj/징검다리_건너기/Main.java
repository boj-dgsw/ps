package 징검다리_건너기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int n, k, min = Integer.MAX_VALUE;
    static int[] smallJumps, bigJumps;

    static void dfs(int index, int energy, boolean jump) {
        if(n == index) {
            min = Math.min(min, energy);
        }

        if(index + 1 <= n) {
            dfs(index + 1, energy + smallJumps[index], jump);
        }
        if(index + 2 <= n) {
            dfs(index + 2, energy + bigJumps[index], jump);
        }
        if(index + 3 <= n && !jump) {
            dfs(index + 3, energy + k, true);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        smallJumps = new int[n];
        bigJumps = new int[n];

        for(int i = 1; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            smallJumps[i] = Integer.parseInt(st.nextToken());
            bigJumps[i] = Integer.parseInt(st.nextToken());
        }
        k = Integer.parseInt(br.readLine());

        dfs(1, 0, false);
        System.out.print(min);
    }

}
