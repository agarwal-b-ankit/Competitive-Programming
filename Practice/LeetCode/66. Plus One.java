class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for(int i=digits.length-1;i>=0;i--){
            int temp = (digits[i]+carry)/10;
            digits[i]=(digits[i]+carry)%10;
            carry = temp;
        }
        if(carry ==0 ) return digits;
        int[] newDigits = new int[digits.length+1];
        newDigits[0]=carry;
        for(int i=0;i<digits.length;i++)
            newDigits[i+1]=digits[i];
        return newDigits;
    }
}