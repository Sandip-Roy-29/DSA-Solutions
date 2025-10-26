import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class PlusOne {
    
    public static List<Integer> plusOne(List<Integer> digits) {
        int num = 0;
        List<Integer> temp = new ArrayList<>();

        // Convert array of digits into an integer
        for (int i = 0; i < digits.size(); i++) {
            num = num * 10 + digits.get(i);
        }

        // Add one
        num++;

        // Handle zero case
        if (num == 0) {
            temp.add(num);
            return temp;
        }

        // Extract digits (in reverse order)
        while (num > 0) {
            temp.add(num % 10);
            num = num / 10;
        }

        // Reverse list to correct order
        Collections.reverse(temp);

        return temp;
    }

    public static List<Integer> plusOne2(List<Integer> digits) {
        for (int i = digits.size(); i > 0; i--) {
            if (digits.get(i-1)< 9) {
                digits.set(i - 1, digits.get(i - 1) + 1);
                return digits;
            }
            digits.set(i-1,0);
        }
        digits.add(0, 1);

        return digits;
    }
    public static void main(String[] args) {
        List<Integer> digits = Arrays.asList(4, 3, 2, 1);
        List<Integer> result = plusOne(digits);

        for (int d : result) {
            System.out.print(d);
        }

    }
}
