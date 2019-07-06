/*
Monk went to a really nice place for celebrating birthday with his friends.
 He booked an awesome resort for hosting the birthday party. But the resort is very costly
  so he wants to wrap up the party as soon as possible.
Now, everything apart from dinner has been finished.
 There are N different types of delicious cakes for the dinner. 
 The number of cakes of ith type is C[i] and each of them weighs W[i] units. 
 Now, there are M friends of Monk present at the party. 
 Each friend has a certain limit L[i] units which denotes his/her maximum eating capacity.
  In other words, cakes having weight larger than L[i] units can't be eaten by ith friend.
   Note that eating capacity has no influence on total weight of cakes eaten by a friend.
Each friend takes one minute of time to eat a cake which is in his limits (i.e. if L[i]>=W[j] 
where i is the friend number and j is the cake's number).
 Please note that there is no sharing allowed between friends and each cake should be eaten by a single individual. 
 Also, Monk's friends have to eat full cake in one go. They can't eat a fractional part of any cake.
  And friends can eat cakes simultaneously as they need to wrap up the party as soon as possible.
   You need to tell whether it is possible for Monk's friends to eat all the cakes present at the birthday party.
 If yes, then print the minimum time required to eat all the cakes else print -1 otherwise.


Input Format
First line of the input contains test cases denoted by T

For each of the test cases, first line contains two space separated integers N and M denoting
 the number of different types of cakes present at the party and the number of Monk's friends 
 present at the party respectively.

The next line contains M space separated integers denoting the eating capacity of the Monk's friends.

In the third line N space separated integers will be given where the ith integer corresponds to 
the weight of ith type of cake ,i.e., W[i].

The fourth line contains N space separated integers where the ith integer corresponds to the 
number of cakes of ith type present, i.e., C[i]. 


Output Format
For each of the test cases, output the required answer in a separate line.


Constraints:
1=T=5
1=N,M=10^5
1=W[i],C[i],L[i]=10^8


SAMPLE INPUT
2
5 5
1 2 3 4 5
1 2 3 4 5
5 4 3 2 1
5 5
1 2 3 4 5
1 2 3 4 6
5 5 5 5 5

SAMPLE OUTPUT
3
-1
*/
#include<iostream>
using namespace std;

















