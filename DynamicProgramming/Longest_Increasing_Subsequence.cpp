/* Given a list of N integers find the longest increasing subsequence in this list.

Example
If the list is [16, 3, 5, 19, 10, 14, 12, 0, 15] one possible answer is the subsequence [3, 5, 10, 12, 15], another is [3, 5, 10, 14, 15].

If the list has only one integer, for example: [14], the correct answer is [14].

One more example: [10, 8, 6, 4, 2, 0], a possible correct answer is [8].

Test cases
Your solution will be graded against a number of test cases. All test cases contain at least one integer. Half of them will have no more than 1,000 integers in the input sequence. The other half will contain sequences with up to 10,000 integers. */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> longest_increasing_subsequence(vector<int> sequence) {
    // Write your solution here
    vector<int> res;
    if (sequence.empty())
        return res;
    int N = sequence.size();
    if (N==1)
        return sequence;
    vector<int> index(sequence.size());
    vector<int> maxSubseq(sequence.size(), 1);
    int maxInd = 0;
    int maximum=0;
    for (int i=1;i<N; ++i)
    {
        int maxVal = maxSubseq[i];
        int indexx = i;
        for (int j=0;j<i;++j)
        {
            if (sequence[j] < sequence[i] and maxVal < maxSubseq[j] + 1)
            {
                maxVal =  maxSubseq[j]+1;
                indexx = j;
            }
        }
        maxSubseq[i] = maxVal;
        index[i] = indexx;
        if (maximum < maxVal)
        {
            maximum = maxVal;
            maxInd = i;
        }
    }
    cout<<"The index where the longest subsequence will end : " <<  maxInd<<endl;
    cout<<"The size of longest increasing subsequence : " <<  maximum<<endl;
    cout<<"The dp array that store Longest increasing subs at each index" <<endl;
    for (auto num: maxSubseq)
        cout<< num << " ";
    cout<<endl;
    cout<<"The backtracking array" <<endl;
    for (auto num: index)
        cout<< num << " ";
    cout<<endl;
    while (maxSubseq[maxInd] > 1)
    {
        res.push_back(sequence[maxInd]);
        maxInd = index[maxInd];
    }
    res.push_back(sequence[maxInd]);
    std::reverse(res.begin(), res.end());
    return res;
}


int main()
{
    vector <int> inp {3, 4, 1, 2, 5, 6, 9, 0, 1, 2, 3, 1};
    vector<int> res = longest_increasing_subsequence(inp);
    for (auto num: res)
        cout<< num << " ";
} 