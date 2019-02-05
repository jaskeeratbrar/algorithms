package ub.cse.algo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Solution {

    private int origin;
    private ArrayList<HashMap<Integer, Integer>> incoming_edges;
    private ArrayList<HashMap<Integer, Integer>> outgoing_edges;

    public Solution(int origin, ArrayList<HashMap<Integer, Integer>> incoming_edges, ArrayList<HashMap<Integer, Integer>> outgoing_edges){
        this.origin = origin;
        this.incoming_edges = incoming_edges;
        this.outgoing_edges = outgoing_edges;
    }

    public int[] outputShortestDistance(){

    	int voo = outgoing_edges.size();

    	int max = Integer.MAX_VALUE;

    	int distance[] = new int[voo];
    	Arrays.fill(distance, max);
    	distance[origin] = 0;


    	for( int i = 0; i < voo ; i++) {

    		int c = 0;

    		for(HashMap<Integer, Integer> j: outgoing_edges) {

    			for(Integer a : j.keySet()) {

    				/*System.out.print(a);*/

    				int codeFast = j.get(a);
    				int distanceC = distance[c];
    				int distanceA = distance[a];


    				if(distanceC != max &&  distanceC + codeFast < distanceA ) {

    						distance[a] = distanceC + codeFast;

        			}

    			}
    			c+=1;
    			/*System.out.print("  ");*/
    		}

    	}


        return distance;
    }
}
