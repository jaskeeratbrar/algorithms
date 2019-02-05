package ub.cse.algo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;

import javax.swing.text.html.HTMLDocument.Iterator;

public class Solution {
	  private int startNode;
	  private HashMap<Integer, ArrayList<Integer>> graph;
	  public Solution(int node, HashMap<Integer, ArrayList<Integer>> g){
	    startNode = node;
	    graph = g;
	  }

	  public int[] outputDistances(){
		  LinkedList<Integer> q = new LinkedList<Integer>();
		  q.add(startNode);
		  int[] output = new int[graph.size()];
		  Arrays.fill(output, -1);
		  output[startNode] =0;
		  while(!q.isEmpty()){
              int n = q.poll();
              for(int a :graph.get(n)){
                  if(output[a] == -1){
                      output[a] = output[n] + 1;
                      q.add(a);
                  }
              }
          }

	    return output;
	  }
}
