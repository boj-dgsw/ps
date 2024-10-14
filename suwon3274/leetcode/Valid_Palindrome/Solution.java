class Solution {
    public boolean isPalindrome(String s) {
        s = export(s);
        int l = 0, r = s.length() - 1;
        for(; l<s.length()/2; l++, r--) {
            if(s.charAt(l) != s.charAt(r)) {
                return false;
            }
        }
        return true;
    }

    private String export(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(isAlphabetOrNumber(c)) {
                if(c >= 'A' && c <= 'Z') {
                    c += 'a' - 'A';
                }
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private boolean isAlphabetOrNumber(char c) {
        if(c >= '0' && c <= '9') {
            return true;
        }
        if(c >= 'A' && c <= 'Z') {
            return true;
        }
        if(c >= 'a' && c <= 'z') {
            return true;
        }
        return false;
    }
}
