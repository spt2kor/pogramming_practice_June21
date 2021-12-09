#include "common.h"
//==============================================
/*void shuffle(vector<int>& nums, int curr, vector<int> res)
{
	int size = nums.size();
	for(int )
}
*/
int FindLeader(vector<int>& opNum)
{
	cout << "\ncurrentlist of leader candidate: \t";
	if (!opNum.empty())
	{
		int maxIndex = 0;
		int count = 0;
		for (int i = 0; i < opNum.size(); ++i)
		{
			cout << "\t" << opNum[i];
			if (opNum[i] == opNum[maxIndex])
			{
				++count;
			}
			else {
				--count;
				if (count <= 0) {
					maxIndex = i;
					count = 1;
				}
			}
		}
		cout << "\n";
		return opNum[maxIndex];
	}
	return -1;
}
//--------------
void printSeq(vector<vector<int>> &matrix, int max)
{
	int size = matrix.size();
	vector<int> validList;

	for (int i = 0; i < size; ++i)
	{
		validList.push_back(1);
	}


	for (int op = 0; op < max; ++op)
	{
		vector<int> opNum;
		for (int i = 0; i < size; ++i)
		{
			if (validList[i] == 1)
			{
				if (matrix[i].size() >= (op + 1) )
				{
					opNum.push_back( matrix[i][op]);
				}
				//else {
				//	validList[i] = 0;
				//}
			}
		}
		
		if (!opNum.empty())
		{
			int leader = FindLeader(opNum);
			cout << "\n op : " << op << "\t leader = " << leader << endl;
			for (int i = 0; i < matrix.size(); ++i)
			{
				if (validList[i] == 1)
				{
					if (matrix[i].size() >= (op + 1))
					{
						if (matrix[i][op] != leader)
							validList[i] = 0;
					}
					else {
						validList[i] = 0;
					}
				}
			}
		}
		else
			break;
	}
	//print list
	cout << "\n final no of valid list = "<<endl;
	for (int i = 0; i < size; ++i)
	{
		if (validList[i] == 1)
		{
			cout << "\n List No = " << i + 1 << "\t\t";
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				cout << "\t" << matrix[i][j];
			}
		}
	}
}
//==============================================
void runTestApp() {
	FUNC_START;
	
	vector<vector<int>> matrix{ {1,2,3}
							  , {1,2,4}
							  , {5,2,3} 
							  , {1}
							  , {1,2,4}	};
	printSeq(matrix, 5);



	FUNC_END;
}