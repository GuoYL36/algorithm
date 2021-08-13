// leetcode84、柱状图中最大的矩形——困难
// 题目描述：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 解题思路：
// 依次遍历每个元素，以该元素为中心，向左和向右遍历，找到第一个使得左边的元素值及右边的元素值小于该元素，记录左右索引（记录的是两端中第一个大于当前元素的索引），该长度即为以当前元素作为高时的矩形宽度。


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    // 时间复杂度为O(N^2)，空间复杂度为O(1)————超时
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        int res=0;
        for(int i=0;i<length;i++){
            // 已当前元素为中心
            int left=i, right=i;
            // 找到左边第一个小于当前元素的值
            while((left-1)>=0 && (heights[left-1]>=heights[i])){
                left--;
            }
            // 找到右边第一个小于当前元素的值
            while((right+1)<length && (heights[right+1]>=heights[i])){
                right++;
            }
            res = max(res, (right-left+1)*heights[i]);
        }
        return res;
    }

    // 利用“栈+哨兵(即索引为-1或者length)”进行优化，时间复杂度为O(N)、空间复杂度为O(N)
    // 利用栈来记录比当前元素小的第一个左边元素和第一个右边元素的索引
    int largestRectangleArea0(vector<int>& heights) {
        int length = heights.size();
        stack<int> s;  // 记录比当前元素小的元素索引
        vector<int> left(length), right(length); // 用于记录当前元素的左右边界索引
        for(int i=0;i<length;i++){
            // 假如栈非空，则从栈中依次弹出当前索引之前的，比当前元素大的元素索引
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i] = s.empty()?-1:s.top(); // 记录当前元素的左边界, -1作为哨兵
            s.push(i);
        }

        s = stack<int>();
        for(int i=length-1;i>=0;i--){
            // 假如栈非空，则从栈中依次弹出当前索引之前的，比当前元素大的元素索引
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i] = s.empty()?length:s.top(); // 记录当前元素的右边界, length作为哨兵
            s.push(i);
        }

        // 计算结果
        int res=0;
        for(int i=0;i<length;i++){
            res = max(res, (right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }

    // 优化利用“栈+哨兵”方式，左右两次遍历可以改为1次.时间复杂度为O(N)、空间复杂度为O(N)
    // 由于栈中元素是依次递增的，当找左边界的时候，只需要找到栈中小于当前元素的值，作为左边界，大于当前的元素的值就弹出；
    // 当找右边界的时候，由于栈中元素是依次递增的，如果当前元素比栈中某些元素值小，则当前元素可以作为这些元素的右边界；
    int largestRectangleArea1(vector<int>& heights) {
        int length = heights.size();
        stack<int> s;
        vector<int> left(length),right(length,length); // 用哨兵初始化right数组

        for(int i=0;i<length;i++){
            while(!s.empty() && (heights[s.top()]>=heights[i])){
                right[s.top()] = i;   // 由于栈中元素是递增的，假如当前元素小于栈中元素时，可以认为当前元素为这些元素右边遇到的第一个小于这些元素的（反向思考为栈中的元素找到右边第一个最小的）
                s.pop();
            }
            left[i] = s.empty()?-1:s.top();
            s.push(i);
        }

        // 计算结果
        int res=0;
        for(int i=0;i<length;i++){
            res = max(res, (right[i]-left[i]-1)*heights[i]);
        }
        return res;



    }

        
};


int main(){
    vector<int> heights;
    heights = {2,1,5,6,2,3};
    Solution func = Solution();
    cout<<"=== first baoli method ==="<<endl;
    cout<<func.largestRectangleArea(heights)<<endl;
    cout<<"=== second better method ==="<<endl;
    cout<<func.largestRectangleArea0(heights)<<endl;
    cout<<"=== third best method ==="<<endl;
    cout<<func.largestRectangleArea1(heights)<<endl;
    return 1;
}










