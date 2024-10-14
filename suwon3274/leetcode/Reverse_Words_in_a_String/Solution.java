import java.util.*;

class Solution {
    public String reverseWords(String s) {
        StringTokenizer st = new StringTokenizer(s, " ");
        List<String> wordList = new ArrayList();
        while(st.hasMoreTokens()) {
            wordList.add(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        for(int i = wordList.size() - 1; i>=0; i--) {
            sb.append(wordList.get(i));
            if(i != 0) {
                sb.append(" ");
            }
        }
        return sb.toString();
    }
}
