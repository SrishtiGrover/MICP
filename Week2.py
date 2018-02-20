
import unittest

def find_triplets(string, target_sum):

    ### this code works for any target sum value ####

    if(string is None or ''):
        return None

    
    size=len(string)
    arr=[0]*size

    ### converting input string into list of integer values ###
    arr=map(int, string.split())
    
    arr.sort()

    size=len(arr)

    if size<3:
        return None
    
    ### set containing required triplets ####
    triplets_set=[]

    ### pointer to traverse each variable ###
    k=0

    while(k<=(size-3)):

        #### left pointer: moves towards right ####
        l=k+1
            
        #### right pointer: moves towards left ###
        r=size-1
            
        while(l<r):
            
            if((arr[l]+arr[r]+arr[k])==target_sum):
                triplets_set.append((arr[k], arr[l], arr[r]))
                l=l+1
                r=r-1
            
            
            while(arr[l]+arr[r]+arr[k]>target_sum):
                r=r-1
                if (r-1<=k):
                    break
                
            while(arr[l]+arr[r]+arr[k]<target_sum):
                l=l+1
                if l>=size:
                    break
            
        ### to handle duplicate triplets ####
        while (arr[k]==arr[k+1]):
            k=k+1
            if k>=size-1:
                break
        
        k=k+1

    if triplets_set==[]:
        return None
    else:
        return triplets_set



class SimpleTest(unittest.TestCase):
    def test1(self):
    	self.assertEquals(find_triplets('0 0 0',0),[(0,0,0)])

    def test2(self):
    	self.assertEquals(find_triplets(None,0),None)

    def test3(self):
    	self.assertEquals(find_triplets('-1 0 1 2 -1 -4',0),[(-1,0,1)(-1,-1,2)])

    def test3(self):
    	self.assertEquals(find_triplets('-1 9',0),None)


if __name__ == '__main__':
    unittest.main()



