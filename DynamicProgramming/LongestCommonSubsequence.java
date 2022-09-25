class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int map[][] = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 1; i < text1.length() + 1; ++i) {
            for (int k = 1; k < text2.length() + 1; ++k) {
                if (text1.charAt(i - 1) == text2.charAt(k - 1))
                    map[i][k] = map[i - 1][k - 1] + 1;
                else
                    map[i][k] = Math.max(map[i][k - 1], map[i - 1][k]);
            }
        }
        return map[text1.length()][text2.length()];
    }
}
