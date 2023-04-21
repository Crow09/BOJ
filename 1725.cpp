#include <bits/stdc++.h>
#define PUSH histo.push
#define TOP histo.top()
#define NOT_EMPTY !histo.empty()
#define LL long long
using namespace std;

int main() {
    while (true) { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n;
        cin >> n;
        if (n == 0) break;
        LL result = 0;
        stack<int> histo; // 인덱스를 저장할 스택
        vector<LL> height(n + 2);
        PUSH(0); // 같은 수가 들어올 시 계산이 안되는 오류가 생기기에 오류 방지용
        for (int i = 1; i <= n + 1; i++) { // 마지막으로 들어오는 수까지 모두 계산하기 위함
            if (i <= n)
                cin >> height[i]; // n보다 작거나 같은 수라면 (n 개의 수만 입력) vector에 높이 입력 (stack에 입력된 인덱스로 접근 예정)
            while (NOT_EMPTY && height[i] < height[TOP]) { // 비어있지 않고 입력받은 값보다 현재 top이 더 크다면
                int tmpTop = TOP; // 최상단에 위치한 인덱스 복사
                histo.pop(); // 최상단 pop
                result = max((LL)height[tmpTop] * (i - TOP - 1), result); // 최상단에 위치한 높이와 그 넓이를 계산해 현재 result와 비교
            }
            PUSH(i); // 인덱스 push
            // 최상단보다 작은 값이 들어온다면 값이 더 커질 수 없기에 위와 같은 코드 작성
        }
        cout << result << '\n';
    }
    return 0;
}