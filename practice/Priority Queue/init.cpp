#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;
    public:
        PriorityQueue(){

        }
        bool isEmpty(){
            return pq.size() == 0;
        }

        // total no of elements present
        int getSize(){
            return pq.size();
        }

        int getMin(){
            if(isEmpty)return 0;
            return pq[0];
        }

        // PARENT INDEX = (CHILD INDEX - 1) / 2
        // FOR I, PREV ELEMENT INDEX = 2I + 1, NEXT ELEMENT INDEX = 2I + 2
        void insert(int n){
            pq.push_back(n);
            int CI = pq.size() - 1;            
            while(cI > 0){
                int pI = (cI - 1) / 2;
                if(pq[cI] < pq[PI]){
                    swap(pq[cI], pq[pI]);                
                    cI = pI;
                }
                else break;
            }
        }

        int removeMin(){
            if(isEmpty())return 0;

            int ans = pq[0];
            swap(pq[0], pq[pq.size()-1]);
            pq.pop_back();

            //CBT Satisfied

            // Down Heapify
            int pI = 0;
            while(true){
                int lCI = 2 * pI + 1;
                int rCI = 2 * pI + 2;
                int min = pI;

                if(pq[lCI] < pq[min])min = lCI;
                
            }
        }
}

int main(){}
