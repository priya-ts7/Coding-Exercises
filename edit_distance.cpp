# Levenshtein Distance

/* convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
The minimum number of steps required to convert word1 to word2 with the given set of allowed operations is called edit distance.
e.g. Minimum edit distance between the words 'kitten' and 'sitting', is 3.
kitten → sitten (substitution of "s" for "k")
sitten → sittin (substitution of "i" for "e")
sittin → sitting (insertion of "g" at the end) */


int levenshteinDistance(string strWord1, string strWord2) {
   // Creating a 2-D table with string partials
   int n1 = strWord1.size();
   int n2 = strWord2.size();
   if (n1 == 0) {
       return n2;
   }
   if (n2 == 0) {
       return n1;
   }
   int na, nb, max;
   string *wa, *wb;
   if (n1 < n2) {
       na = n1;
       nb = n2;
       wa = &strWord1;
       wb = &strWord2;
       max = n2+1;
   } else {
       na = n2;
       nb = n1;
       wa = &strWord2;
       wb = &strWord1;
       max = n1+1;
   }
   int distance[2][na+1];
   int pos = 0;
   int previous = 1;
   for (int i = 0; i <= nb; ++i) {
       for (int j = 0; j <= na; ++j) {
           if (i == 0 && j == 0) {
               distance[pos][j] = 0;
           } else {
               int rep = max;
               int ins = max;
               int del = max;
               if (i > 0) {
                   if (j > 0) {
                       rep = distance[previous][j-1] + (wa->at(j-1) == wb->at(i-1) ? 0 : 1);
                   }
                   ins = distance[previous][j] + 1;
               }
               if (j > 0) {
                   del = distance[pos][j-1] + 1; 
               }
               distance[pos][j] = min(rep, min(ins, del));
           }
          // cout << pos << " " << j << " " << distance[pos][j] << endl;
       }
       if (pos == 0) {
           pos = 1;
           previous = 0;
       } else {
           pos = 0;
           previous = 1;
       }
   }
   return distance[previous][na];
}

