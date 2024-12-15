class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> maxHeap;
        for(const vector<int>& c : classes)
        {
            const int pass = c[0];
            const int total = c[1];
            maxHeap.emplace(extraPassRatio(pass, total), pass, total);
        }

        for(int i{0}; i < extraStudents; ++i)
        {
            const auto [_, pass, total] = maxHeap.top();
            maxHeap.pop();
            maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
        }
        double ratio_sum{0};
        while(!maxHeap.empty())
        {
            const auto [_, pass, total] = maxHeap.top();
            maxHeap.pop();
            ratio_sum += pass / static_cast<double>(total);
        }
        return ratio_sum / classes.size();
    }
private:
    double extraPassRatio(int pass, int total)
    {
        return (pass + 1) / static_cast<double>(total + 1) - pass / static_cast<double>(total);
    }
};