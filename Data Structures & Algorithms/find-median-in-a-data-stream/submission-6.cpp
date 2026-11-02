class MedianFinder {
public:

    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(min_heap.empty() || min_heap.top() < num){
            min_heap.push(num);
        }else{
            max_heap.push(num);
        }

        if(min_heap.size() > 1+max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }else if(max_heap.size() > 1+min_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        
    }
    
    double findMedian() {

        if (max_heap.size() == min_heap.size()) {
			if (max_heap.empty()) {
				return 0;
			} else {
				double avg = (max_heap.top() + min_heap.top()) / 2.0;
				return avg;
			}

		} else {
			return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
		}
        
    }
};
