package org.example.absHeap;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> absQueue = new PriorityQueue<>((a1,a2) -> {
            int num1 = Math.abs(a1);
            int num2 = Math.abs(a2);

            if(num1==num2) return a1>a2?1:-1;
            return num1-num2;
        });
        int N = Integer.parseInt(br.readLine());

        for(int i=0;i<N;i++){
            int num = Integer.parseInt(br.readLine());
            if(num == 0){
                if(absQueue.isEmpty()) System.out.println("0");
                else System.out.println(absQueue.poll());
            }else{
                absQueue.add(num);
            }
        }
    }
}
