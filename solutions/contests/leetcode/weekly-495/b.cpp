// https://leetcode.com/problems/design-event-manager/

class EventManager {
public:
    struct Compare {
        bool operator()(pair<int,int>& p1, pair<int,int>& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    unordered_map<int,int> m;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

    EventManager(vector<vector<int>>& events) {
        for (auto& event : events) {
            m[event[0]] = event[1];
            pq.push({event[0], event[1]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        m[eventId] = newPriority;
        pq.push({eventId, newPriority});
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [id, prio] = pq.top();
            pq.pop();

            if (m.count(id) &&  m[id] == prio) {
                m.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */