package _2더하기1_세일;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Integer[] items = new Integer[n];

        for(int i = 0; i<n; i++) {
            items[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(items, Collections.reverseOrder());

        long result = 0;
        for(int i = 0; i<n; i++) {
            if(i%3 != 2) {
                result += items[i];
            }
        }
        System.out.print(result);
    }

}