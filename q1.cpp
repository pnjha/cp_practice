// Q2) Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Example:
// Explanation:
//   1 <---
//  / \
// 2   3 <---
//  \   \
//  5    4 <---
// Output: [1, 3, 4]
// Explanation:
//   1 <---
//  / \
// 2   3 <---
//  \  /
//  5  4 <---
// Output: [1, 3, 4]

int max_height = 0;

void preorder(Tree* root, int h){
	if(!root) 
		return;
	if(h>max_height){
		max_height = h;
		cout<<root->val<<"\n";
	}
	preorder(root->right, h+1);
	preorder(root->left, h+1);
}

void print_right_view(Tree* root){
	max_height = 0;
	preorder(root,1);
}

max_height = 3
h = 3
1, 3, 4


// Q3) Given an array of integers, for each element find the first element in the right side of the array , 
// which is bigger than the current element: 2, 25, 3, 11, 10, 18 -> 25, -1, 11, 18, 18, -1

s = 25, 2
-1, 18, 18, 11, -1, 25

vector<int> nextGreaterElement(vector<int> arr){
	vector<int> ans;
	stack<int> s;

	for(int i = arr.size()-1;i>=0;i--){
		if(s.empty()){
			ans.push_back(-1);
		}else{
			while(s.top()<arr[i]){
				s.pop();
			}
			if(s.empty()){
				ans.push_back(-1);
			}else{
				ans.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	return ans;
}

arr + intergers
+ integers

2, 5, 7, 1, 9
3
abs(arr[i] - arr[j]) > 3

bool solve(vector<int> arr, int ele){
	int max_val = INT_MIN, min_val = INT_MAX;
	for(int i = 0;i<arr.size();i++){
		if(arr[i] > max_val)
			max_val = arr[i];
		if(arr[i] < min_val)
			min_val = arr[i];
	}
	if(abs(max_val - min_val) > ele)
		return true;
	return false;
}

class A {
public:
	virtual void func1(){
		cout<<"base\n";
	}
};

class B : public A {
public:
	void func1(){
		cout<<"derived\n";
	}
};

int main(){

	A* aobj = new B;
	aobj.func1();
	return 0;
}

Emp (eid, ename, salary, dept_id)
dept (did, dname)
Printout for each dept employee with maximum salary
(did, dname, employee, salary)

Select K.dept_id, K.dname, e.emp_id, e.salary from 
(Select d.dept_id as dept_id, max(e.salary) as salary, d.dname as dname from Emp as e, Dept as d 
groupby d.dept_id, d.dname) as K, from Emp as e, where e.salary == K.salary;

http.createServer(function (req, res) {
 data = fs.readFileSync("response.json") // 5 sec
 res.write(data);
 res.end();
}).listen(8080);