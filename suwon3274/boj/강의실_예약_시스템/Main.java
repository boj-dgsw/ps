package 강의실_예약_시스템;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] rooms = new int[n + 1];

        for(int i = 0; i<m; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            int room = Integer.parseInt(st2.nextToken());
            int start = Integer.parseInt(st2.nextToken());
            int end = Integer.parseInt(st2.nextToken());

            if(rooms[room] > start) {
                sb.append("NO").append("\n");
                continue;
            }

            sb.append("YES").append("\n");
            rooms[room] = end;
        }

        System.out.print(sb);
    }

}
