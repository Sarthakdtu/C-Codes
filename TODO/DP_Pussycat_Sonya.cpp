/*
Pussycat Sonya
Send Feedback
Pussycat Sonya has N blocks consisting of integers. You may assume that block is a one-dimensional array. She wants to put them all in the box of length M in such a way that they don't overlap. To do this she's allowed to remove any number of leftmost or rightmost elements in some blocks. It's also allowed to remove block completely or to not remove anything at all.
What is the maximal sum of elements in the box Sonya can get? Pay attention on that she's allowed to leave some free space in the box if she wants.
Input
The first line of input contains two integers N - the number of blocks and M - the length of the box.
The next N lines describe the blocks. The first number in i-th of these lines is leni - the length of the i-th block. Then leni integers follow - the elements of the i-th block.
Output
Print the maximal sum of elements in the box Sonya can get.
Constraints:
1 = N = 100

1 = M = 1000

-10^9 = element of block = 10^9

0 = sum overall leni = 10^5
Sample Input
3 4
3 2 3 5
2 7 -1
2 8 10
Sample Output
30
*/
