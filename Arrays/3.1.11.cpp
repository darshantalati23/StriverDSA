/**
 * Question: Given a non-empty array of integers arr,
   every element appears twice except for one. Find that single one.

 * Brute: 
    Intuition:
    For every element present in the array, we will do a linear search and count the occurrence.
    If for any element, the occurrence is 1, we will return it.

    Approach:
    The steps are as follows:
    First, we will run a loop(say i) to select the elements of the array one by one.
    For every element arr[i], we will perform a linear search using another loop and count its occurrence.
    If for any element the occurrence is 1, we will return it.

    Time Complexity: O(N2), where N = size of the given array.
    Reason: For every element, we are performing a linear search to count its occurrence. 
    The linear search takes O(N) time complexity. And there are N elements in the array. 
    So, the total time complexity will be O(N2).

    Space Complexity: O(1) as we are not using any extra space.


 * Better 1: Array hashing:
    In order to hash using an array, we need to first find the maximum 
    element(say maxElement) to get the range of the hash array. The index 
    of the hash array will represent the elements of the given array and 
    the value stored in that index will be the number of occurrences. Now, 
    the size of the array must be maxElement+1 as we need to hash the maxElement itself.

    Approach:

    The steps are as follows:

    First, we will find the maximum element(say maxElement) to know the size of the 
    hash array. Then we will declare a hash array of size maxElement+1.
    Now, using another loop we will store the elements of the array along with their 
    frequency in the hash array. (i.e. hash[arr[i]]++)
    After that, using another loop we will iterate over the hash array, and try to 
    find the element for which the frequency is 1, and finally, we will return that 
    particular element.
    Note: While searching for the answer finally, we can either use a loop from 0 
    to n(i.e. Size of the array) or use a loop from 0 to maxElement. So, the time 
    complexity will change accordingly.

    Now, using array hashing it is difficult to hash the elements of the array if 
    it contains negative numbers or a very large number. So to avoid these problems, we 
    will be using the map data structure to hash the array elements.

    Time Complexity: O(N)+O(N)+O(N), where N = size of the array
    Reason: One O(N) is for finding the maximum, the second one is to hash 
    the elements and the third one is to search the single element in the array.

    Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.

 * Better 2:
    Approach:
    The steps are as follows:

    First, we will declare a map.
    Now, using a loop we will store the elements of the array along with their frequency 
    in the map data structure.
    Using another loop we will iterate over the map, and try to find the element 
    for which the frequency is 1, and finally, we will return that particular element.

    Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. 
    M = (N/2)+1. N = size of the array.
    Reason: We are inserting N elements in the map data structure and insertion 
    takes logM time(where M = size of the map). So this results in the first term O(N*logM). 
    The second term is to iterate the map and search the single element. 
    In Java, HashMap generally takes O(1) time complexity for insertion and search. 
    In that case, the time complexity will be O(N) + O(M).

    Note: The time complexity will be changed depending on which map data structure 
    we are using. If we use unordered_map in C++, the time complexity will be O(N) 
    for the best and average case instead of O(N*logM). But in the worst 
    case(which rarely happens), it will be nearly O(N2).

    Space Complexity: O(M) as we are using a map data structure.
    Here M = size of the map i.e. M = (N/2)+1.

 * Optimal:
    Intuition:
    Two important properties of XOR are the following:

    XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
    XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

    Here all the numbers except the single number appear twice and so will form a pair. 
    Now, if we perform XOR of all elements of the array, the XOR of each pair will result 
    in 0 according to the XOR property 1. 
    The result will be = 0 ^ (single number) = single number (according to property 2).

    So, if we perform the XOR of all the numbers of the array elements, 
    we will be left with a single number.
 */

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr) {
    int xorr=0;
    for (auto x : arr) {
        xorr=xorr^x;
    }
    cout << xorr << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) cin>>arr[i];

    solve(arr);
    
    return 0;
}