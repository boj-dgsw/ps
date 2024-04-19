package org.example.balloonPop;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        Deque<Integer> deque = new ArrayDeque<>();
        int [] balloon = new int[N+1];
        for(int i=1;i<=N;i++){
            balloon[i] = Integer.parseInt(st.nextToken());
            deque.addLast(i);
        }
        for(int i=1;i<N;i++){
            int index = deque.pollFirst();
            System.out.print(index+" ");
            int move = balloon[index];
            if(move < 0){
                while(move!=0) {
                    move++;
                    deque.addFirst(deque.pollLast());
                }
            }else{
                while (move!=1){
                    move--;
                    deque.addLast(deque.pollFirst());
                }
            }
        }
        System.out.println(deque.pollFirst());
    }
}
