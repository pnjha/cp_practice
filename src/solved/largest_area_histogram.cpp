//using stack approach O(n) solution
//Example: largestRectangleArea.jpg

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

//Divide and conquer approach O(nlogn)
//O(n) work on every O(logn) levels
int max(int a,int b){
    return a>b?a:b;
}

int largest_area(vector<int>& heights,int start,int end){
    
    if(start<0||end>=heights.size()||end<start)
        return 0;
    
    if(start==end){
        return heights[start];
    }
    
    int min_height = heights[start],min_index = start;
    
    for(int i = start+1;i<=end; ++i){
        if(heights[i]<min_height){
            min_height = heights[i];
            min_index = i;
        }
    }
    
    int area_left = largest_area(heights,start,min_index-1);
    int area_right = largest_area(heights,min_index+1,end);
    int area_curr = min_height*(end-start+1);
    
    return max(area_curr,max(area_left,area_right));
}

int largestRectangleArea(vector<int>& heights){

    return largest_area(heights,0,heights.size()-1);
}