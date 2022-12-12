int getDifference(int B, int X, int Y) {
    int finalVal = 0;
    int carry = 0;
    int power = 1;

    while (X > 0) {
        int n1 = X % 10;
        int n2 = Y % 10;
        // Remove last digits from X and Y
        X = X / 10;
        Y = Y / 10;
        int temp = n1 - n2 + carry;
        if (temp < 0) {
            // Carry = -1 will act as borrow
            carry = -1;
            temp += B;
        } else
            carry = 0;
        finalVal += temp * power;
        power = power * 10;
    }
    return finalVal;
}