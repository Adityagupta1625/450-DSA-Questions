#include <iostream>
#include <algorithm>
using namespace std;

// Approach 1:
// void merge(int A[], int l, int m, int h)
// {
// 	int j = m + 1;
// 	if (A[m] <= A[j])
// 		return;
// 	while (l <= m && j <= h)
// 	{
// 		if (A[l] <= A[j])
// 			l++;
// 		else
// 		{
// 			int value = A[j];
// 			int index = j;
// 			while (index != l)
// 			{
// 				A[index] = A[index - 1];
// 				index--;
// 			}
// 			A[l] = value;
// 			l++;
// 			j++;
// 			m++;
// 		}
// 	}
// }

// Approach 2:
// int nextgap(int gap){
// 	if(gap>0)
// 		return gap/2;
// 	return 0;
// }
// void merge(int A[],int l,int m,int h){

// 	int gap=h-l+1;
// 	for (gap=nextgap(gap);gap>0;gap=nextgap(gap))
// 	{
// 		for (int i = 0,j=i+gap; i+gap<h-l+1; i++,j++)
// 		{
// 			if(A[j]<A[i])
// 				swap(A[j],A[i]);
// 		}

// 	}

// }

void merge(int A[], int l, int m, int h)
{
	int i=l,j=m+1,k=l;
	int mx=max(A[m],A[h])+1;
	while (i <= m && j <= h && k<=h)
	{
		int e1=A[i]%mx;
		int e2=A[j]%mx;
		if (e1<=e2){
			A[k]+=e1*mx;
			i++;
			k++;
		}	
		else
		{
			A[k]+=e2*mx;
			j++;
			k++;
		}
	}
	while(i<=m){
		int e1=A[i]%mx;
		A[k]+=e1*mx;
		k++;
		i++;
	}
	while(j<=h){
		int e2=A[j]%mx;
		A[k]+=e2*mx;
		j++;
		k++;
	}
	for (int i = l; i <=h; i++)
	{
		A[i]/=mx;
	}
	
}
void mergeSort(int A[], int l, int h)
{
	if (l < h)
	{
		/* code */
		int m = l + (h - l) / 2;
		mergeSort(A, l, m);
		mergeSort(A, m + 1, h);
		merge(A, l, m, h);
	}
}
void printAay(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << A[i];
	cout << "\n";
}

/* Driver program to test above functions */
int main()
{
	int A[] = {1, 11, 3, 5, 6, 7};
	int A_size = sizeof(A) / sizeof(A[0]);

	mergeSort(A, 0, A_size - 1);

	printAay(A, A_size);
	return 0;
}