import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;

/*
http://community.topcoder.com/stat?c=problem_statement&pm=12399&rd=15489
*/
public class TheDeviceDiv2
{
	public String identify(String[] plates)
	{
		int numPlates = plates.length;
		if(numPlates < 3)
			return "NO";
		int numBits = plates[0].length();
		for( int i = 0; i < numBits; i++){
			int count[] = {0,0};
			for(int j = 0; j < numPlates; j++)
				count[ plates[j].charAt(i) - '0' ]++;
			if(! (count[0] > 0 && count[1] > 1 ) )
				return "NO";
		}
		return "YES";
	}

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
