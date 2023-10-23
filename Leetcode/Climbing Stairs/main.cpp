#include<iostream>

//暴力解
//int climbStair(int n) {
//    if (n <= 0) {
//        return 0;
//    }
//    if (n == 1) {
//        return 1;
//    }
//    else if (n == 2)
//    {
//        return 2;
//    }
//    else {
//        return climbStair(n - 1) + climbStair(n - 2);
//    }
//
//}

//动态规划


int climbStairs(int n) {
    unsigned int p = 0, q = 0, r = 1;
    for (int i = 0; i < n; i++)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

int main() {
    unsigned int n = climbStairs(100);
    std::cout << n;
    return 0;
}