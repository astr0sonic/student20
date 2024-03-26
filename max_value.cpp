#include "max_value.h"
using namespace std;

double calculateMaxValue(double* nums, int n) {
    double dig[2],var[8]{};
//    vector<double> var(8, 0), pos[2];
//    vector<char> znak{'+', '-', '*', '/'}, ans[2];
    for (int i = 0; i < n; i++) {
        if (!i) {
            dig[0] = nums[i];
            dig[1] = nums[i];
        } else {
            for (int j = 0; j < 2; j++) {
                var[j * 4] = dig[j] + nums[i];
                var[j * 4 + 1] = dig[j] - nums[i];
                var[j * 4 + 2] = dig[j] * nums[i];
                if (nums[i]) {
                    var[j * 4 + 3] = dig[j] / nums[i];
                } else {
                    var[j * 4 + 3] = 0;
                }
            }
//            char znak1, znak2;
//            int last1, last2;
//            for (int j = 0; j < 8; j++) {
//                if (var[j] <= dig[0]) {
//                    last1 = j / 4;
//                    znak1 = znak[j % 4];
//                    dig[0] = var[j];
//                }
//                if (var[j] >= dig[1]) {
//                    last2 = j / 4;
//                    znak2 = znak[j % 4];
//                    dig[1] = var[j];
//                }
//            }
//            ans[0].push_back(znak1);
//            ans[1].push_back(znak2);
//            pos[0].push_back(last1);
//            pos[1].push_back(last2);
        }
    }
//    int now = 1;
//    deque<char> ret;
//    for (int i = n - 2; i > 0; i--) {
//        ret.push_front(ans[now][i]);
//        now = pos[now][i - 1];
//    }
//    ret.push_front(ans[now][0]);
//    cout << ret.size() << endl;
//    for (int i = 0; i < n; i++) {
//        if (nums[i] < 0) {
//            cout << '(' << nums[i] << ')';
//        } else {
//            cout << nums[i];
//        }
//        if (i != n - 1) {
//            cout << ret[i];
//        }
//    }
//    cout << "=" << dig[1];
    return dig[0];
}
