import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.atomic.AtomicBoolean;

public class Solution {

    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Process> que = new LinkedList<>();

        for(int i = 0; i<priorities.length; i++) {
            que.add(new Process(i, priorities[i]));
        }

        int cnt = 1;
        while(!que.isEmpty()) {
            AtomicBoolean canWork = new AtomicBoolean(true);
            Process process = que.poll();

            que.forEach(p -> {
                if(p.priority > process.priority) {
                    canWork.set(false);
                }
            });

            if(canWork.get()) {
                if(process.index == location) {
                    answer = cnt;
                }
                cnt++;
            } else {
                que.add(process);
            }
        }

        return answer;
    }

    static class Process {

        int index, priority;

        Process(int index, int priority) {
            this.index = index;
            this.priority = priority;
        }

    }

}
