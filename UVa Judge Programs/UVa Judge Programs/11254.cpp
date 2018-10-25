#include <iostream>

using namespace std;

int main () {
    long long num;
    while (cin >> num && num != -1) {
        //cout << num << '\n';
        bool isFound = false;
        // for all numbers until the given num, strting with 1 and increasing
        // | = i[0]
        // v
        // |-----------------------------------|
        //
        //  | = i[1]
        //  v
        // |-----------------------------------|
        //
        // ...
        //                                     | = i[num]
        //                                     v
        // |-----------------------------------|
        //
        long long sum = 2;
        while (sum < num) {
            sum = sum + sum;
        }
        if (sum == num)
            isFound = true;
        long long high, low = high = num;
        long long maxHigh = (num / 2);
        for (int i = 1; i <= maxHigh && !isFound; i++) {
            //// prlong long out the instance
            //cout << "num = " << i << '\n';
            //    for all numbers less than or equal to i
            
            //      | = i
            //      v
            // |-----------------------------------|
            //      ^
            //      | = j[0] 
            //
            //     | = i
            //     v
            // |-----------------------------------|
            //      ^
            //      | = j[1]
            //
            //
            // ...
            //    | = i
            //    v
            // |-----------------------------------|
            //                                     ^
            //                                     | = j[num]
            //
            for (int j = i; j <= maxHigh + 1 && !isFound; j++) {
                sum = (((j * (j + 1)) - (i * (i - 1))) / 2);
                if (sum == num && i != j) {
                    isFound = true;
                    high = j;
                    low = i;
                }

            }
        }
        if (isFound && low != high) {
            cout << num << " = " << low << " + ... + " << high << '\n';

        }

    }
}