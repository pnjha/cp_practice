
int largestRectangleArea(vector<int>& heights) {
        
    if(heights.size()==0)
        return 0;
    if(heights.size()==1)
        return heights[0];
    
    int area = INT_MIN;
    int top=0;
    heights.push_back(-1);
    stack<int> s;
    
    int i=0;
    while(i<heights.size()){
        
        if(s.empty()||heights[s.top()]<=heights[i]){
            s.push(i++);
        }else{
            top = s.top();
            s.pop();
            int temp = heights[top] * (s.empty()?i:i-s.top()-1);
            if(temp>area)
                area = temp;
            
        }
    }
    
    return area;
}