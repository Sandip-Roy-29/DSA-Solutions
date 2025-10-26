public class RemoveDuplicatesFromSortedArray {
    public static int removeDuplicates(int[] nums) {
        int pos = 0;

        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] != nums[i+1]) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        nums[pos] = nums[nums.length - 1];
        pos++;

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
        return pos;
    }

    public static int removeDuplicates2(int[] nums) {
        int write = 0;
        int read = 1;

        while (read < nums.length) {
            if (nums[read] != nums[write]) {
                nums[++write] = nums[read];
            }
            read++;
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i]+" ");
        }
        System.out.println();
        return write+1;
    }
    public static void main(String[] args) {
        int[] nums = {1,1,2,2,3,3,4,4,5,5};
        System.out.println(removeDuplicates(nums));
        System.out.println(removeDuplicates2(nums));
    }
}
