import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int f = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int g = Integer.parseInt(st.nextToken());
        int u = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        boolean[] visit = new boolean[f + 1];
        Queue<Click> que = new LinkedList<>();
        que.add(new Click(s, 0));

        while(!que.isEmpty()) {
            Click click = que.poll();
            int position = click.position;
            int count = click.count;

            if(!visit[position]) {
                visit[position] = true;

                if(g == position) {
                    System.out.print(count);
                    return ;
                }

                if(position + u <= f) {
                    que.add(new Click(position + u, count + 1));
                }
                if(position - d > 0) {
                    que.add(new Click(position - d, count + 1));
                }
            }
        }

        System.out.print("use the stairs");
    }

    static class Click {

        int position, count;

        Click(int position, int count) {
            this.position = position;
            this.count = count;
        }

    }

}
