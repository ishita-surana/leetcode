class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSqSum = 0;

        for(auto &row : grid) {
            for(int num : row) {
                actualSum += num;
                actualSqSum += 1LL * num * num;
            }
        }

        long long x = actualSum - expectedSum;          // a - b
        long long y = (actualSqSum - expectedSqSum) / x; // a + b

        long long a = (x + y) / 2; // repeating
        long long b = (y - x) / 2; // missing

        return {(int)a, (int)b};
    }
};