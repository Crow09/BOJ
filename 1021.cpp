#include <bits/stdc++.h>
using namespace std;

int N, M, popNum, repeat, idx, dequeSize;
deque<int> rotationQueue;

void frontPopMethod() {
    while (true) {
        if (rotationQueue.front() == popNum) {
            rotationQueue.pop_front();
            break;
        }
        int tmp = rotationQueue.front();
        rotationQueue.pop_front();
        rotationQueue.push_back(tmp);
        repeat++;
    }
}

void backPopMethod() {
    while (true) {
        if (rotationQueue.front() == popNum) {
            rotationQueue.pop_front();
            break;
        }
        int tmp = rotationQueue.back();
        rotationQueue.pop_back();
        rotationQueue.push_front(tmp);
        repeat++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        rotationQueue.push_back(i);
    while (M--) {
        cin >> popNum;
        dequeSize = rotationQueue.size();
        for (int i = 0; i < dequeSize; i++)
            if (rotationQueue[i] == popNum) {
                idx = i;
                break;
            }
        if (dequeSize/2 < idx) backPopMethod();
        else                   frontPopMethod();
    }
    cout << repeat << '\n'; 
    return 0;
}