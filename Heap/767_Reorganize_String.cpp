
struct comparator
{
  bool operator() (const pair<char, int>& p1, const pair<char, int>& p2)
  {
      return p1.second < p2.second;
  }       
};
class Solution {
public:
    
    string reorganizeString(string s) {
        string output;
        unordered_map<char, int> freq;
        for(auto ch: s)
        {
            freq[ch]++;
        }
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, comparator> maxHeap;
        
        for(auto f: freq)
        {
            maxHeap.push(f);
        }
        
        pair<char, int> prev;
        while(!maxHeap.empty())
        {
            auto top = maxHeap.top();
            maxHeap.pop();
            output += top.first;
            if(prev.second > 1)
            {
                maxHeap.push(make_pair(prev.first, prev.second - 1));
            }
            prev = top;
        }
        
        return prev.second > 1 ? "" : output;
        
    }
};