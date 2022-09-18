class Solution {
  // attempt 1
  public String longestCommonPrefix(String[] strs) {
	        String ret = "";
	        for (int i = 0; i < strs[0].length(); ++i) {
	            for (int k = 1; k < strs.length; ++k) {
	            	if (i >= strs[k].length() || strs[0].charAt(i) != strs[k].charAt(i))
	            		return ret;
	            }
	            ret += strs[0].charAt(i);
	        }
	        return ret;
	}
  
  // attempt 2
  public String overlap(String a, String b) {
		String ret = "";
		for (int i = 0; i < a.length(); ++i) {
			if (i >= b.length() || a.charAt(i) != b.charAt(i)) {
				return ret;
			}
			ret += a.charAt(i);
		}
		return ret;
	}
	public String longestCommonPrefix(String[] strs) {
	        if (strs.length == 1)
	        	return strs[0];
	        String ret = overlap(strs[0], strs[1]);
	        for (int i = 1; i < strs.length; ++i) {
	        	ret = overlap(ret, strs[i]);
	        }
	        return ret;
	}
  
  
  //attempt 3
}
