import unittest

# the algo that I have used is similar to Kadane Algorithm

def longest_substring(string):


	if(string is None):
		return 0

	L=len(string)

	### stores the final answer
	max_l=1

	## stores the length of the current substring
	curr_l=1

	#### store the previous recent index value of all the characters 
	visited_index=255*[-1] 
	i=0

	visited_index[ord(string[i])]=i
	i=i+1

	#traverse the whole string 
	while(i<L):
	    
	    k=ord(string[i])
	    prev_index=visited_index[k]

	    
	    #### if a new char is found that is not present in current substring 
	    if((prev_index==-1) or (prev_index<i-curr_l)): 
	       	curr_l=curr_l+1



	    ### if a char is found that occurred before
	    else:
	    	if(max_l<curr_l):
	        	max_l=curr_l
	        curr_l=i-prev_index

	    visited_index[k]=i 
	    i=i+1    


	if(max_l<curr_l):
	   	max_l=curr_l


	return max_l



class SimpleTest(unittest.TestCase):
    def test1(self):
    	self.assertEquals(longest_substring('srishti'),5)

    def test2(self):
    	self.assertEquals(longest_substring('abcabcbb'),3)

    def test3(self):
    	self.assertEquals(longest_substring('bbbbb'),1)

    def test4(self):
    	self.assertEquals(longest_substring(' @ 23ss'),5)
   
    def test5(self):
    	self.assertEquals(longest_substring(None),0)
   

if __name__ == '__main__':
   unittest.main()
