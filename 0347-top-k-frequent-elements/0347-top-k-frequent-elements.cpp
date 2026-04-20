class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fr;
        for( int num:nums){
            fr[num]++;
        }
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        for(auto& p: fr){
            pq.push({p.second,p.first});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
        
    }
};
اخر حاجة في الكود بنجيب السكاند الي هو العدد مش التكرار لاني هو عاوز الاعداد احنا خلينا الاعداد الاكثر تكرار بس فمجرد بنطلعها من المصفوفة
