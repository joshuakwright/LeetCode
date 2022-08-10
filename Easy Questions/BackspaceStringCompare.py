# constant space version by iterating in reverse:

class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def F(s):
            skip = 0
            for x in reversed(s):
                if x == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield x
                    
        return all(x == y for x, y in itertools.izip_longest(F(s), F(t)))

# Initial solution with stack:

class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ss = []
        for c in s:
            if c != '#':
                ss.append(c)
            elif ss:
                ss.pop()
                
        st = []
        for c in t:
            if c != '#':
                st.append(c)
            elif st:
                st.pop()
        
        return ss == st