#include<bits/stdc++.h>
using namespace std;

int arr[100];
int m[100][100];
int s[100][100];

void MATRIX_CHAIN_ORDER(int n){
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) { // chain length
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void PRINT_OPTIMAL_PARENS(int s[][100], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
        PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n; // number of dimensions (so number of matrices = n - 1)

    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; // dimension array
    }

    MATRIX_CHAIN_ORDER(n);

    PRINT_OPTIMAL_PARENS(s, 1, n-1); // FIX: use n - 1 as upper matrix index
    cout << endl;


    return 0;
}
