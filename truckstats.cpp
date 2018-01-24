#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <set>
#include <utility>
#include <string>
using namespace std;


map<int,int> get_stats(vector< tuple<int,int> >&truck_data){
	map<int,int> truck_stats;
	for (int i =0; i< truck_data.size(); i++){
        int start = get<0>(truck_data[i]);
        int end = get<1>(truck_data[i]);
        for (int j = start; j <= end ; j++){
            if (truck_stats.find(j) != truck_stats.end()){
                truck_stats[j] ++;
            }else {
                truck_stats[j] = 1;
            }
        }
	}
    return truck_stats;
	
}


int main(){
    cout << "Program start here"<< endl;
    vector<tuple<int,int> > v1 {{1900,1950},{1910,1940},{1905,1960},{1960,1980}};
    map<int,int>res = get_stats(v1);
    vector<pair<int,int>>values;
 
    for (map<int,int>::iterator it = res.begin() ; it != res.end();it++){
        values.push_back(make_pair(it->second,it->first));
        
    }
    sort(values.begin(),values.end());
  
    int most = values[values.size()-1].first;
    int year =values[values.size()-1].second;
    for (map<int,int>::iterator it = res.begin() ; it != res.end();it++){
        if (it -> second == most){
            year = it->first;
            break;
        }
        
    }
    cout << "Most: " << year<< " (" <<  most << " truck";
    if (most == 1){
        cout << ")" <<endl;
    }else {
        cout << "s)" << endl;
    }
    cout << "Least: " << values[0].second << " (" <<  values[0].first << " truck";
    if (values[0].first == 1){
        cout << ")" <<endl;
    }else {
        cout << "s)" << endl;
    }
    
    cout << "Top-5:[ " ;
    
   
    int count = 0;
    int k = 0;
    
    
    
        for (map<int,int>::iterator it = res.begin() ; it != res.end();it++){
            int t = values[values.size()-1-k].first;
            if (k == 5) break;
            if (it -> second == t){
                cout << "(" << it->first << ", "  << t << ") " ;
                count ++;
                k++;
                
            }
        }
    cout << "]" <<endl;
    
    
    cout << "Least-3:[ " ;
    
    for (int i = 0 ; i < 3; i++){
        cout << "("<<values[i].second << ", " <<values[i].first << ") " ;
    }
    cout << "]" << endl;
    
   
}


