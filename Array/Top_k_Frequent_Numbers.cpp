/* Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

In this Solution I have used an important concept called hoarse quick_select algorithm to select kth smallest element which can be used in many problems.
The best thing about it is , O(n) average case complexity due to recurrenece
 T(N) = T(N/2) + N */
 
 

class Solution {
public:
    map<int, int> count;
    vector<int> unique;
    int partition(int left, int right, int pivot)
    {
        int pivot_freq = count[unique[pivot]];
        std::swap(unique[pivot], unique[right]);
        int swap_index = left;
        for (int i=left;i<=right;++i)
        {
            if (count[unique[i]] < pivot_freq)
            {
                std::swap(unique[i], unique[swap_index]);
                swap_index++;
            }
        }
        std::swap(unique[swap_index], unique[right]);
        return swap_index;
    }
    
    void quick_select(int left, int right, int k_smallest)
    {
        if (left == right)
            return;
        srand (time(NULL));
        int pivot = left + rand() % (right - left);
        pivot = partition(left, right, pivot);
        cout<<pivot;
        if (pivot == k_smallest)
        {
            return;
        }
        else if(pivot < k_smallest)
        {
            quick_select(pivot+1, right, k_smallest);
        }
        else
        {
            quick_select(left, pivot-1, k_smallest);
        }

    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (auto num: nums)
        {
            if (count.find(num)==count.end())
                count[num] = 1;
            else
                count[num]++;
        }
        
        for (auto elem: count) {
            unique.push_back(elem.first);
        }
    
        int n=count.size();
        std::cout<<n<<endl;
        
        quick_select(0, n - 1, n - k);
        
        for (auto elem: unique) {
            cout<<elem;
        }
        vector<int> final_res(unique.begin()+(n-k), unique.end());
        return final_res;
        
    }
};