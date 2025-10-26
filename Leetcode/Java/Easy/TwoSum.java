import java.util.HashMap;

public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
            HashMap<Integer,Integer> map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                int complement = target - nums[i];
                if (map.containsKey(complement)) {
                    return new int[]{map.get(complement),i};
                }else{
                    map.put(nums[i], i);
                }
            }
            return new int[]{};
        }

        public static int[] twoSum2(int[] nums, int target) {
            for (int i = 0; i < nums.length; i++) {
                for (int j = 0; j < nums.length; j++) {
                    if (nums[i]+nums[j] == target) {
                        return new int[]{i,j};
                    }
                }
            }
            return new int[]{};
        }
    
    public static void main(String[] args) {
        int[] nums = {2,7,11,15};
        int[] temp = twoSum(nums,9);
        System.out.println(temp[0]+","+temp[1]);
    }
}
