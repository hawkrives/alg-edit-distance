# alg-edit-distance

**C.1:** Implement the edit distance algorithm given in the book, and compute the edit distance between the two words `anagram` and `agnar`. Can you verify that the result is correct?
- `make edit-distance.out`
- `./edit-distance.out anagram agnar`


**C.2:** The edit distance between two words can be defined in many ways. Suppose that the cost of a substitution is half the cost of an insertion or deletion. Modify your algorithm to compute this revised edit distance, and test with the same word pair.
- `make edit-halved-distance.out`
- `./edit-halved-distance.out anagram agnar`


**C.3:** Revise your program once more to find the longest common subsequence between two words. In this case, substitution is not allowed per say, but insert and delete are. Check the video above for an example and more info on it!
- `make subsequence.out`
- `./subsequence.out anagram agnar`
