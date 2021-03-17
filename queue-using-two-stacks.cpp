#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(long int x) 
        {
            stack_newest_on_top.push(x);
        }

        void pop() 
        {
            updateOldest();
            stack_oldest_on_top.pop();
        }

        int front() 
        {
            updateOldest();
            return stack_oldest_on_top.top();
        }
    
    private:
    void updateOldest() 
    {
        if(stack_oldest_on_top.empty())
        {
            while(!stack_newest_on_top.empty()) 
            {
                stack_oldest_on_top.push(stack_newest_on_top.top());
                stack_newest_on_top.pop();
            }
        }
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    if ((q < 1) || (q > 100000)) return -1;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if ((type < 1) || (type > 3)) return -1 ;
        if(type == 1) {
            cin >> x;
            if ((x < 1) || (x > 1000000000)) return -1;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
