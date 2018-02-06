#include<iostream>
using namespace std;

int findmcm(int a, int b)//�ҵ�a��b����С������������������Լ��������a*b��������
{
	int mul = a*b;
	while (true){
		if (a > b)a = a - b;
		else if (a == b) return mul / a;
		else b = b - a;
	}
}

int findmcm(int n, int *a)//�ҵ�����Ԫ�ص���С������
{
	if (n == 1)return a[0];
	if (n == 2)return findmcm(a[0], a[1]);
	int mcm = findmcm(a[0], a[1]);
	for (int i = 2; i < n; i++)
	{
		mcm = findmcm(mcm, a[i]);
	}
	return mcm;
}

int main()
{
	int n=0, m=0, k=0;
	int mcm = 0, sum = 0;
	int a[50] = { 0 };
	cin >> m >> n;
	while (n&&m){
		sum = 0;
		for (int i = 0; i < n; i++)cin >> a[i];
		mcm = findmcm(n, a);//mcmΪ��С������
		for (int i = 0; i < n; i++)sum += (mcm / a[i]);
		if (m%sum){
			cout << "Can't Solve" << endl;
		}
		else{
			k = m*(mcm - sum) / sum;
			m += k;
			for (int i = 0; i < n - 1; i++)cout << m / a[i] << ' ';
			cout << m / a[n - 1] << endl;
		}
		cin >> m >> n;
	}
	system("pause");
	return 0;
}