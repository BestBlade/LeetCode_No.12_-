/*--------------------------------------------------------------------------------------------------------------|
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。															|
																												|
字符          数值																								|
I             1																									|
V             5																									|
X             10																								|
L             50																								|
C             100																								|
D             500																								|
M             1000																								|
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。	|
																												|
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左	|
边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：	|
																												|
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。																|
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 															|
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。														|
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。													|
																												|
示例 1:																											|
																												|
输入: 3																											|
输出: "III"																										|
示例 2:																											|
																												|
输入: 4																											|
输出: "IV"																										|
示例 3:																											|
																												|
输入: 9																											|
输出: "IX"																										|
示例 4:																											|
																												|
输入: 58																										|
输出: "LVIII"																									|
解释: L = 50, V = 5, III = 3.																					|
示例 5:																											|
																												|
输入: 1994																										|
输出: "MCMXCIV"																									|
解释: M = 1000, CM = 900, XC = 90, IV = 4.																		|
																												|
来源：力扣（LeetCode）																							|
链接：https://leetcode-cn.com/problems/integer-to-roman															|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。											|
---------------------------------------------------------------------------------------------------------------*/

/*	if-else法
*	执行用时：20 ms, 在所有 C++ 提交中击败了44.47%的用户
*	内存消耗：6.2 MB, 在所有 C++ 提交中击败了71.76%的用户
*/
#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) 
{
	string result;

	int p[] = { 0,0,0,0 };

	int p_size = sizeof(p) / sizeof(p[0]);

	for (int j = p_size - 1; j >= 0; j--)
	{
		p[j] = num % 10;
		num /= 10;
	}


	if (p[0] <= 3 && p[0] >= 1)
	{
		result = result + 'M';
		p[0]--;
	}

	if (p[1] == 9)
	{
		result = result + "CM";
	}
	else if (p[1] < 9 && p[1] >= 5)
	{
		int k = p[1] - 5;
		result = result + 'D';
		while (k)
		{
			result = result + 'C';
			k--;
		}
	}
	else if (p[1] == 4)
	{
		result = result + "CD";
	}
	else if (p[1] < 4)
	{
		int k = p[1];
		while (k)
		{
			result = result + 'C';
			k--;
		}
	}

	if (p[2] == 9)
	{
		result = result + "XC";
	}
	else if (p[2] < 9 && p[2] >= 5)
	{
		int k = p[2] - 5;
		result = result + 'L';
		while (k)
		{
			result = result + 'X';
			k--;
		}
	}
	else if (p[2] == 4)
	{
		result = result + "XL";
	}
	else if (p[2] < 4)
	{
		int k = p[2];
		while (k)
		{
			result = result + 'X';
			k--;
		}
	}

	if (p[3] == 9)
	{
		result = result + "IX";
	}
	else if (p[3] < 9 && p[3] >= 5)
	{
		int k = p[3] - 5;
		result = result + 'V';
		while (k)
		{
			result = result + 'I';
			k--;
		}
	}
	else if (p[3] == 4)
	{
		result = result + "IV";
	}
	else if (p[3] < 4)
	{
		int k = p[3];
		while (k)
		{
			result = result + 'I';
			k--;
		}
	}

	return result;
}

int main()
{
	int num = 901;

	//int p[] = { 0,0,0,0 };
	//for (int j = 3; j >= 0; j--)
	//{
	//	p[j] = num % 10;
	//	num /= 10;
	//}

	cout << intToRoman(num) << endl;
}