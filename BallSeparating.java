import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
/*
http://community.topcoder.com/stat?c=problem_statement&pm=12398&rd=15488
*/

public class BallsSeparating
{
	int dp[][];
	int boxes [][];
	int INF = 1<<30, numColours;
	public int minOperations(int[] red, int[] green, int[] blue)
	{
		boxes = new int[][]{red, green, blue};
		int colours[] = {0,0,0};
		for(int i = 0; i < red.length; i++){
			for(int j = 0; j < 3; j++)
				if(boxes[j][i] > 0)
					colours[j] = 1;
		}
		numColours = colours[0] + colours[1] + colours[2];
		
		if( boxes[0].length < numColours)
			return -1;
		
		dp = new int[1<<3][boxes[0].length];
		for(int[] ar : dp)
			Arrays.fill(ar, INF);

		int state = 0;
		
		return find(state ,0);
		
	}
	//state stores the number of colors already assigned to some vertices
	//find() finds the minCost to move balls from this vertex to other by assigning a color to the ith vertex
	//if when the final is reached and we don't have the intended number of vertices assigned
	//the answer is INF else 0
	int find( int state, int i){
		if( i >= boxes[0].length){
				if( Integer.bitCount(state) == numColours)
					return 0;
				else
					return INF;
		}
		
		if(dp[state][i] != INF)
			return dp[state][i];
		
		int min = INF;
		for( int c = 0; c < 3; c++){
			//set current vertex to color i
			//cost is transferring other balls to other boxes assuming they exist
			int cost = boxes[(c+1) % 3][i] + boxes[(c+2) %3][i];
			min = Math.min(cost + find(state|(1<<c) ,  i+1), min);
		}
		return dp[state][i] = min;
	}
}
