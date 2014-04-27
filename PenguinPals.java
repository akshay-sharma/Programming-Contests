import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

/*
http://community.topcoder.com/stat?c=problem_statement&pm=12355&rd=15486
*/


public class PenguinPals
{
	private String colors;
	private int dp[][];
	public int findMaximumMatching(String colors)
	{
		dp = new int[55][55];
		for(int i = 0; i < 55; i++)
			for(int j = 0; j < 55; j++)
				dp[i][j] = -1;
		this.colors = colors;
		return find(0,colors.length() - 1);
	}
	
	int find(int a , int b){
		if(a >= b || a<0 || b >=colors.length())	return 0;
		if(dp[a][b] != -1)
			return dp[a][b];
		char colora = colors.charAt(a);
		int max = -1;
		for(int i = a+1; i <=b; i++)
			if(colors.charAt(i) == colora){
				//join i and a
				int ans = 1 + find(a+1, i-1) + find(i+1, b);
				max = Math.max(max, ans);
			}
		if(max == -1){
			a++;//colora didn't match anyone in the set
			max = find(a,b);
		}
		return dp[a][b] = max;
	}
	

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
