class Solution {
    public String removeDigit(String number, char digit) {
        int targetIndex = 0;
        int numLength = number.length();

        for(int i = 0; i < numLength; ++i) {
            if(number.charAt(i) == digit) {
                targetIndex = i;

                if(i < numLength-1 && number.charAt(i) < number.charAt(i + 1)) {   
                    break;
                }
            }
        }

        StringBuilder newNumber = new StringBuilder();
        for(int i = 0; i < numLength; ++i) {
            if(i != targetIndex) {
                newNumber.append(number.charAt(i));
            }
        }
        return newNumber.toString();
    }
}
