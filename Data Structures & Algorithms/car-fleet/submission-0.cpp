class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<pair<int, int>> carstack;        
        vector<pair<int, int>> carPairs;

        // populate the array of pairs with their position and speed
        for(int i = 0; i < n; i++) {
            carPairs.push_back({position[i], speed[i]});
        }

        // sort the array
        sort(carPairs.begin(), carPairs.end());

        // iterate backwards through the loop
        for(int j = n - 1; j >= 0; j--) {
            // add an element to the stack
            carstack.push(carPairs[j]);
            
            // if there is not enough elements to make a comparison continue
            if(carstack.size() < 2) continue;

            // get the two top elements from the stack
            pair<int, int> car2 = carstack.top();
            carstack.pop();

            pair<int, int> car1 = carstack.top();
            carstack.pop();

            // calculate how long it'll take for each of them to reach their destination
            double car1Time = (double)(target - car1.first)/car1.second;
            double car2Time = (double)(target - car2.first)/car2.second;


            // if car 2 will arrive faster than car 1, which is in front of it
            // then they are a car fleet bottlenecked by
            // car1, so then only push car1 back to the stack
            // otherwise push back both if they're their own car fleets
            if(car2Time <= car1Time) {
                carstack.push(car1);
            } else {
                carstack.push(car1);
                carstack.push(car2);
            }
        }

        // the size of the remaining carstack is the solution for how many individual fleets there are
        return carstack.size();
    }
};
