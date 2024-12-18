class Solution 
{
public:
    int mySqrt(int x) 
    {
        if( x < 2) return x;

        long num;
        int pivot;
        int left = 2;
        int right = x / 2;

        while(left <= right)
        {
            pivot = left + (right - left) / 2;
            num = (long)pivot * pivot;

            if(num > x) right = pivot - 1;
            else if (num < x) left = pivot + 1;
            else return pivot;
        }
        return right;
    }
};

// Time Complexity:
// O(Log(N))
// N = X
// Dividing range by 2, hence logarithmic complexity

// Space Complexity:
// O(1)
// Constant, no extra memory or allocation