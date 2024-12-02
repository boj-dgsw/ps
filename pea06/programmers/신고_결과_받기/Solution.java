package 신고_결과_받기;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {

    public int[] solution(String[] id_list, String[] report, int k) {
        Map<String, Integer> reporteeCountMap = new HashMap<>();
        Map<String, Set<String>> reporteeIdMap = new HashMap<>();
        Map<String, Set<String>> reportIdMap = new HashMap<>();

        for(int i = 0; i < id_list.length; i++) {
            reporteeIdMap.putIfAbsent(id_list[i], new HashSet<>());
            reporteeCountMap.putIfAbsent(id_list[i], 0);
            reportIdMap.putIfAbsent(id_list[i], new HashSet<>());
        }

        for (String s : report) {
            String reporter = s.split(" ")[0];
            String reportee = s.split(" ")[1];
            reportIdMap.putIfAbsent(reporter, new HashSet<>());
            reportIdMap.get(reporter).add(reportee);
            if(!reporteeIdMap.get(reportee).contains(reporter)) {
                reporteeIdMap.get(reportee).add(reporter);
                reporteeCountMap.put(reportee, reporteeCountMap.get(reportee) + 1);
            }


        }
        int[] answer = new int[id_list.length];
        for(int i = 0; i < id_list.length; i++) {
            for (String s : reportIdMap.get(id_list[i])) {
                if (reporteeCountMap.get(s) >= k) {
                    answer[i]++;
                }
            }
        }

        return answer;
    }
}