<H1>Hybrid LRU to increase the efficiency of page replacement</H1>
<hr>
<H3><B>Brief Introduction</B></H3>
<p>This Algorithm is a combination of General LRU(Last Recently Used) Algorithm and MFU (Most Frequently Used) Algorithm for Page Replacement.
It gives a better performance then compared to general LRU as it's Cache Miss is lower.</p><br>
<H3><B>Idea</B></H3>
<p> Idea is to first count the cost of the page using general LRU and then multipling it with the cost of that same page using MFU Algorithm, 
Then all the cost is saved into an array, later when all the fragments are full, then the algorithm has to find the page with minimum value. 
Later that page is selected to be replaced with the new page.</p><br>
<H3><B> Future Enhancement to the page replacement </B></H3>
<p> We can store that array into a database so that whenever the system is started the system will automatically predict and will load those pages 
with maximum cost into the frame. Thus in this way the system which is used for general perpose will loose initial cache miss and it will function much faster.</p>
<br>
Thank You!!

Tanmay Kumar
