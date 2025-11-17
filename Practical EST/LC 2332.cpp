class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int j = 0, m = passengers.size();
        int lastBoarded = -1;
        for (int bus : buses) {
            int cap = capacity;
            while (cap > 0 && j < m && passengers[j] <= bus) {
                lastBoarded = passengers[j];
                j++;
                cap--;
            }
        }
        unordered_set<int> taken(passengers.begin(), passengers.end());
        int lastBus = buses.back();
        int idx = 0, count = 0;
        for (int bus : buses) {
            count = 0;
            while (idx < m && passengers[idx] <= bus && count < capacity) {
                count++;
                idx++;
            }
        }

        int candidate;
        if (count < capacity) {
            candidate = lastBus;
        } 
        else {
            candidate = lastBoarded - 1;
        }
        while (taken.count(candidate)) candidate--;
        return candidate;
    }
};
