package 최소비용_구하기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<City>[] graph;
    static int[] distances;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        distances = new int[n + 1];
        graph = new List[n + 1];
        for(int i = 1; i<=n; i++) {
            graph[i] = new ArrayList<>();
            distances[i] = Integer.MAX_VALUE;
        }

        while(m-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int destination = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());
            graph[start].add(new City(destination, weight));
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int destination = Integer.parseInt(st.nextToken());

        distances[start] = 0;
        PriorityQueue<City> que = new PriorityQueue<>(Comparator.comparingInt(c -> c.weight));
        que.add(new City(start, 0));

        while(!que.isEmpty()) {
            City city = que.poll();
            int num = city.num;
            int weight = city.weight;

            if(distances[num] < weight) {
                continue;
            }

            for(City next : graph[num]) {
                if(distances[next.num] > weight + next.weight) {
                    distances[next.num] = weight + next.weight;
                    que.add(new City(next.num, distances[next.num]));
                }
            }
        }

        for(int i = 1; i<=n; i++) {
            System.out.println(distances[i]);
        }
        System.out.println(distances[destination]);
    }

    static class City {

        int num, weight;

        City(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }

    }

}
