package 좌표_압축;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] sortedArr = Arrays.stream(arr).distinct().sorted().toArray();

        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < arr.length; i++) {
            answer.append(binarySearch(sortedArr, arr[i], 0, sortedArr.length - 1)).append(" ");
        }
        System.out.println(answer);
    }

    private static int binarySearch(int[] arr, int target, int low, int high) {
        while (low<=high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else if (arr[mid] < target) {
                low = mid + 1;
            }
        }
        return 0;
    }
}

/*
[2 4 -10 4 -9]
[-10, -9, 2, 4, 4]
==>
[2, 3, 0, 3, 1]

[1000 999 1000 999 1000 999]
[999 999 999 1000 1000 1000] / TreeSet?
==>
[3, 0, 3, 0, 3, 0]

*/
