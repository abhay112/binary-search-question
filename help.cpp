/*Rahul had a sorted array of numbers from which he 
had to find a given number quickly. His friend by 
mistake rotated the array. Now Rahul doesn't have 
time to sort the elements again. Help him to quickly find
 the given number from the rotated array.

5
4
5
1
2
3
2
*/

#include<bits/stdc++.h> 


using namespace std;

int help_rahul(int a[],int n , int k) {
	int s = 0;
	int e = n-1;
	//6 7 8 9 10 11 1 2 3 4 5
	// 4 5 1 2 3 	
	while(s<=e){
		int mid = (s+e)/2;
		if(a[mid] == k)
			return mid;
		else if(a[s] <= a[mid]){
			if(k >= a[s] && k <= a[mid]){
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}
		}
		else{
			if(k >= a[mid] && k <= a[e]){
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
	}
	return -1;

}
int main() {
	int n; cin >> n;
	int a[100000];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int k; cin >> k;
	cout << help_rahul(a,n,k);
}
