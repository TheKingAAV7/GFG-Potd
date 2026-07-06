class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &enemy) {
        // code here
        vector <int> x;

        vector <int> y;

        

        x.push_back(0);

        for(int i = 0; i < k; i++)

            x.push_back(enemy[i][0]);

        x.push_back(n+1);

        

        int x_max = 0;

        

        sort(x.begin(),x.end());

        

        for(int i = 0; i < x.size()-1; i++){

            x_max = max(x_max,x[i+1]-x[i]-1);

        }

        

        y.push_back(0);

        for(int i = 0; i < k; i++) {

            y.push_back(enemy[i][1]);

        }

        y.push_back(m+1);

        

        sort(y.begin(),y.end());

        

        int y_max = 0;

        

        for(int i = 0; i < y.size()-1; i++) {

            y_max = max(y_max,y[i+1] - y[i]-1);

        }

        

        // cout << x_max <<" " << y_max << endl;

        return x_max*y_max;
    }
};