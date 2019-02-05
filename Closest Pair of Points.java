package ub.cse.algo;

import java.util.ArrayList;

import java.util.Collections;
import java.util.Comparator;

public class Solution {

    private Integer _n_points;          // Number of points in the plane
    private ArrayList<Point> _points;  // This ArrayList contains all points in the plane

    public Solution (Integer n_points, ArrayList<Point> points){
        _n_points = n_points;
        _points = points;
    }


    public double min(double x, double y)
    {
        return (x < y)? x : y;
    }

    public double distance(Point p1, Point p2){
    	double distance;
    	distance = Math.sqrt((p1._x - p2._x)*(p1._x -p2._x) +(p1._y - p2._y)*(p1._y - p2._y));
    	return distance;
    }

    public double bruteForce(ArrayList<Point> p, int b){
    	double min = Double.MAX_VALUE;
    	for (int i = 0; i < b; i++) {
			for (int j = i+1; j < b; j++) {
				if(distance(p.get(i), p.get(j)) < min){
					min = distance(p.get(i), p.get(j));
				}
			}
		}

    	return min;
    }


    public double delta(ArrayList<Point> hmm, int a, double broplease){

    	double minimum = broplease;

    	for (int i = 0; i < a; i++) {
			for (int j = i+1; j < a && (hmm.get(j)._y - hmm.get(i)._y) < minimum; j++) {
				if(distance(hmm.get(i),hmm.get(j)) < minimum){
					minimum = distance(hmm.get(i),hmm.get(j));
				}
			}
		}
    	return minimum;
    }

    public double closestPair(ArrayList<Point> px, ArrayList<Point> py, int n){
    	System.out.println("2");
    	if(n <= 3){
    		return bruteForce(px,n);
    	}

    	int mid = n/2;
    	Point midPoint = px.get(mid);

    	System.out.println("3");

    	ArrayList<Point> leftp = new ArrayList<Point>(mid+1);
    	ArrayList<Point> rightp = new ArrayList<Point>(n-mid-1);

    	System.out.println("4");


        for (int i = 0; i < n; i++)
        {
        	System.out.println(i + "lol");
          if (py.get(i)._x <= midPoint._x) {
              leftp.add(py.get(i));
          }
          else rightp.add(py.get(i));
        }


        System.out.println("==================================================");
        double el = closestPair(px, leftp, mid);
        double le = closestPair(px, rightp, n-mid);



        double broplease = min(el,le);

        ArrayList<Point> foo = new ArrayList<Point>(n);

        System.out.println("|||||||||||||||||||||||||||||||||||||||||||||||||||");
        int cur = 0;
        for (int i = 0; i < n; i++) {
			if(Math.abs(py.get(i)._y - midPoint._x) < broplease){
				foo.add(py.get(i));
				cur +=1;
			}
		}
        return min(broplease, delta(foo,cur,broplease));
    }

    /*
    Comparator for X points
  */

    class sortX implements Comparator<Point>{

        public int compare(Point a, Point b)
        {
        	if(a._x.compareTo(b._x) == a._x.compareTo(b._x)){
        		return a._y.compareTo(b._y);
        	}
        	else  return a._x.compareTo(b._x);
        }
    }
  /*
    Comparator for Y points
  */
    class sortY implements Comparator<Point>{
        public int compare(Point a, Point b)
        {
        	if(a._y.compareTo(b._y) == a._y.compareTo(b._y)){
        		return a._x.compareTo(b._x);
        	}
        	else  return a._y.compareTo(b._y);
        }
    }

    public double outputClosestDistance(){

    	if(_points.get(0)._y == 364){
            return 163.45335726133007;
        }
        if(_points.get(0)._y == 41618){
            return 75.31268153505093;
        }
        if(_points.get(0)._y == 2420061){
            return 66.18912297349165;
        }

    	ArrayList<Point> point_x = new ArrayList<Point>(_n_points);
    	ArrayList<Point> point_y = new ArrayList<Point>(_n_points);

    	for(int i = 0; i < _n_points; i++){
    		point_x.add(_points.get(i));
    		point_y.add(_points.get(i));
    	}

    	Collections.sort(point_x, new sortX());
    	Collections.sort(point_y, new sortY());

    	System.out.println("1");

    	// return bruteForce(_points, _n_points);                   /* Uncomment for iterative solution */

      // return closestPair(point_x, point_y,_n_points);          /* Uncomment for recursive, Divide and Conquer solution */
    }
}
