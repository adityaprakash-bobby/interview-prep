class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        rv = dict()
        cv = dict()
        
        for i in indices:
            if i[0] in rv:
                del rv[i[0]]
            else:
                rv[i[0]] = 1
                
            if i[1] in cv:
                del cv[i[1]]
            else:
                cv[i[1]] = 1
        
        r_ctr = len(rv.keys())
        c_ctr = len(cv.keys())
        
        return r_ctr*m + c_ctr*n - 2*c_ctr*r_ctr
        
