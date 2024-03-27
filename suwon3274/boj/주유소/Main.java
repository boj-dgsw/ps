package 주유소;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st2 = new StringTokenizer(br.readLine());

        int[] distance = new int[n - 1];
        for(int i = 1; i<n; i++) {
            distance[i - 1] = Integer.parseInt(st.nextToken());
        }

        int[] stations = new int[n];
        for(int i = 0; i<n; i++) {
            stations[i] = Integer.parseInt(st2.nextToken());
        }

        int bestStation = stations[0];
        long result = (long) bestStation * distance[0];
        for(int i = 1; i<n - 1; i++) {
            if(bestStation > stations[i]) {
                bestStation = stations[i];
            }
            result += (long) bestStation * distance[i];
        }
        System.out.print(result);
    }

}