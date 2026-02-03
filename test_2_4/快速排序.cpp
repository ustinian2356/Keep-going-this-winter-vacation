#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdlib.h>
using namespace std;
#define NUMSIZE 9
int midRank(int left, int right, int* nums)
{
	int temp = nums[left];
	while (left < right)
	{
		while (left < right && nums[right] >= temp)
		{
			right--;
		}
		nums[left] = nums[right];
		while (left < right && nums[left] <= temp)
		{
			left++;
		}
		nums[right] = nums[left];
	}
	nums[right] = temp;
	return left;
}
void FastRank(int left, int right, int* nums)
{
	if (left < right)
	{
		int mid = midRank(left, right, nums);
		FastRank(left, mid - 1, nums);
		FastRank(mid + 1, right, nums);
	}
}
int main()
{
	int nums[NUMSIZE];
	cout << "ÅÅÐòÇ°:";
	for (int i = 0;i < NUMSIZE;i++)
	{
		nums[i] = rand() % 100;
		cout << nums[i] << " ";
	}
	cout << endl;
	FastRank(0, NUMSIZE - 1, nums);
	cout << "ÅÅÐòºó:";
	for (int i = 0;i < NUMSIZE;i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}