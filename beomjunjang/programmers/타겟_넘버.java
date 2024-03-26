class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        sum(numbers,0,0,target);
        return answer;
    }
    void sum(int[] array, int index, int nowNum, int target){
        if(index==array.length){
            if(target==nowNum) answer++;
            return;
        } 
        
        sum(array,index+1,nowNum+array[index],target);
        sum(array,index+1,nowNum+array[index]*-1,target);
    }
}
