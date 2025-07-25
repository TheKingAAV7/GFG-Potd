class Solution {
public:
    int maxCircularSum(vector<int> &arr) {
        // Handle the case for non-wrapping subarray
        int curr_max = arr[0];
        int max_so_far = arr[0];
        
        // Handle the case for wrapping subarray
        int curr_min = arr[0];
        int min_so_far = arr[0];
        
        int total_sum = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            total_sum += arr[i];
            
            // Kadane's algorithm for maximum subarray
            curr_max = max(arr[i], curr_max + arr[i]);
            max_so_far = max(max_so_far, curr_max);
            
            // Kadane's algorithm for minimum subarray
            curr_min = min(arr[i], curr_min + arr[i]);
            min_so_far = min(min_so_far, curr_min);
        }
        
        // If all elements are negative, return the maximum element
        if (max_so_far < 0)
            return max_so_far;
            
        // Return the maximum of non-circular and circular sums
        return max(max_so_far, total_sum - min_so_far);
    }
};