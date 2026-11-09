#include <bits/stdc++.h>
using namespace std;
int main() {
	default_random_engine e;
	uniform_int_distribution<int> v(1, 2000000);
	uniform_int_distribution<int> u(1,1e9);
	uniform_int_distribution<int> w(1,1e5);
	e.seed(time(0));
	freopen("z9.in","w",stdout);
    int n = v(e);
	printf("%d", n);
    uniform_int_distribution<int> t(1, n);
	int m = w(e);
	printf("%d\n", m);
	for(int i = 1; i <= n; i++) printf("%d ", u(e));
    printf("\n");
    for(int i = 1; i <= m; i++) {
        printf("%d ", t(e));
    }
	return 0;
}