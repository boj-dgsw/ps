package 재귀함수가_뭔가요;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static StringBuilder sb;

    static void chatBot(int depth, int end) {
        underBar(depth);
        sb.append("\"재귀함수가 뭔가요?\"").append("\n");
        if(depth == end) {
            underBar(depth);
            sb.append("\"재귀함수는 자기 자신을 호출하는 함수라네\"").append("\n");
            saidThat(depth);
            return ;
        } else {
            underBar(depth);
            sb.append("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.").append("\n");
            underBar(depth);
            sb.append("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.").append("\n");
            underBar(depth);
            sb.append("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"").append("\n");
        }
        chatBot(depth + 1, end);
        saidThat(depth);
    }

    static void underBar(int depth) {
        sb.append("_".repeat(4).repeat(Math.max(0, depth)));
    }

    static void saidThat(int depth) {
        underBar(depth);
        sb.append("라고 답변하였지.").append("\n");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        sb.append("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.").append("\n");
        chatBot(0, n);
        System.out.print(sb);
    }

}
