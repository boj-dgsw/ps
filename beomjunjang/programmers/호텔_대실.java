import java.util.*;

class Solution {
//    class Visitor implements Comparable<Visitor> {
//        int startTime;
//        int endTime;
//        Visitor(int start, int end){
//            this.startTime=start;
//            this.endTime = end;
//        }
//        
//        @Override    
//        public int compareTo(Visitor visit) {        
//             if (visit.startTime < startTime) {            
//                 return 1;        
//             } else if (visit.startTime > startTime) {            
//                 return -1;        }        
//             return 0;    
//         }
//    }
    public int solution(String[][] book_time) {
        List<Integer> startTimeList = new ArrayList<>();
        List<Integer> endTimeList = new ArrayList<>();
        int answer = 0;
        for(int i=0;i<book_time.length;i++){
            int start=0,end=0;
            StringTokenizer st = new StringTokenizer(book_time[i][0],":");
            String hour = st.nextToken();
            String minute = st.nextToken();
            if(hour.charAt(0)!='0'){
                start+=Integer.parseInt(hour)*60;
            }else{
                start+=Character.getNumericValue(hour.charAt(1))*60;
            }
            if(minute.charAt(0)!='0'){
                start+=Integer.parseInt(minute);
            }else{
                start+=Character.getNumericValue(minute.charAt(1));
            }
            st = new StringTokenizer(book_time[i][1],":");
            hour = st.nextToken();
            minute = st.nextToken();
            if(hour.charAt(0)!='0'){
                end+=Integer.parseInt(hour)*60;
            }else{
                end+=Character.getNumericValue(hour.charAt(1))*60;
            }
            if(minute.charAt(0)!='0'){
                end+=Integer.parseInt(minute);
            }else{
                end+=Character.getNumericValue(minute.charAt(1));
            }
            startTimeList.add(start);
            endTimeList.add(end);
        }
        startTimeList.sort(Comparator.naturalOrder());
        endTimeList.sort(Comparator.naturalOrder());
        int accSum=0, j=0;
        for(int i=0;i<startTimeList.size();i++){
            accSum++;
            int sTime = startTimeList.get(i);
            while(true){
                int etime=endTimeList.get(j);
                if(etime+10<=sTime){
                    accSum--;
                    j++;
                }else{
                    break;
                }
            }
            if(accSum>answer) answer=accSum;
        }
        return answer;
    }
}
