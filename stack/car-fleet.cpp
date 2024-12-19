bool cmp(pair<int,int>a, pair<int,int>b) {
	return a.first > b.first;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int n = position.size();
		vector<pair<int, int>> cars(n);
		for(int i = 0; i < n; i++) {
			cars[i] = pair<int,int>(position[i], speed[i]);
		}
		// sort cars in descending order of position
		sort(cars.begin(), cars.end(), cmp);

		// do fleets instead of time to avoid rounding issues
		stack<double> fleets;
		for(const auto &car : cars) {
			double time = static_cast<double>(target - car.first) / car.second;
			if(fleets.empty()) {
				fleets.push(time);
			}
			else if(time > fleets.top()) {
				fleets.push(time);
			}
		}
		return fleets.size();
    }
};

