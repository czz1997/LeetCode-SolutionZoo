class Solution {
    Map<Integer, String> map;
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return new ArrayList<>();
        }
        map = new HashMap<>();
        String[] strs = new String[]{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < strs.length; ++i) {
            map.put(i + 2, strs[i]);
        }
        List<String> ret = new ArrayList<>();
        dfs(ret, new StringBuffer(), 0, digits);
        return ret;
    }
    
    private void dfs(List<String> ret, StringBuffer sb, int index, String digits) {
        if (index == digits.length()) {
            ret.add(new String(sb));
            return;
        }
        Integer key = digits.charAt(index) - '0';
        String value = map.get(key);
        for (int i = 0; i < value.length(); ++i) {
            sb.append(value.charAt(i));
            dfs(ret, sb, index + 1, digits);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
// time complexity : faster 100% O(3^m * 4*n)
// space complexity : faster 89.41% O(m + n)
