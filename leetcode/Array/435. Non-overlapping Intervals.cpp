// https://leetcode.com/problems/non-overlapping-intervals/

we have to sort the intervals on the basis of thier end points,
then use a greeady approach to find the answer.

bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int ans=-1;      
		if(intervals.size()==0) return 0;       
		sort(intervals.begin(),intervals.end(),comp);      //custom comperator is used.
		vector<int> prev= intervals[0];

		for(vector<int> i: intervals) {
			if(prev[1]>i[0]) {
				ans++;                //we dont update previous, because i[1] will be grater then prev[1]
			}else prev=i;           // we want the end point to be minimum
		}
		return ans;                 //ans was initially made -1 because our prev and intervals[0] will always match
	}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       
          int start=intervals[0][0];
          int end=intervals[0][1];
         int count=0;
        for(int i=1;i<intervals.size();i++)
        {
            
            if(end>intervals[i][0])
            {
                count++;
                end=min(end, intervals[i][1]);
            }
            else
                end=intervals[i][1];       
        }
        
        return count;
    }
};