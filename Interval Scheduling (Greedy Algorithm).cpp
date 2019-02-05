#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
class Solution
{
public:
    Solution(vector<pair<int,int> >);
    vector<pair<int,int> > rallies;
    vector<pair<int,int> > outputRallies();
};

Solution::Solution(vector<pair<int,int> > _rallies)
{
    rallies = _rallies;
}

/** Implement the solution in this function
 * Return a vector of pairs of int containing the Rally ID and start time of the schedule you computed
 * or an empty vector of pairs of int if there exists no valid schedule and Serena has to take the nuke option.
 *
 * Don't change any files but this one!
 */
vector<pair<int,int> > Solution::outputRallies()
{

    int a ,b;

    std::vector<std::pair<int,int> > schedule;
    std::vector<std::pair<int,int> > noSchedule;
    std::pair<int,int> vPair;

    std::vector<vector<int> > myList;
    std::vector<int> temp;
    //creates triple tuplets where 3rd ele is the index and adds all of them to mylist
    for (int i = 0; i < rallies.size() ; ++i) {
        temp.push_back(rallies[i].first);
        temp.push_back(rallies[i].second);
        temp.push_back(i);
        myList.push_back(temp);
        temp.clear();
    }

    //sorts mylist in ascending order
    std::sort(myList.begin(), myList.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    });


    b = 0;
    for (int j = 0; j < rallies.size() ; ++j) {
        if (j == 0){
            a = myList[j][2];
            int c = myList[j][1];
            vPair = std::make_pair(a,b);
            schedule.push_back(vPair);
            b += c;
        }
        else{
            a = myList[j][2];
            int t = myList[0][0];
            int d = myList[j][1];
            if(b+t > rallies[a].second){
                return std::vector<pair<int, int> >();
            }
            vPair = std::make_pair(a, b);
            schedule.push_back(vPair);
            b += d;
        }

    }

    return schedule;
}
