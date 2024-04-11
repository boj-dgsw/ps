package 현대모비스_입사_프로젝트;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<Class> classes = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            StringTokenizer st2 = new StringTokenizer(br.readLine());
            classes.add(new Class(
                    Integer.parseInt(st2.nextToken()),
                    Integer.parseInt(st2.nextToken()),
                    Integer.parseInt(st2.nextToken())
            ));
        }

        int abSum = 0;
        classes.sort((o1, o2) -> o2.ab - o1.ab);
        for(int i = 0; i<k; i++) {
            abSum += classes.get(i).ab;
        }

        int acSum = 0;
        classes.sort((o1, o2) -> o2.ac - o1.ac);
        for(int i = 0; i<k; i++) {
            acSum += classes.get(i).ac;
        }

        int bcSum = 0;
        classes.sort((o1, o2) -> o2.bc - o1.bc);
        for(int i = 0; i<k; i++) {
            bcSum += classes.get(i).bc;
        }

        System.out.print(Math.max(abSum, Math.max(acSum, bcSum)));
    }

    static class Class {

        int ab, ac, bc;

        Class(int a, int b, int c) {
            this.ab = a + b;
            this.ac = a + c;
            this.bc = b + c;
        }

    }

}
