class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int size = t.length() - p.length()+1;
        int length = p.length();
        long numP = Long.parseLong(p);
        int [] list = new int[size];
        for(int i=0;i<size;i++){
            long num = Long.parseLong(t.substring(i,i+length));
            answer+=num<=numP ? 1 : 0; 
        }
        return answer;
    }
}
