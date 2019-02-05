#include <vector>
#include <float.h>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {

    /*
    * Class data:
    * points:
    *  - the location of the 2-D points for the problem
    */
public:

    Solution(std::vector<std::pair<int,int>> in_points);
    double outputClosestDistance();
    std::vector<std::pair<int,int>> points;
};



Solution::Solution(std::vector<std::pair<int,int>> in_points) :
    points(in_points)
{/* Nothing needs to be added here.*/}

/*double distance(std::pair<int,int> a ,std::pair<int,int> b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double delta(std::vector<std::pair<int,int>> ghost , int s, double o){
    double minimum = o;

    *//*std::sort(ghost.begin(), ghost.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        return a.second < b.second;
    });*//*

    for (int i = 0; i < s; ++i) {
        for (int j = i+1; j < s && (ghost[j].second - ghost[i].second) < minimum; ++j) {
            if(distance(ghost[i], ghost[j]) < minimum){
                minimum = distance(ghost[i], ghost[j]);
            }
        }
    }

    return minimum;
}

double min(double bro, double sis){
    if (bro < sis) {
        return bro;
    } else {
        return sis;
    }
}



double bruteForce(std::vector<std::pair<int,int>> haha, int n){

    double min = DBL_MAX;
    for(int i = 0; i < n; ++i){
        for(int j =i+1; j < n; j++){
            if(distance(haha[i],haha[j]) < min){
                min = distance(haha[i], haha[j]);
            }
        }
    }
    return min;
}

double closestDist(std::vector<std::pair<int,int>> x_point,std::vector<std::pair<int,int>> y_point, int p){
    if(p < 4){
        return bruteForce(x_point,p);
    }

    int mid = p/2;

    std::pair<int,int> midpoint = x_point[mid];

    std::vector<std::pair<int,int>> y_left(y_point.begin(), y_point.end()-mid+1);
    std::vector<std::pair<int,int>> y_right(y_point.begin()+mid +1, y_point.end());

    int cur_left = 0;
    int cur_right = 0;

    for (int i = 0; i < p ; ++i) {
        if(y_point[i].first <= midpoint.first){
            y_left[cur_left+=1] = y_point[i];
        }
        else y_right[cur_right+=1] = y_point[i];
    }


    double left = closestDist(x_point,y_left,mid);
    std::vector<std::pair<int,int>> v1(x_point.begin() + mid, x_point.end());
    double right = closestDist(v1,y_right,p-mid);

    double dee = min(left, right);

    std::vector<std::pair<int,int> > nav(p);

    int c = 0;
    for (int i = 0; i <p ; ++i) {
        if(abs(y_point[i].first - midpoint.first) < dee){
            nav[c] = y_point[i];
            c+=1;
        }
    }

    return min(dee, delta(nav,c,dee));
}*/

struct Point
{
    int x, y;
};

int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
// Needed to sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// A utility function to find the distance between two points
double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
    );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
double bruteForce(Point P[], int n)
{
    double min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// A utility function to find minimum of two float values
double min(double x, double y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
double stripClosest(Point strip[], int size, double d)
{
    float min = d;  // Initialize the minimum distance as d

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// A recursive function to find the smallest distance. The array Px contains
// all points sorted according to x coordinates and Py contains all points
// sorted according to y coordinates
double closestUtil(Point Px[], Point Py[], int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);

    // Find the middle point
    int mid = n/2;
    Point midPoint = Px[mid];


    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    Point Pyl[mid+1];   // y sorted points on left of vertical line
    Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++)
    {
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }

    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    double dl = closestUtil(Px, Pyl, mid);
    double dr = closestUtil(Px + mid, Pyr, n-mid);

    // Find the smaller of two distances
    double d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;

    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, j, d) );
}

// The main functin that finds the smallest distance
// This method mainly uses closestUtil()
double closest(vector<pair<int,int>> vec, int n)
{
    Point Px[n];
    Point Py[n];

    for (int i = 0; i < n; i++)
    {

        Px[i].x = vec[i].first;
        Py[i].y = vec[i].second;
    }

    qsort(Px, n, sizeof(Point), compareX);
    qsort(Py, n, sizeof(Point), compareY);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(Px, Py, n);
}

double Solution::outputClosestDistance() {

    /*std::vector<std::pair<int,int>> yVec(points.begin(), points.end());

    std::sort(points.begin(), points.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        if(a.first == b.first){
          return  a.second < b.second;
        }
        else return a.first < b.first;
    });

    std::sort(yVec.begin(), yVec.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        if(a.second == b.second){
          return  a.first < b.first;
        }
        else return a.second < b.second;
    });*/




    int nsize = points.size();

    return closest(points, nsize);
}
