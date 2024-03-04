#include<iostream>
#include<vector>
using namespace std;
float op(float a, float b, int x) {
	switch (x) {
	case 1:return a + b; break;
	case 2:return a - b; break;
	case 3:return a * b; break;
	case 4:return a / b; break;
	}
}
 vector<vector<float>> An2(vector<float>nums) {
	int m = nums.size();
	vector<vector<float>>  An2(m * (m - 1));
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int n = 0; n < m * (m - 1); n++) {
				An2[n][0] = nums[i]; An2[n][1] = nums[j];
				n += 1;
				An2[n][1] = nums[i]; An2[n][0] = nums[j];
			}
		}
	}
	return An2;
}
 vector<float> delete2(vector<float>nums, float a, float b) {
	 auto iter = nums.begin();
	 while (iter != nums.end()) {
		 if (*iter == a) {
			 iter = nums.erase(iter); break;
		 }
		 else {
			 iter++;
		 }
	  }
	 auto iter1 = nums.begin();
	 while (iter1 != nums.begin()) {
		 if (*iter == b) {
			 iter1 = nums.erase(iter1); break;
		 }
		 else iter1++;
	 }
	 return nums;
 }
 int main() {
	 float a, b, c, d; cin >> a >> b >> c >> d;
	 vector<float> nums = { a,b,c,d };
	 vector<vector<float>> r1 = An2(nums);
	 int m = r1.size();
	 float R1, R2, R3;
	 for (int i = 0; i < m; i++) {
		 for (int j = 1; j <= 4; j++) {
			 R1 = op(r1[i][0], r1[i][1],j);
			 vector<float>nums1 = nums;
			 delete2(nums1, r1[i][0], r1[i][1]);
			 nums1.push_back(R1);
			 vector<vector<float>>r2 = An2(nums1);
			 for (int k = 0; k < r2.size(); k++) {
				 for (int l = 1; l <= 4; l++) {
					 R2 = op(r2[k][0], r2[k][1], l);
					 vector<float>nums2 = nums1;
					 delete2(nums2, r2[k][0], r2[k][1]);
					 nums2.push_back(R2);
					 for (int p = 1; p <= 4; p++) {
						 if (op(nums2[0], nums2[1], p) == 24) cout << "yes"; return 0;
						 if (op(nums2[1], nums2[0], p) == 24) cout << "yes"; return 0;
					 }
				 }
			 }

		 }
	 }
	 cout << "no"; return 0;
 }
