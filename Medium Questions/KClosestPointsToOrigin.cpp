//my slower solution with c++ sort and unessicary stuff like square rooting each number
class Solution {
public:
    bool static comp(pair<double, vector<int>> i, pair<double, vector<int>> j) {
        return (i.first < j.first);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, vector<int>>> distances;
        for (int i = 0; i < points.size(); i++) {
            pair<double, vector<int>> temp {sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), points[i]};
            distances.push_back(temp);
        }
        
        sort(distances.begin(), distances.end(), comp);
        
        vector<vector<int>> result;
        for (int i = 0; i < k; i++) {
            result.push_back(distances[i].second);
        }
        return result;
    }
};


//fast solution with quicksort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> dist;
        dist.resize(points.size());
        for (int i=0;i<points.size();i++) {
            dist[i] = pair<int,int>(points[i][0] * points[i][0] + points[i][1] * points[i][1],i);
        }
        
        partitionK(dist, 0, dist.size(), k);        
        
        vector<vector<int>> result;
        result.reserve(k);
        for (int i = 0; i != k; i++) {
            result.push_back(points[dist[i].second]);
        }
        return result;
    }
    
    void partitionK(vector<pair<int,int>>& dist, int start, int len, int k) {
        if (len == 1) return;
        if (k == len) return;
        pair<int,int> pivot = dist[start];
        swap(dist[start+len-1], dist[start]);
        int store_idx = start;
        for (int i=start;i<start + len-1;i++) {
            if (dist[i].first < pivot.first) {
                swap(dist[i], dist[store_idx++]);
            }
        }
        swap(dist[store_idx++], dist[start+len-1]);
        if ((store_idx-start) == k) return;
        if ((store_idx-start) > k) {
            partitionK(dist, start, store_idx - start, k);            
        } else {
            partitionK(dist, store_idx, len - (store_idx - start), k - (store_idx - start));            
        }
    }
};