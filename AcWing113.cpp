// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
	vector<int> specialSort(int N) {
		int len, l, r, mid;
		vector<int> a;
		a.insert(a.begin(), 1); r++;
		for(int i=2; i<=N; i++){
			l=0; r=i-1;
			while(l<r){
				mid = (l+r)>>1;
				if(compare(i, a[mid])) r = mid;
				else l = mid+1;
			}
			a.insert(a.begin()+l, i);
		}
		return a;
	}
};
