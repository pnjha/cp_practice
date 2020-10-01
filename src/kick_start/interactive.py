import sys
def solve():
    
    t = int(input())
    
    while t > 0:
        t = t-1
        a,b = input().split()
        a = int(a) + 1
        b = int(b)
        n = input()
        
        while True:

            mid = int((a+b)/2)
            print(mid)
            sys.stdout.flush()
            res = input()
            if res == "CORRECT" or res == "WRONG_ANSWER":
                break
            elif res == "TOO_SMALL":
                a = mid+1
            elif res == "TOO_BIG":
                b = mid-1
                
        
solve()


# C++:

# #include <iostream>
# #include <string>

# int main() {
#   int num_test_cases;
#   std::cin >> num_test_cases;
#   for (int i = 0; i < num_test_cases; ++i) {
#     int lo, hi;
#     std::cin >> lo >> hi;
#     int num_tries;
#     std::cin >> num_tries;
#     int head = lo + 1, tail = hi;
#     while (true) {
#       int m = (head + tail) / 2;
#       std::cout << m << std::endl;
#       std::string s;
#       std::cin >> s;
#       if (s == "CORRECT") break;
#       if (s == "TOO_SMALL")
#         head = m + 1;
#       else
#         tail = m - 1;
#     }
#   }
#   return 0;
# }

# C:

# #include <stdio.h>
# #include <string.h>

# int main() {
#   int T; scanf("%d", &T);

#   for (int id = 1; id <= T; ++id) {
#     int A, B, N, done = 0;
#     scanf("%d %d %d", &A, &B, &N);
#     for (++A; !done;) {
#       int mid = A + B >> 1;
#       char result[32];
#       printf("%d\n", mid);
#       fflush(stdout);
#       scanf("%s", result);
#       if (!strcmp(result, "CORRECT")) done = 1;
#       else if (!strcmp(result, "TOO_SMALL")) A = mid + 1;
#       else B = mid - 1;
#     }
#   }
#   return 0;
# }



