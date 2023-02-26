#pragma once
#include <iostream>

template<class N>
class FenwickTree {

    long long n;
    N* A;
    N* T;

    void build() {
        for (long long i = 0; i < n; i++) {
            modify(i, A[i]);
        }
    }

public:

    FenwickTree(N* _A, long long _n) {
        n = _n;
        A = _A;
        T = new N[n]{ N(0) };

        build();
    }

    long long size() const {
        return n;
    }

    void modify(long long i, N addendum) {
        while (i < n) {
            T[i] += addendum;
            i |= i + 1;
        }
    }

    void set(long long i, N x) {
        N d = x - A[i];
        A[i] = x;
        modify(i, d);
    }

    long long f(long long i) {
        return i & (i + 1);
    }

    N sum(long long i) {
        N result = N(0);

        while (i >= 0) {
            result += T[i];
            i = f(i) - 1;
        }

        return result;
    }

    N sum(long long i, long long j) {
        return sum(j) - sum(i - 1);
    }

    ~FenwickTree() {
        delete[] T;
        A = nullptr;
    }

    N& operator[](long long i) {
        return T[i];
    }

    N operator[](long long i) const {
        return T[i];
    }

    friend std::ostream& operator<<(std::ostream& out, const FenwickTree<N>& ft) {
        for (long long i = 0; i < ft.size(); i++) {
            out << ft[i] << ' ';
        }

        return out;
    }
};