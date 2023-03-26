#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

template <typename T>
class UnionFindSet {
private:
    unordered_map<T, T> _parent{};
public:
    UnionFindSet(void) = default;
    UnionFindSet(UnionFindSet<T>& ufs) = default;
    int merge(T x, T y);
    bool find(T x, T y);
    T findRoot(T x);
};


template <typename T>
int UnionFindSet<T>::merge(T x, T y) {
    if (_parent.count(x) == 0 and _parent.count(y) != 0) {
        _parent[x] = _parent[y];
    } else if (_parent.count(x) != 0 and _parent.count(y) == 0) {
        _parent[y] = _parent[x];
    } else if (_parent.count(x) == 0 and _parent.count(y) == 0) {
        _parent[x] = x;
        _parent[y] = y;
    } else {
        if (not find(x, y)) {
            _parent[findRoot(y)] = x;
        }
    }
out:
    return 0;
}

template <typename T>
bool UnionFindSet<T>::find(T x, T y) {
    if (_parent.count(x) == 0 or _parent.count(y) == 0)
        return false;

    return findRoot(x) == findRoot(y);
}

template <typename T>
T UnionFindSet<T>::findRoot(T x) {
    T newParentX;
    T xx = x;
    vector<T> temp_xx_{};
    while (1) {
        temp_xx_.push_back(xx);
        if (xx == _parent[xx])
            break;
        xx = _parent[xx];
    }
    newParentX = *min_element(temp_xx_.begin(), temp_xx_.end());
    for (auto const& key: temp_xx_) {
        _parent[key] = newParentX;
    }
    return newParentX;
}

int main()
{
    UnionFindSet<int> ufs;
    ufs.merge(1, 2);
    ufs.merge(1, 3);
    ufs.merge(1, 4);

    ufs.merge(5, 6);
    ufs.merge(5, 7);

    cout << ufs.merge(1, 7) << endl;
    cout << boolalpha << ufs.find(1, 5) << endl;
    return 0;
}