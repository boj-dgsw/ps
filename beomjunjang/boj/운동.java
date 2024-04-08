package org.example.PE;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        if(m+T>M) System.out.println("-1");
        else{
            int now=m,time=0;
            while (N!=0){
                if(now+T<=M){
                    N--;
                    now+=T;
                }else{
                    if(now-R<m){
                        now=m;
                    }else{
                        now-=R;
                    }
                }
                time++;
            }
            System.out.println(time);
        }

    }
}
