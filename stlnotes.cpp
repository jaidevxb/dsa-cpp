STL NOTES


Alogrithms
Containers
Functions
Iterators







void explainPair(){

    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second;

    pair<int, pair<int, int> p = {1, {2, 3}};

    cout << p.first << " " << p.second.first << " " << p.second.second;

    pair<int, int> arr[] = { {1, 2}, {2, 3}, {4, 5}};

    cout << arr[1].second;
}









void explainVector(){

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;

    vec.push_back({1, 3});
    vec.emplace_back(4, 5); // {} not required for emplace back

    vector<int> v(5, 100); // {100, 100, 100, 100, 100}

    vector<int> v(5);

    vector<int> v1(5, 20);
    vector<int> v2(v1);

    // Access elements of vector
    
     vector<int>::iterator it = v.begin();
     it++;
     cout << *(it) << " ";

     it = it+2;
     cout << *(it) << " ";

    vector<int>::iterator it = v.end(); // Points the address of last+1 element

    vector<int>::iterator it = v.rend();

    vector<int>::iterator it = v.rbegin();

    
    
    cout << v[0] << " " << v.at(0);

    cout << v.back() << " "; // Prints last element



    for(vector<int>::iterator it = v.begin(); it < v.end(); it++)
        cout << *(it) << " ";

    // Auto = automatically assigns the data type, auto a = 5 assigns a as int
    for(auto it = v.begin(); it < v.end(); it++)
        cout << *(it) << " ";

    // For each loop, it on v points the value not the address so no need of *(it)
    for(auto it : v)
        cout << it << " ";

    // Deletion
    // {10, 20, 25, 30, 40}
    v.erase(v.begin()+2); // {10, 20, 30, 40}
    v.erase(v.begin() + 2, v.begin() + 4) // {10, 20, 40} (start, end+1)

    // Insert Function
    vector<int> v(2,100); // {100, 100}
    v.insert(v.begin(), 300); // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100} (position, no. of occurrence, value)

    vector<int> copy(2, 50); // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // Size {10, 20}
    cout << v.size(); // 2

    // PopBack {10, 20}
    v.pop_back(); //{10}

    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2); // v1 -> {30, 40}, v2 -> {10, 20}

    v.clear() // Erases entire vector

    cout << v.empty(); // Returns 1 if the vector is empty 0 if its non empty

}





void explainList(){
    list<int> ls;

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4}
    ls.emplace_front(7); //{7, 5, 2, 4}

    ls.front(); // Access first element
    ls.back(); // Access last element

    ls.pop_front(); // Removes first element
    ls.pop_back(); // Removes second element

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap

}







void explainDeque(){
    deque<int> dq; 
    // Same as List
    dq.push_back(2); // {2}
    dq.emplace_back(4); // {2, 4}
    dq.push_front(5); // {5, 2, 4}
    dq.emplace_front(7); //{7, 5, 2, 4}

    // Rest of functions same as vector
    // front(), back(), pop_front(), pop_back() 
    // begin, end, rbegin, rend, clear, insert, size, swap
    
}






// LIFO = Last In First Out
void explainStack(){
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // prints 5 ** st[0] is invalid, no index accessing **

    st.pop(); // {3, 3, 2, 1}

    cout << st.top(); // 3

    cout << st.size(); // 4

    cout << st.empty(); // 0

    stack<int> st1, st2;
    st1.swap(st2);

    // ** No Front or Back Access **, push(), top(), pop() are main functions
    // Cant access bottom elements directly
}







// FIFO = First In First Out
void explainQueue(){
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}

    q.back() += 5; // 4+5
    cout << q.back(); // prints 9 

    // {1, 2, 9}
    cout << q.front(); // prints 1

    q.pop(); // {2, 9}

    cout << q.front(); // prints 2

    // stack -> top(),cant access bottom    queue -> front(), back()
    // size(), swap(), empty() same as stack
}





void explainPQ(){
    // Maximum Heap (Big one goes to top place)
    priority_queue<int> pq;

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // prints 10

    pq.pop(); // {8, 5, 2}

    cout << pq.top(); // prints 8

    // size(), swap(), empty() same as others

    // Minimum Heap (Small one goes to top place)
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // prints 2

}







// ** SORTED AND UNIQUE **
void explainSet(){
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    // Functionality of insert in vector can also be used, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(), swap(), empty() are same as above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // iterator points the address of 3
    auto it = st.find(6); // if the element is not in the set it'll return st.end() -> address after 5, used to find if the element exists in the set or not

    // {1, 4, 5}
    int cnt = st.count(5); // cnt will always be 1 or 0 since the elements are unique

    st.erase(5); // erases 5, takes logaritmic time // erase(value)
    
    auto it = st.find(5);  
    st.erase(it); // erases 5, takes constant time // erase(address)
     
    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // {1, 4, 5} [start, end) aka (start, end+1) same as vector

    // lower_bound() and upper_bound() functions works in the same way as in vector

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // lower bound explanation
    a[] = {1, 4, 5, 6, 9, 9};
    int ind = lower_bound(a, a+n, 4) - a; // points 4 i.e 1st index
    int ind = lower_bound(a, a+n, 7) - a; // since 7 does not exists points to next greater value i.e 9 at 4th index
    int ind = lower_bound(a, a+n, 10) - a; // points a.end() i.e 6th index

    int ind = lower_bound(a.begin(), a.end(), x) - a.begin(); // in vector

    // upper bound explanation
    a[] = {1, 4, 5, 6, 9, 9};
    int ind = upper_bound(a, a+n, 4) - a; // points next greater value to 4 i.e 2nd index
    int ind = upper_bound(a, a+n, 7) - a; // since 7 does not exists points to next greater value i.e 9 at 4th index
    int ind = upper_bound(a, a+n, 10) - a; // points a.end() i.e 6th index

    int ind = upper_bound(a.begin(), a.end(), x) - a.begin(); // in vector

}









