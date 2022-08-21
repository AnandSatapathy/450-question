priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        for (int i = 0; i < mat.size(); i++) {
            int soldiercount = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) soldiercount++;
            }
           
            pq.push({soldiercount, i});
        }
        vector<int> res;

        while (!pq.empty() && k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
