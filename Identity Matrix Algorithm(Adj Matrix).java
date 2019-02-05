package ub.cse.algo;

import java.util.Arrays;
import java.util.Vector;
import java.util.ArrayList;

public class Matrix {

    private ArrayList<Integer> in_vector;
     /**
     *
     * @param in_vector the vector used to multiply against the matrix
     */
    public Matrix(ArrayList<Integer> in_vector) {
        this.in_vector = in_vector;
    }

    public ArrayList<Integer> outputVector() {

    	for(int i = in_vector.size()-1; i >= 0; i-- ){
    		if(i == in_vector.size()-1){
    			continue;
    		}

        // uT multiplication
    			in_vector.set(i, in_vector.get(i+1)+in_vector.get(i));

    	}

        return in_vector;
    }
}
