#include<bits/stdc++.h>

using namespace std;

void shuffle(vector<int> &vec) {
    srand(time(NULL));
    for(int i = vec.size() - 1; i >= 0; i--) {
        int randnum = rand() % (i + 1);
        swap(vec[i], vec[randnum]);
    }
}
int main() {
    vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    shuffle(vec);
    for(auto i : vec) {
        cout << i << " ";
    }
    return 0;
}
