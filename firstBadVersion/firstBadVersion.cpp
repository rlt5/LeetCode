// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binSearch(1,n);
    }
    int binSearch(int first, int last){
        if ( last == first)
            return first;
        int mid = first+(last-first)/2;
        if ( isBadVersion(mid) ){
            return binSearch(first,mid);
        } else {
            return binSearch(mid+1,last);
        }
    }
};