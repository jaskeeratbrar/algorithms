package ub.cse.algo;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;



public class Solution {

    private ArrayList<ArrayList<Integer>> adj_matrix;

    public Solution(ArrayList<ArrayList<Integer>> adj_matrix) {
        this.adj_matrix = adj_matrix;
    }


    /*
     * Output the node ids of the smallest weighted path using Prim's algorithm.
     *
     * Adjacency Matrix format
     */

    int minimumKeys(ArrayList<Integer> k, ArrayList<Boolean> m ){

        int minimum = Integer.MAX_VALUE;

        int m_index = -1;

        for(int i = 0; i < adj_matrix.size(); i++){
            if(m.get(i) == false && k.get(i) < minimum){
                minimum= k.get(i);
                m_index = i;
            }
        }
        return m_index;

    }

    public int[] outputEdges() {

        int size = adj_matrix.size();

        ArrayList<Integer> keys = new ArrayList<>();
        ArrayList<Integer> parent = new ArrayList<>();
        ArrayList<Boolean> m_tree = new ArrayList<>();

        keys.add(0);
        parent.add(-1);
        m_tree.add(false);

        for(int i = 1; i < size; i++){
            keys.add(Integer.MAX_VALUE);

            parent.add(null);

            m_tree.add(false);

        }

        for(int bro = 0; bro < size; bro++ ){

            int min = minimumKeys(keys,m_tree);

            m_tree.set(min, true);

            for(int z = 0; z < size; z++){

                if(!adj_matrix.get(min).get(z).equals(-1) && m_tree.get(z).equals(false) && adj_matrix.get(min).get(z) < keys.get(z)){
                    parent.set(z, min);
                    keys.set(z, adj_matrix.get(min).get(z));
                }

            }

        }

        int[] output = new int[parent.size()];

        for(int yo = 0; yo < parent.size(); yo++){
            output[yo] = parent.get(yo);
        }

        return output;

    }
}
