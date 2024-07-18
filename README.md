Servers (Servere)

The input data is read from a file, and the minimum and maximum values are identified for the current vector.
The optimal current for powering the servers is determined using binary search: the interval is defined by the minimum and maximum values in the current vector.
The condition limitRight - limitLeft > 0.1 ensures more efficient control over the number of iterations, leading to better solution accuracy.
The system's power is calculated for each half of the interval using the formula provided, and the search continues in the interval corresponding to the maximum of the two.
After finding the optimal interval, the supply current is calculated using the values at the interval boundaries.
As a final step, the system power is calculated using the optimal current value, and this coincides with the minimum of the individual powers.
Complexity: O(n + nlog x), where x is the difference between the minimum and maximum values of the current vector.

Coloring (Colorare)

The Pow function calculates exponentiation efficiently using modulo.
Two initial checks are made for the exponent value.
If the exponent value differs from 0 or 1, the while loop is executed.
The parity of the exponent is checked: if it is even, the base is squared, and the exponent is halved.
The efficiency of this function comes from this logic of halving the exponent.
The input data is read from a file.
A vector of k elements is used to store the number of possible colorings for each rectangle.
The number of colorings is calculated according to the rules provided and considering the type of the previous zone.
Finally, the product of the elements in the vector where the number of colorings is stored is calculated, modulo 1e9 + 7.
Complexity: O(k)

Compression (Compresie)

The values n, m, and the two vectors are read from a file.
The sum of the elements for each vector is calculated, and if the sums are different, it means that the two sequences cannot be compressed, and -1 is returned.
If the sums are equal, the sequences are attempted to be compressed.
A variable length is used to track the length of the new sequence.
A while loop iterates through the sequences using two variables to calculate the sums of the elements that can be compressed.
Initially, the current sums take the value of the first elements from the two vectors.
If the two sums are equal, it means a compressible sequence has been found, the positions in the two sequences and the length variable are incremented.
Otherwise, the current sums of the elements continue to be calculated, and the position indices are updated.
Complexity: O(n + m)

Encrypted (Criptat)

The input data is read from a file, and the occurrence of each character is counted using a vector of size 26.
Additionally, for each word, the character with the most occurrences is determined and stored in a vector of size n.
The word vector is traversed, and for each word, it is checked if the character with the most occurrences matches the character with the most total occurrences.
If so, the condition for the dominant character is checked, and the word is concatenated to the password.
After adding the words that contained the character with the most total occurrences, the vector is traversed again to check if there are any words that meet the condition nr. of occurrences > len / 2 to determine the maximum length.
In this traversal, it is checked that the current word is not already in the password.
Finally, the length of the password is displayed.
Complexity: O(n + n*len), where len is the maximum length of a word.

Offer (Oferta)

The number of products, the order of the desired lowest price, and the price vector are read from a file.
Three variables sum1, sum2, and sum3 are used to store the discounts:
sum1 will be the new sum if no discount is applied.
sum2 will hold the new sum if a discount is applied for 2 products.
sum3 will equal the new sum if a discount is applied for 3 products.
A vector dp is used to store the minimum updated sums for each product.
For the first two products, the minimum sum is calculated, and the values are placed in the vector.
For the remaining elements, from 2 to N, the three sum options are calculated, and the minimum of the three is placed in dp.
Finally, the last element in the vector is printed to the output file.
Complexity: O(n)

Couting (Numarare)
For the topological sorting function, I used the implementation from the published solution of lab 6, with slight modifications.

The number of nodes and edges of the graphs are read from the input file, and the two graphs are constructed. These two graphs are topologically sorted using the topologicalSort function. The dp vector is used to count the paths to each node, starting from node 1. The common paths are found as follows:

Iterate through each node of the first graph in topological order.
For each neighbor of the current node, check if it also exists in the second graph.
If the neighbor is found in the second graph, update the number of paths to that neighbor using the modulo operation.
At the end, the last element of the dp vector, which contains the number of common paths from the first to the last node, is written to the output file.
Complexity: O(m * (n + m))

Trains (Trenuri)
For the topological sorting function, I used the implementation from the published solution of lab 6, with slight modifications.

The source node, destination node, number of edges, and the edges themselves are read from the input file. As the edges are read, the graph is constructed. Additionally, a dictionary is declared to keep track of the in-degree of each node.
The topologicalSort function is called to sort the nodes of the graph, and then the distance to each node is initialized to the smallest int value.
The nodes sorted topologically are iterated through again to find the longest distance between the source node and the destination node: if the current node is accessible from the source, its neighbors are iterated through to check if the distance to the current neighbor can be increased, updating it if so.
Finally, the maximum distance is written to the output file.

Complexity: O(n + m)

Mandatory Paths (Drumuri obligatorii)
For this problem, I used the implementation of the Dijkstra function from the published solution of lab 8. Additionally, similar to the implementation in the solution, I used a structure to store the distance and parent vectors.

The number of nodes and edges are read from the input file, and as the edges and their associated costs are read, the graph is constructed. Subsequently, the three nodes x, y, and z are read.
Solving the problem involves using the Dijkstra function to find the minimum distances from node x and node y to all other nodes. This function returns a vector of n elements, where each element i represents the distance from node x/y to node i.
To find the minimum distances from all nodes to node z, a reversed graph is used because the Dijkstra function needs a source node, thus the edges were traversed from z to the other nodes. The target node is the one for which the sum of the distances from x, y, and z to it is minimal, and finding it required traversing the three distance vectors and summing the i-th elements from each vector.
The minimum sum is written to the output file.

Complexity: O((log n)(n + m))
