# Solution

## Question 2

Example 1 (Single Long-Running Job): `python3 mlfq.py -Q 10,10,10 -A 1,1,1 -l 0,100,0 -c`
Example 2 (Along Came A Short Job): `python3 mlfq.py -Q 10,10,10 -A 1,1,1 -l 0,200,0:100,20,0 -c`
Example 3 (What about I/O): `python3 mlfq.py -Q 10,10,10 -A 1,1,1 -l 0,200,0:50,10,1 -i 10 -c`

## Question 3

By using only a single queue.

## Question 4

`python3 mlfq.py -Q 10,10,10 -A 1,1,1 -S -l 0,175,0:75,100,9 -i 1 -c`

## Question 5

If it gets 5% of CPU time, that means $`5/100 = 10/B -> B = 200`$

## Question 6


