package org.example.ironpipe;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String pipe = br.readLine();
        int num=0;
        int answer=0;
        for(int i=0;i<pipe.length();i++){
            char state = pipe.charAt(i);
            if(state==')'){
                num--;
                if(pipe.charAt(i-1)=='('){
                    answer+=num;
                }else {
                    answer++;
                }
            }else{
                num++;
            }
        }
        System.out.println(answer);
    }
}