// SORTED BUT NOT UNIQUE   
void explainMultiSet(){
    // Everything is same as set only difference is it can store duplicate elements also

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    int cnt = ms.count(1); // 3 

    ms.erase(1); // all 1's will be erased since we giving value

    // to delete one occurance of 1
    ms.erase(ms.find(1)); // since ms.find() points the iterator i.e the address only the first 1 will be erased

    // to delete first 2 occurance of 1
    ms.erase(ms.find(1), ms.find(1)+2); // erase [start, end+1)

}







// UNIQUE BUT NOT SORTED (STORES IN RANDOM ORDER)
void explainUSet(){
    unordered_set<int> st;
    
    // lower and upper bound functions does not work
    // rest all functions are same as above
    // it does not store in any particular order it has better complexity than set in most of cases
    // except some when collision happens 

}






// KEY AND VALUE, CAN HAVE DUPLICATE VALUES BUT NOT KEYS
// STORES UNIQUE KEYS IN SORTED ORDER
void explainMap(){
    // KEY AND VALUE CAN BE ANY DATATYPE
    map<int, int> mpp;
    mpp[1] = 2; // {1: 2}
    mpp.emplace(3, 1); // {1: 2, 3: 1}
    mpp.insert({2, 4}); // {1: 2, 2: 4, 3: 1}


    map<int, pair<int, int>> mpp;
    mpp[1] = {2, 3};  // {1: (2, 3)}
    mpp.emplace(3, {1, 4}); // {1: (2, 3), 3: (1, 4)}
    mpp.insert({2, {5, 6}}); // {1: (2, 3), 2: (5, 6), 3: (1, 4)}


    map<pair<int, int>, int> mpp;
    mpp[{1, 2}] = 3;       // {(1, 2): 3}
    mpp.emplace({3, 4}, 5); // {(1, 2): 3, (3, 4): 5}
    mpp.insert({{2, 3}, 6}); // {(1, 2): 3, (2, 3): 6, (3, 4): 5}


    for(auto it : mpp){   // auto is pair here
        cout << it.first << " " << it.second << endl;
    }

    // {1: 2, 2: 4, 3: 1}
    cout << mpp[1]; // print 2
    cout << mpp[5]; // it does not exists since it prints 0

    auto it = mpp.find(3); // iterator points the address of {3, 1}
    cout << *(it).second; // * to get key and .second for the value, only *(it) prints key i.e 3

    auto it = mpp.find(5); // points mpp.end()

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as above


}





void explainMultimap(){
    // everything is same as map, only difference is it can store multiple keys i.e duplicate keys but sorted order
    // similar to set and multiset
    // map[key] cannot be used here

    multimap<int, int> mm;

    mm.insert({1, 100});
    mm.insert({2, 200});
    mm.emplace(1, 150);

    for (auto it : mm){
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }
    
}
    
    

void explainUMap(){
    // same as set and unordered_set difference

}


// CONTAINERS AND ITERATORS ARE OVER FUNCTIONS YOU CAN SKIP NOT NEEDED
// WILL START ALGORITHMS



bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // they are same

    if (p1.first > p2.first) return true;
    return false;
}

void explainAlgo(){
    
    sort(a, a + n);  // [start, end) for array
    sor(v.begin(), v.end())  // for vector

    // partial sort
    sort(a + 2, a + 4);

    // decending order
    sort(a, a+n, greater<int>);

    pair<int, int> a[] = {{1, 2}, {2,1}, {4, 1}};
    // sort it according to second element -> {{2,1}, {4, 1}, {1, 2}}
    // if second element is same then sort 
    // according to first element but in decending -> {{4, 1}, {2,1}, {1, 2}}

    sort(a, a+n, comp); // Custom comparator
    // {{4, 1}, {2,1}, {1, 2}}


    // Calculate the number of set bits for each integer
    int num = 7;
    int cnt = __builtin_popcount(num); // returns no. of 1's from binary representation

    long long num1 = 165786578687;
    int cnt1 = __builtin_popcountll(num1);

    cout << "Number of set bits in " << num << cnt << endl;
    cout << "Number of set bits in " << num1 << cnt1 << endl;

    string s = "123";
    sort(s.begin(), s.end());
    do {
        cout << s << endl;  
    } while(next_permutation(s.begin, s.end()));  // 123, 132, 213, 231, 312, 321

    int max = *max_element(a, a+n); // * to get value cos max, min points address
    int min = *min_element(a, a+n);


}

