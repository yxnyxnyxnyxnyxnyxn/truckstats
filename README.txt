My approach: 
   Use map to store the truck count for each year.
My limitations:
   Map is sorted by the key value in order to get the final output I need to take extra step to put all the values into vector then sort the value, then check back through the map again which is super ineffiencent. 
Run time: O(N2)
Memory complexities: O(N) using hashmap
Testing: I dont really have enough time to test the edge case. Edge case will be 1. years that are out of range should return error message 
 2. final result doesnt have enough data for top-n or least-3
 3.  start year is larger then end year should return error message
 4. Empty input return error message 
 
If I have more time, I will try to cover all edge case and check input error. I will also use set to make final output easiler.
