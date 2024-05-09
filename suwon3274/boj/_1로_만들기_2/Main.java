package _1로_만들기_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        boolean[] visit = new boolean[n + 1];
        Queue<Node> que = new LinkedList<>();
        List<Integer> startList = new ArrayList<>();
        startList.add(n);
        que.add(new Node(n, 0, startList));
        while(!que.isEmpty()) {
            Node node = que.poll();
            int num = node.num;
            int cnt = node.cnt;
            List<Integer> list = node.list;

            if(!visit[num]) {
                visit[num] = true;

                if(1 == num) {
                    System.out.println(cnt);
                    for(int next : list) {
                        System.out.print(next + " ");
                    }
                    return ;
                }

                if(num % 3 == 0) {
                    List<Integer> newList = new ArrayList<>(list);
                    newList.add(num / 3);
                    que.add(new Node(num / 3, cnt + 1, newList));
                }
                if(num % 2 == 0) {
                    List<Integer> newList = new ArrayList<>(list);
                    newList.add(num / 2);
                    que.add(new Node(num / 2, cnt + 1, newList));
                }
                if(num - 1 > 0) {
                    List<Integer> newList = new ArrayList<>(list);
                    newList.add(num - 1);
                    que.add(new Node(num - 1, cnt + 1, newList));
                }
            }
        }
    }

    static class Node {

        int num;
        int cnt;
        List<Integer> list;

        Node(int num, int cnt, List<Integer> list) {
            this.num = num;
            this.cnt = cnt;
            this.list = list;
        }

    }

}
