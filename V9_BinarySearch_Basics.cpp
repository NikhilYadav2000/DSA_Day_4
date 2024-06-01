/*
Binary Search Introduction : 
https://www.naukri.com/code360/problems/binary-search_972?nps=true

Via Iteration
int search(vector<int> &nums, int target) {
    int n=nums.size(),l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]==target) return m;
        else if(nums[m]>target) h=m-1;
        else l=m+1; // the value is of m is smaller then the target so we have to search it amongst larger numbers so moving the low pointer
    }return -1;
}

Via Recurison
int f(vector<int> &nums,int t,int l,int h){
    if(l>h) return -1;
    int m=(l+h)/2;
    if(nums[m]==t) return m;
    else if(nums[m]>t) return f(nums,t,l,m-1);

    // else if(nums[m]<t) f(nums,t,m+1,h);
    return f(nums,t,m+1,h);
    // we can write the above code like this, bcoz if it doesnt go with the  nums[m]>t part then it will come here

}
int search(vector<int> &nums, int target) {
    int n=nums.size();
    f(nums,target,0,n-1);
}

// Lower Bound
int lowerBound(vector<int> arr, int n, int x) {
	int l=0,h=n-1,ans=n;
	while(l<=h){
		int m=(l+h)/2;
		if(arr[m]>=x){
			ans=m;
			h=m-1; // so we've got the lowerbound, but we need to find the closest element that is bigger then x
			// so we'll be searching in the left side amongst the smaller values then a[m] rn
		}else l=m+1; // we got a value smaller then x, so we are searching in the right half amongst the larger values then a[m] rn
	} return ans;
}
Using C++ STL
lb=lower_bound(arr,arr+n,x)-arr.begin();

If we are asked to find between 2nd index and 6th index then
lb=lower_bound(arr+2,arr+7,x)-arr.begin();
[2,7) so basically it will be [2,6]

// Upper Bound
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// Search where to insert, if present then return the index if not then find the index where it should exist
int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

// Floor
int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

// Ceil
int findCeil(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}

// First Occurence
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

// Last Occurence
int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}

// If the number exists then returning the value
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

// Returning the count
int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1); // +1 bcoz its 0 based indexing
}

// Search in ROtated Sorted Array I
class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0,h=a.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==target) return m;
            else if(a[l]<=a[m]){ // if left is sorted
                if(a[l]<=target && target<=a[m]) h=m-1; // bring h behind the curr index of m as m!=k and search in this half
                else l=m+1; // though this half was sorted but we dont have the answer here so moving to the other half even though it is unsorted
            }
            else{ // right side is sorted
                if(a[m]<=target && target<=a[h]) l=m+1;
                else h=m-1;
            }
        }return -1;  // if not found
    }
};

*/