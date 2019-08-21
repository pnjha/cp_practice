#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int find_distance(string& a, string& b){
    int dist = 0;
    for(int i = 0;i<a.length();i++)
        if(a[i] != b[i])
            dist++;
    return dist;
}

void create_graph(vector<string>& wordList){
    for(int i = 0;i<wordList.size();i++){
        for(int j = i+1;j<wordList.size();j++){
            if(find_distance(wordList[i],wordList[j])==1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

int bfs(int start_node, int end_node) {

    //node number  path length

    queue<pair<int,int>> q;
    pair<int,int> p;

    q.push({start_node,0});
    visited[start_node] = true;

    int path_length = -1;

    while(!q.empty()){
        
        p = q.front();

        if(p.first == end_node){
            path_length = p.second;
            break;
        }

        q.pop();

        for(int i = 0;i<graph[p.first].size();i++){

            if(!visited[graph[p.first][i]]){

                visited[graph[p.first][i]] = true;				
                q.push({graph[p.first][i], p.second+1});
            }
        }
    }

    return path_length;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    ios_base::sync_with_stdio(false);
    
    bool flag = true;
    vector<int> index;
    int min_val = INT_MAX, end_index, min_index = -1,temp = 0;

    for(int i = 0;i<wordList.size();i++){

        if(flag && wordList[i] == endWord){
            flag = false;
            end_index = i;			
        }

        if(find_distance(beginWord,wordList[i])<=1){
            index.push_back(i);
        }
    }

    if(flag)
        return 0;

    graph.clear();
    graph.resize(wordList.size());

    visited.clear();
    visited.resize(wordList.size(),false);

    create_graph(wordList);

    for(int i = 0;i<index.size();i++){
            
        visited.clear();
        visited.resize(wordList.size(),false);
        
        temp = bfs(index[i] ,end_index);

        if(temp == -1){
            continue;
        }

        if(find_distance(wordList[index[i]],beginWord)==0){
            temp += 1; 
        }else{
            temp += 2;
        }

        if(min_val > temp){
            min_val = temp;
            min_index = index[i];
        }
    }

    if(min_val == INT_MAX)
        return 0;
    
    return min_val;
    
}

int main(){

	vector<string> s = {"hot","dog"};
	string beginWord = "hot";
	string endWord = "dog";

	cout<<ladderLength(beginWord,endWord,s)<<"\n";


	return 0;
}
