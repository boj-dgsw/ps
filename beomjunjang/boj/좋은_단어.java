package org.example.goodword;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int answer=0;
        for(int i=0;i<N;i++){
            String word = br.readLine();
            Stack<Character> stack = new Stack<>();
            if(word.length()%2==0){
                for(int j=0;j<word.length();j++){
                    if(!stack.isEmpty() && stack.peek()==word.charAt(j)) stack.pop();
                    else stack.push(word.charAt(j));
                }
                if(stack.isEmpty()) answer++;
            }
        }
        System.out.println(answer);
    }
}
