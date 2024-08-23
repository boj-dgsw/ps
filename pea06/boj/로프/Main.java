package 로프;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] ropes = new int[n];
        for (int i = 0; i < n; i++) {
            ropes[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(ropes);
        Integer[] w = new Integer[ropes.length];
        for (int i = 0; i < ropes.length; i++) {
            w[i] = ropes[i] * n;
            n--;
        }
        Arrays.sort(w, Collections.reverseOrder());
        System.out.println(w[0]);
    }
}