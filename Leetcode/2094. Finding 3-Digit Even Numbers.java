class Solution {
    private int concatNums(int digit1, int digit2, int digit3) {
        return digit1 * 100 + digit2 * 10 + digit3;
    }
    
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> evenNumsSet = new HashSet<>();
        
        for(int i = 0; i < digits.length; ++i) {
            if(digits[i] == 0) {
                continue;
            }

            for(int j = 0; j < digits.length; ++j) {
                if(j == i) {
                    continue;
                }

                for(int k = 0; k < digits.length; ++k) {
                    if(k == j || k == i || digits[k] % 2 == 1) {
                        continue;
                    }

                    evenNumsSet.add(concatNums(digits[i], digits[j], digits[k]));
                }
            }
        }
        return evenNumsSet.stream()
                          .mapToInt(Integer::intValue)
                          .sorted()
                          .toArray();        
    }
}
