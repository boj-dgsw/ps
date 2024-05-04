import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            int N = scanner.nextInt();
            if (N == 0) break;

            List<String> s1 = new ArrayList<>();
            List<String> s2 = new ArrayList<>();
            List<String> s3 = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                String tmp = scanner.next();
                s1.add(tmp);
                tmp = tmp.toLowerCase();
                s2.add(tmp);
                s3.add(tmp);
            }
            Collections.sort(s2);
            String res = s2.get(0);
            int idx = 0;
            for (int i = 0; i < s3.size(); i++) {
                if (s3.get(i).equals(res)) {
                    idx = i;
                    break;
                }
            }
            System.out.println(s1.get(idx));
        }

        scanner.close();
    }
}
