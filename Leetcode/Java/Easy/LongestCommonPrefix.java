public class LongestCommonPrefix {
    public static String longestCommonPrefix(String[] strs) {
        String prefix = strs[0];
        for (int i = 0; i < strs.length-1; i++) {
            String s1 = prefix;
            String s2 = strs[i+1];
            int j = 0;

           while (j<s1.length() && j<s2.length()) {
                if (s1.charAt(j) == s2.charAt(j)) {
                    j++;
                }else{
                    break;
                }
            }          
            prefix = s1.substring(0, j);
            if (prefix.isEmpty()) {
                return "";
            }
        }
        return prefix;
    }

    public static String longestCommonPrefix2(String[] strs) {
        if(strs.length == 0) return "";
        for (int i = 0; i < strs[0].length(); i++) {
           char ch = strs[0].charAt(i);

          for (int j = 0; j < strs.length; j++) {
            if (i>=strs[j].length() || strs[j].charAt(i) != ch) {
                return strs[0].substring(0,i);
            }
          }
        }
        return strs[0];
    }

    public static String longestCommonPrefix3(String[] strs,int low,int high) {
        if(low==high) return strs[low];

        int mid = (low+high)/2;
        String left = longestCommonPrefix3(strs,low,mid);
        String right = longestCommonPrefix3(strs,mid+1,high);
        return commonPrefix(left,right);
    }
    
    public static String commonPrefix(String left,String right){
        int minLen = Math.min(left.length(), right.length());
        int i =0;
        
        while (i<minLen && left.charAt(i) == right.charAt(i)) {
            i++;
        }
        return left.substring(0,i);
        
    }

    public static String longestCommonPrefix4(String[] strs) {
        int minLen = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            minLen = Math.min(minLen, strs[i].length());
        }
        int low = 0, high = minLen;
        while (low<=high) {
            int mid = low+(high+low)/2;
            if (isCommonPrefix(strs,mid)) {
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }
        return strs[0].substring(0,(high+low)/2);
    }

    public static boolean isCommonPrefix(String strs[],int len){
        String prefix = strs[0].substring(0,len);

        for (int i = 1; i < strs.length; i++) {
            if (strs[i].substring(0,len) != prefix) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        String[] strs = {"flower","flow","flight"};
        // System.out.println(longestCommonPrefix(strs));
        // System.out.println(longestCommonPrefix2(strs));
        // System.out.println(longestCommonPrefix3(strs,0,strs.length-1));
        System.out.println(longestCommonPrefix4(strs));
    }
}
