# Homework Solution

## Question 1
Both SJF and FIFO schedulers will yield the same response time and turnaround
time:

response time = (0 + 200 + 400) / 3 = 200

turnaround time = (200 + 400 + 600) / 3 = 400

## Question 2
Both SJF and FIFO schedulers will also yield the same response time and
turnaround time in this case. However, there is a subtle point to note, we
assume the shorter jobs arrive just a touch earlier than the longer ones.

response time = (0 + 100 + 300) / 3 = 133.3

turnaround time = (100 + 300 + 600) / 3 = 333.3

## Question 3
For question 1, with RR scheduling:

response time = (0 + 1 + 2) / 3 = 1

turnaround time = (598 + 599 + 600) / 3 = 199

For question 2, with RR scheduling:

response time = (0 + 1 + 2) / 3 = 1

turnaround time = (298 + 499 + 600) / 3 = 465.7

## Question 4
Workloads that satisfy the following: 

If arrival time (i) < arrival time(j) then job length (i) must be <= job length (j).

## Question 5
Assuming jobs arrive simultaneously:

Quantum time >= MIN(job lengths)

If not,

Quantum time >= MAX(jobs length)

## Question 6
If each job length is increased by x, and the number of jobs is equal to n,
then the response time will increase by:

$`(0 + (n-1) * x) / 2`$

## Question 7
In RR scheduling, assuming the number of jobs is equal to n, and the quantum
time is equal to q, response time is equal to

$`(n - 1) * q / n`$
