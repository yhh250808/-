#include<iostream>
using namespace std;

int findmcm(int a, int b)//找到a和b的最小公倍数（改用辗转相除法）
{
	int mul = a*b;
	if (b > a){
		b ^= a; a ^= b; b ^= a;
	}
	int temp = 0;
	while (b != 0){
		temp = a%b;
		a = b;
		b = temp;
	}
	return mul / a;
}

int main()
{
	int n=0, m=0, k=0;
	int mcm = 1, sum = 0;
	int a[50];
	while (cin >> m >> n&&n&&m){
		sum = 0; mcm = 1;
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)
			mcm = findmcm(mcm, a[i]);
		for (int i = 0; i < n; i++)sum += (mcm / a[i]);
		if (m%sum==0){
			k = m / sum;
			for (int i = 0; i < n - 1; i++)cout << k*mcm / a[i] << ' ';
			cout << k*mcm / a[n - 1] << endl;
		}
		else{
			cout << "Can't Solve" << endl;
		}
	}
	return 0;
}
