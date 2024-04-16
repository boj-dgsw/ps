package org.example.gitar;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        List<Integer> volume = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            volume.add(i,Integer.parseInt(st.nextToken()));
        }
        int [] state = new int[M+1];
        if(S+volume.get(0)>M && S-volume.get(0)<0){
            System.out.println(-1);
        }else{
            if(S+volume.get(0)<=M) state[S+volume.get(0)]=1;
            if(S-volume.get(0)>=0) state[S-volume.get(0)]=1;
            for(int i=1;i<N;i++){
                List<Integer> list = new ArrayList<>();
                for(int j=0;j<=M;j++){
                    if(state[j]==i){
                        if (j + volume.get(i) <= M) {
                            list.add(j + volume.get(i));
                        }
                        if (j - volume.get(i) >= 0) {
                            list.add(j - volume.get(i));
                        }
                    }
                }
                if(list.size()==0){
                    System.out.println(-1);
                    return;
                }else{
                    for(int num : list) state[num] = i+1;
                }
            }
            for(int i=M;i>=0;i--){
                if(state[i]==N){
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}
