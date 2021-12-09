#include "common.h"
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> ar, int ts) {
	// Write your code here.
	vector<vector<int>> res;
	auto size = ar.size();
	//unordered_map<string, vector< int> > resStr;
	unordered_map<int, vector<pair<int, int>>> map;
	if (size >= 4)
	{
		sort(ar.begin(), ar.end());

		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				auto sum = ar[i] + ar[j];
				auto rem = ts - sum;
				auto itr = map.find(rem);
				if (ar[i] == -1 && ar[j] == 4) {
					rem = ts - sum;
				}
				if (ar[i] == 6 && ar[j] == 7) {
					rem = ts - sum;
				}
				if (itr != map.end())
				{
					auto& v = itr->second;//vector<pair<int, int>>
					for_each(v.begin(), v.end(), [&](auto& pr)
						{
							vector<int> r{ ar[i], ar[j], pr.first, pr.second };
							sort(r.begin(), r.end());

							bool dup = false;
							for (int k = 1; k < 4; ++k) {
								if (r[k - 1] == r[k]) {
									dup = true;
									break;
								}
							}
							if (!dup)
							{
								int found = 0;
								for (auto& re : res) {
									found = 0;
									for (int m = 0; m < 4; ++m) {
										if (re[m] == r[m]) {
											++found;
										}
									}
									if (found==4)
										break;
								}
								if (found != 4)
									res.push_back(r);
							}
						});
				}
				auto itr1 = map.find(sum);
				if (itr1 != map.end())
				{
					auto& v1 = itr1->second;//vector<pair<int, int>>
					v1.push_back(pair<int, int>(ar[i], ar[j]));
				}
				else
				{
					vector<pair<int, int>> v2;
					v2.push_back(pair<int, int>(ar[i], ar[j]));
					map[sum] = v2;
				}
			}
		}
	}

	return res;
}
/*
* [
  [7, 6, 4, -1],
  [7, 6, 1, 2]
]
*/
void FindFourSumProblem() {
	FUNC_START;
	vector<int> ar{ 7, 6, 4, -1, 1, 2 };
	int ts = 16;
	vector<vector<int>> res = fourNumberSum(ar, ts);
	for (auto &v : res)
	{
		cout << "\n res = ";
		for (auto& x : v)
			cout << "\t" << x;
	}
	FUNC_END;
}