struct cmp {
    bool operator() (pair<int,string>a,pair<int,string>b) const {
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
    const int N=20005;
    set<pair<int,string>,cmp>s[N];
    
class FoodRatings {
public:
   unordered_map<string,string>food;
  unordered_map<string,int>index;
    unordered_map<string,int>rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            s[i].clear();
        }
        for(int i=0;i<foods.size();i++){
            food[foods[i]]=cuisines[i];
                rating[foods[i]]=ratings[i];
            index[cuisines[i]]=i;
           
        }
      
        for(int i=0;i<foods.size();i++){
            int idx=index[cuisines[i]];
           s[idx].insert(make_pair(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string f, int newRating) {
        string cuisine=food[f];
        int idx=index[cuisine];
        int rate=rating[f];
        auto it=s[idx].find({rate,f});
        if(it!=s[idx].end()){
            s[idx].erase({rate,f});
        }
        s[idx].insert({newRating,f});
        rating[f]=newRating;
        
    }
    
    string highestRated(string cuisine) {
        int idx=index[cuisine];
        auto it=s[idx].end();
        it--;
    
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */