package 기능개발;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();

        Queue<Module> que = new LinkedList<>();
        for(int i = 0; i<progresses.length; i++) {
            que.add(new Module(i, progresses[i], speeds[i]));
        }

        while(!que.isEmpty()) {
            int cnt = 0;

            List<Module> modules = new ArrayList<>();
            while(!que.isEmpty()) {
                modules.add(que.poll());
            }
            for(Module module : modules) {
                int index = module.index;
                int progress = module.progress;
                int speed = module.speed;
                que.add(new Module(index, progress + speed, speed));
            }

            while(!que.isEmpty() && que.peek().progress >= 100) {
                cnt++;
                que.poll();
            }
            if(cnt > 0) {
                list.add(cnt);
            }
        }

        int[] answer = new int[list.size()];
        for(int i = 0; i<list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }

    static class Module {

        int index, progress, speed;

        Module(int index, int progress, int speed) {
            this.index = index;
            this.progress = progress;
            this.speed = speed;
        }

    }

}