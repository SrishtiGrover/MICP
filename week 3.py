import unittest
split_string=[]

def dic_contains(word,dic):
    dic_size=len(dic)
    for i in range(0,dic_size):
        if (dic[i]== word ):
           return 1
    return 0



def word_break(dic,string):
    string_size=len(string)
    if (string_size == 0):
        return 1
        
    for i in range(0,string_size):
        if (dic_contains(string[0:i+1],dic) and word_break(dic,string[i+1:string_size])):
            split_string.append(string[0:i+1])
            return 1
    return 0

    

class SimpleTest(unittest.TestCase):
    def test1(self):
    	self.assertEquals(word_break(["mobile","samsung","sam","sung","man","mango","icecream","and","go","i","like","ice","cream"],'ilikeicecream'),1)

    def test2(self):
    	self.assertEquals(word_break(['pear', 'salmon', 'foot', 'prints', 'footprints', 'leave', 'you', 'sun', 'girl', 'enjoy'],'youenjoy'),1)

    def test3(self):
    	self.assertEquals(word_break(['pear', 'salmon', 'foot', 'prints', 'footprints', 'leave', 'you', 'sun', 'girl', 'enjoy'],'youleavefootprints'),1)

    def test4(self):
    	self.assertEquals(word_break(['pear', 'salmon', 'foot', 'prints', 'footprints', 'leave', 'you', 'sun', 'girl', 'enjoy'],'salmonenjoyapples'),0)
   
    

if __name__ == '__main__':
    unittest.main()


